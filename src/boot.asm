[bits 16]            ; Tells NASM assembly source is 16 bit
[org 0x7C00]         ; Origin, tells where the code will be in memory

start:
    cli              ; Clear interrupts
    mov ax, 0x9000   ; Set up the stack
    mov ss, ax
    mov sp, 0xFFFF
    mov ax, 0x9000   ; Set data segment
    mov ds, ax
    mov es, ax

    call main        ; Call the main function written in C

    hlt              ; Halt the CPU

times 510-($-$$) db 0
dw 0xAA55           ; Boot signature at the end of the bootloader
