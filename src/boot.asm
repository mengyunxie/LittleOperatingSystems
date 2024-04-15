[bits 16]
[org 0x7C00]

start:
    mov ax, 0x9000
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    call KERNEL_OFFSET

    ; Infinite loop
    jmp $

KERNEL_OFFSET:
    ; Kernel loading code goes here

times 510-($-$$) db 0
dw 0xAA55
