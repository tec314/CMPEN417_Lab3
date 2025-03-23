#include <xil_io.h>   // Include Xilinx I/O functions
#include <stdio.h>    // Include standard I/O functions

#define AR_ADDR 0x43C00008 // Address for 'ar'
#define AI_ADDR 0x43C0000C // Address for 'ai'
#define BR_ADDR 0x43C00010 // Address for 'br'
#define BI_ADDR 0x43C00014 // Address for 'bi'
#define PR_ADDR 0x43C00000 // Address for 'pr' (output from multiplier)
#define PI_ADDR 0x43C00004 // Address for 'pi' (output from multiplier)

int main() {
    short ar, ai, br, bi;  // Declare inputs as short data type (16-bit signed integer)
    int pr, pi;            // Declare outputs as int data type (32-bit signed integer)

    while (1) {
        // Ask for input values
        printf("\nEnter value for ar (short, 16-bit): ");
        scanf("%hd", &ar);  // Input ar (16-bit signed short)
        printf("%hd ", ar);

        printf("\nEnter value for ai (short, 16-bit): ");
        scanf("%hd", &ai);  // Input ai (16-bit signed short)
        printf("%hd ", ai);

        printf("\nEnter value for br (short, 16-bit): ");
        scanf("%hd", &br);  // Input br (16-bit signed short)
        printf("%hd ", br);

        printf("\nEnter value for bi (short, 16-bit): ");
        scanf("%hd", &bi);  // Input bi (16-bit signed short)
        printf("%hd ", bi);

        // Write the input values to memory at the specified addresses
        Xil_Out32(AR_ADDR, ar);  // Write ar to address 0x43C0_0008
        Xil_Out32(AI_ADDR, ai);  // Write ai to address 0x43C0_000C
        Xil_Out32(BR_ADDR, br);  // Write br to address 0x43C0_0010
        Xil_Out32(BI_ADDR, bi);  // Write bi to address 0x43C0_0014

        // Read the output values from the multiplier
        pr = Xil_In32(PR_ADDR);  // Read pr from address 0x43C0_0000
        pi = Xil_In32(PI_ADDR);  // Read pi from address 0x43C0_0004

        // Print the output values
        printf("\nMultiplier output pr = %d", pr);  // Output real part
        printf("\nMultiplier output pi = %d", pi);  // Output imaginary part
    }

    return 0;
}
