```
/* Exercise 1: OSI layers. Topics: arrays, loops, scanf.
   Build/run: gcc -Wall -o ex1 ex1_osi_layers.c && ./ex1 */
#include <stdio.h>

int main(void) {
    const char *layers[7] = {
        "Physical    - sends raw bits as signals",
        "Data Link   - frames, MAC addresses, error detection",
        "Network     - IP addressing and routing",
        "Transport   - TCP/UDP, end-to-end delivery",
        "Session     - opens/closes/manages sessions",
        "Presentation- encoding, encryption, compression",
        "Application - protocols apps use (HTTP, DNS)"
    };

    printf("OSI model (Layer 1 at the bottom):\n");
    for (int i = 0; i < 7; i++)
        printf("Layer %d: %s\n", i + 1, layers[i]);

    int n;
    printf("\nEnter a layer number (1-7): ");
    if (scanf("%d", &n) == 1 && n >= 1 && n <= 7)
        printf("Layer %d -> %s\n", n, layers[n - 1]);
    else
        printf("Invalid layer number.\n");

    /* TODO (your turn): print the layers from 7 down to 1. */
    return 0;
}
 char)value);
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

