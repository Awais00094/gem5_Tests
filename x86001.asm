#x86_32 asmably
.global _start
.intel_syntax

.section .text

_start:
        # writing hello world
        mov %eax, 4
        mov %ebx, 1
        lea %ecx,[msg]
        mov %edx, 26
        int 0x80

        # adding numbers

        # exit syscall
        mov %eax, 1
        mov %ebx, 65
        sub %ebx, 10
        add %ebx, %eax
        int 0x80


.section .data
        msg:
        .ascii "now adding two numbers..\n"
        

