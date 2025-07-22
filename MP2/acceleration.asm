section .text
    global acceleration

const_1000: dq 1000.0
const_3600: dq 3600.0

; void acceleration(double* input, int* output, int rows)
; Windows x64: RCX, RDX, R8, R9

acceleration:
    ; rcx = input pointer (double*)
    ; rdx = output pointer (int*)
    ; r8  = number of rows

    push rbp
    mov rbp, rsp
    push rbx

    xor r9, r9           ; r9 = i = 0 (loop counter)
    movsd xmm6, [rel const_1000]
    movsd xmm7, [rel const_3600]

.loop:
    cmp r9, r8
    jge .done

    mov rax, r9
    imul rax, 24         ; offset = row * 24 (3 doubles * 8)

    ; Load Vi, Vf, T
    movsd xmm0, [rcx + rax]        ; Vi
    movsd xmm1, [rcx + rax + 8]    ; Vf
    movsd xmm2, [rcx + rax + 16]   ; T

    ; Convert Vi from km/h to m/s
    movsd xmm3, xmm0
    mulsd xmm3, xmm6
    divsd xmm3, xmm7

    ; Convert Vf from km/h to m/s
    movsd xmm4, xmm1
    mulsd xmm4, xmm6
    divsd xmm4, xmm7

    ; Accel = (Vf - Vi) / T
    subsd xmm4, xmm3
    divsd xmm4, xmm2

    ; Convert to int and store
    cvtsd2si eax, xmm4
    mov [rdx + r9*4], eax

    inc r9
    jmp .loop

.done:
    pop rbx
    pop rbp
    ret
