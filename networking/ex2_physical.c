#include <stdio.h>

/* Print one byte as 8 bits, e.g. 65 -> 01000001 */
void print_bits(unsigned char b) {
    for (int i = 7; i >= 0; i--)
        printf("%d", (b >> i) & 1);
}

int main(void) {
    unsigned int value;
    printf("Enter a number 0-255: ");
    if (scanf("%u", &value) != 1 || value > 255) {
        printf("Invalid input.\n");
        return 1;
    }
    printf("%u in binary (what the wire carries as signals): ", value);
    print_bits((unsigned char)value);
    printf("\n");

    double size_mb, bw_mbps;
    printf("\nFile size in MB: ");
    scanf("%lf", &size_mb);
    printf("Link speed in Mbps (e.g. 100): ");
    scanf("%lf", &bw_mbps);

    if (bw_mbps <= 0) { printf("Speed must be > 0.\n"); return 1; }
    double bits_mega = size_mb * 8.0;          /* 1 byte = 8 bits */
    printf("Transfer time = %.2f megabits / %.2f Mbps = %.2f seconds\n",
           bits_mega, bw_mbps, bits_mega / bw_mbps);

    /* TODO (your turn): print the number in binary for 0..15 using a loop. */
    return 0;
}

