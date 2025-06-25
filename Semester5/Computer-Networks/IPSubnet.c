#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to determine the class of the IP address
char get_ip_class(int first_octet) {
    if (first_octet >= 1 && first_octet <= 127)
        return 'A';
    else if (first_octet >= 128 && first_octet <= 191)
        return 'B';
    else if (first_octet >= 192 && first_octet <= 223)
        return 'C';
    else if (first_octet >= 224 && first_octet <= 239)
        return 'D';
    else
        return 'E';
}

// Function to calculate subnet mask
void get_subnet_mask(char ip_class, int subnet_mask[4]) {
    if (ip_class == 'A') {
        subnet_mask[0] = 255; subnet_mask[1] = 0; subnet_mask[2] = 0; subnet_mask[3] = 0;
    } else if (ip_class == 'B') {
        subnet_mask[0] = 255; subnet_mask[1] = 255; subnet_mask[2] = 0; subnet_mask[3] = 0;
    } else if (ip_class == 'C') {
        subnet_mask[0] = 255; subnet_mask[1] = 255; subnet_mask[2] = 255; subnet_mask[3] = 0;
    } else {
        subnet_mask[0] = 0; subnet_mask[1] = 0; subnet_mask[2] = 0; subnet_mask[3] = 0;
    }
}

// Function to calculate subnet address
void get_subnet_address(int ip[4], int subnet_mask[4], int subnet_address[4]) {
    for (int i = 0; i < 4; i++) {
        subnet_address[i] = ip[i] & subnet_mask[i];
    }
}

int main() {
    char ip_str[16];
    int ip[4], subnet_mask[4], subnet_address[4];

    printf("Enter an IP address (e.g., 192.168.1.1): ");
    scanf("%s", ip_str);

    // Parse the IP address
    sscanf(ip_str, "%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    // Determine the class
    char ip_class = get_ip_class(ip[0]);
    printf("IP Class: %c\n", ip_class);

    // Calculate subnet mask
    get_subnet_mask(ip_class, subnet_mask);
    printf("Subnet Mask: %d.%d.%d.%d\n", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);

    // Calculate subnet address
    get_subnet_address(ip, subnet_mask, subnet_address);
    printf("Subnet Address: %d.%d.%d.%d\n", subnet_address[0], subnet_address[1], subnet_address[2], subnet_address[3]);

    return 0;
}