#include <stdio.h>
int main() {
    __asm__("movl %edx, %eax\n\t"
        "addl $2, %eax\n\t");

        
    printf("Hello, from main\n");
    return 0;
}
