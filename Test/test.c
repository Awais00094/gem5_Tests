#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

int main() {

    printf("RISC-V Test Program:"  );

    #ifdef __riscv
        printf("Running on Beagle board RISC-V architecture.\n");
    #else
        printf("Not running on RISC-V architecture.\n");
    #endif

    
    return 0;
}
