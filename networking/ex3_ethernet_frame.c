/* Exercise 3: Ethernet frame + MAC address. Topics: structs, arrays, hex printing.
   Build/run: gcc -Wall -o ex3 ex3_ethernet_frame.c && ./ex3 */
#include <stdio.h>
#include <stdint.h>

/* Header fields in order on the wire (preamble/SFD/FCS handled by hardware). */
struct EthHeader {
    uint8_t  dest_mac[6];
    uint8_t  src_mac[6];
    uint16_t ether_type;      /* 0x0800 = IPv4, 0x0806 = ARP */
};

void print_mac(const char *label, const uint8_t mac[6]) {
    printf("%s %02X:%02X:%02X:%02X:%02X:%02X\n", label,
           mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
}

int main(void) {
    struct EthHeader h = {
        .dest_mac   = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},  /* broadcast */
        .src_mac    = {0x00, 0x1A, 0x2B, 0x3C, 0x4D, 0x5E},
        .ether_type = 0x0800
    };

    print_mac("Destination MAC:", h.dest_mac);
    print_mac("Source MAC:     ", h.src_mac);
    printf("EtherType:       0x%04X (%s)\n", h.ether_type,
           h.ether_type == 0x0800 ? "IPv4" :
           h.ether_type == 0x0806 ? "ARP"  : "other");

    int payload;
    printf("\nPayload length in bytes (0-1500): ");
    if (scanf("%d", &payload) != 1 || payload < 0 || payload > 1500) {
        printf("Invalid length.\n");
        return 1;
    }
    int padded = payload < 46 ? 46 : payload;      /* minimum payload is 46 */
    int frame  = 6 + 6 + 2 + padded + 4;           /* dest+src+type+payload+FCS */
    printf("Payload after padding: %d bytes\n", padded);
    printf("Frame size (without preamble/SFD): %d bytes\n", frame);
    printf("On the wire (with 7-byte preamble + 1-byte SFD): %d bytes\n", frame + 8);

    /* TODO (your turn): check if the first byte's lowest bit is 1 -> multicast/broadcast. */
    return 0;
}