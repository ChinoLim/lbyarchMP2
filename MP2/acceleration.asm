section .text
    global acceleration

; Constants stored in .text to avoid .data linkage issues
const_1000: dq 1000.0
const_3600: dq 3600.0

acceleration:
    ; Inputs:
    ;   xmm0 = Vi (km/h)
    ;   xmm1 = Vf (km/h)
    ;   xmm2 = T  (s)

    ; Load constants
    movsd xmm3, [rel const_1000]
    movsd xmm4, [rel const_3600]

    ; Convert Vi from km/h to m/s: Vi * 1000 / 3600
    mulsd xmm0, xmm3           ; xmm0 = Vi * 1000
    divsd xmm0, xmm4           ; xmm0 = Vi_mps

    ; Convert Vf from km/h to m/s: Vf * 1000 / 3600
    movsd xmm5, xmm1           ; copy Vf to xmm5
    mulsd xmm5, xmm3           ; xmm5 = Vf * 1000
    divsd xmm5, xmm4           ; xmm5 = Vf_mps

    ; Compute (Vf - Vi) / T
    subsd xmm5, xmm0           ; xmm5 = Vf_mps - Vi_mps
    divsd xmm5, xmm2           ; xmm5 = acceleration

    ; Convert double to int (round to nearest)
    cvtsd2si eax, xmm5         ; return int result in eax

    ret
