#include <stdint.h>
#include <stdio.h>

// Constants for cache levels
#define kDCacheL1 0
#define kDCacheL2 2

// Function to flush cache lines
void flush_cache_lines(void *alignedVirtAddr, void *endAddr, uint32_t lineSize) {
    // Loop until the end address is reached
    while (alignedVirtAddr < endAddr) {
        // Flushing L1 cache
        asm volatile (
            "mcr   p15, 2, %0,  c0,  c0,  0\n"  // Select cache level
            "isb\n"                              // Instruction Synchronization Barrier
            "mcr   p15, 0, %1,  c7, c14,  1\n"  // Clean and invalidate cache
            "dsb\n"                              // Data Synchronization Barrier
            :
            : "r" (kDCacheL1), "r" (alignedVirtAddr)
        );

        // Flushing L2 cache
        asm volatile (
            "mcr   p15, 2, %0,  c0,  c0,  0\n"  // Select cache level
            "isb\n"                              // Instruction Synchronization Barrier
            "mcr   p15, 0, %1,  c7, c14,  1\n"  // Clean and invalidate cache
            "dsb\n"                              // Data Synchronization Barrier
            :
            : "r" (kDCacheL2), "r" (alignedVirtAddr)
        );

        // Move to the next cache line
        alignedVirtAddr += lineSize;
    }
}


int main() {
    
    printf("tesint the arm...")	;
    // Example variables
    void *alignedVirtAddr = (void *)0x1000;
    void *endAddr = (void *)0x2000;
    uint32_t lineSize = 32;

    // Flush cache lines
    flush_cache_lines(alignedVirtAddr, endAddr, lineSize);

    // Print a message indicating that cache lines have been flushed
    printf("Cache lines flushed.\n");

    return 0;
}

