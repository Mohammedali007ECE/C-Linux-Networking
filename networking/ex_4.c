/* Exercise 4: IPv4 subnet calculator. Topics: bit shifts, masks, uint32_t.
   Build/run: gcc -Wall -o ex4 ex4_ip_subnet.c && ./ex4 */
#include <stdio.h>
#include <stdint.h>

static void print_ip(const char *label, uint32_t ip) {
    printf("%s %u.%u.%u.%u\n", label,
           (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
}

int main(void) {
    unsigned a, b, c, d, prefix;
    printf("Enter IP (e.g. 192.168.1.77): ");
    if (scanf("%u.%u.%u.%u", &a, &b, &c, &d) != 4 || a > 255 || b > 255 || c > 255 || d > 255) {
        printf("Invalid IP.\n");
        return 1;
    }
    printf("Enter prefix length (0-32, e.g. 24): ");
    if (scanf("%u", &prefix) != 1 || prefix > 32) {
        printf("Invalid prefix.\n");
        return 1;
    }

    uint32_t ip   = (a << 24) | (b << 16) | (c << 8) | d;
    uint32_t mask = (prefix == 0) ? 0 : 0xFFFFFFFFu << (32 - prefix);
    uint32_t net  = ip & mask;           /* AND keeps the network part */
    uint32_t bcast = net | ~mask;        /* host bits all 1 */

    print_ip("IP address:       ", ip);
    print_ip("Subnet mask:      ", mask);
    print_ip("Network address:  ", net);
    print_ip("Broadcast address:", bcast);
    if (prefix <= 30)
        printf("Usable hosts:      %u\n", (1u << (32 - prefix)) - 2);
    else
        printf("Usable hosts:      special case (/31 or /32)\n");

    /* TODO (your turn): print whether the IP is private (10.x, 172.16-31.x, 192.168.x). */
    return 0;
}