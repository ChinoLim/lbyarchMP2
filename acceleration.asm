section .text
global compute_accelerations

compute_accelerations:
    ; rdi = pointer to input matrix (double*)
    ; rsi = pointer to output array (int*)
    ; rdx = number of rows

    push rbx
    xor rcx, rcx             ; loop counter = 0

.loop:
    cmp rcx, rdx
    jge .done

    ; Load Vi, Vf, T
    movsd xmm0, [rdi + rcx*24]       ; xmm0 = Vi
    movsd xmm1, [rdi + rcx*24 + 8]   ; xmm1 = Vf
    movsd xmm2, [rdi + rcx*24 + 16]  ; xmm2 = T

    ; Convert Vi and Vf from KM/H to M/S ( * 1000 / 3600 = * 0.2777777778)
    movsd xmm3, xmm1         ; xmm3 = Vf
    movsd xmm4, xmm0         ; xmm4 = Vi

    movsd xmm5, qword [rel kmh_to_ms] ; xmm5 = 0.2777777778
    mulsd xmm3, xmm5         ; xmm3 = Vf in m/s
    mulsd xmm4, xmm5         ; xmm4 = Vi in m/s

    ; Compute (Vf - Vi) / T
    subsd xmm3, xmm4         ; xmm3 = Vf - Vi
    divsd xmm3, xmm2         ; xmm3 = (Vf - Vi) / T

    ; Round to nearest int
    roundsd xmm3, xmm3, 1    ; round to nearest
    cvttsd2si eax, xmm3      ; convert to int

    ; Store result
    mov [rsi + rcx*4], eax

    inc rcx
    jmp .loop

.done:
    pop rbx
    ret

section .rodata
kmh_to_ms: dq 0.2777777777777778
