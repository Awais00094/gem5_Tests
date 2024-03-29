# power of two
INCLUDE Irvine32.inc

.data
    x SDWORD 1

.code 
main PROC
    mov  ecx, 9
    again:
    mov eax, ecx
    call WriteInt
    call Crlf

    loop again
    exit
main ENDP
end main