section .data
    const_1000: dq 1000.0
    const_3600: dq 3600.0
    
section .text
    bits 64
    default rel
    global acceleration
    extern printf, scanf

acceleration:
    push rbp
    mov rbp, rsp
    push rbx

    xor r9, r9
    movsd xmm6, [rel const_1000]
    movsd xmm7, [rel const_3600]

.loop:
    cmp r9, r8
    jge .done

    mov rax, r9
    imul rax, 24

    ; Load Vi, Vf, T
    movsd xmm0, [rcx + rax]
    movsd xmm1, [rcx + rax + 8]
    movsd xmm2, [rcx + rax + 16]

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
