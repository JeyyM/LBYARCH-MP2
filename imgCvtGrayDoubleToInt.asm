; Compile and run command:
; nasm -f win64 imgCvtGrayDoubleToInt.asm; gcc -c main.c -o main.obj -m64; gcc main.obj imgCvtGrayDoubleToInt.obj -o main.exe -m64; .\main.exe

section .data
    mult255: dq 255.0 ; to multiply the float
    half: dq 0.5      ; for rounding

section .text
bits 64
Default rel
global imgCvtGrayDoubleToInt

; Parameters:
; RCX = height
; RDX = width
; R8  = floatPixels pointer
; R9  = intPixels pointer

imgCvtGrayDoubleToInt:
    push rbp
    mov rbp, rsp
    
    ; rax will contain the total number of pixels
    mov rax, rcx
    imul rax, rdx
    
    ; Setup pointers
    mov rsi, r8 ; rsi to store the float source
    mov rdi, r9 ; rdi to store the destination
    
    ; load the multiplier
    movsd xmm1, qword [mult255]
    
    ; pixel counter
    mov rcx, 0
    
.loop:
    ; Pixel for loop
    cmp rcx, rax
    jge .end
    
    movsd xmm0, qword [rsi + rcx*8] ; 8 bytes per double

    ; Multiply by 255.0
    mulsd xmm0, xmm1

    cvtsd2si rbx, xmm0

    ; Store as byte size
    mov byte [rdi + rcx], bl
    inc rcx
    jmp .loop
    
.end:
    pop rbp
    ret
