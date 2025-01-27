#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "networkAddress.h" // Include the network address header

// Function to log suspicious activity
void logSuspiciousActivity(const char *ip) {
    // Implement logging mechanism (e.g., write to a file or console)
    printf("Suspicious activity detected from IP: %s\n", ip);
}

// Function to check if an IP is known to be malicious
int isMaliciousIP(unsigned int ip) {
    // Example of known malicious IPs (in integer format)
    unsigned int knownMaliciousIPs[] = {
        ipToInt("192.168.1.100"), // Example malicious IP
        ipToInt("10.0.0.5")       // Another example
    };
    int numMaliciousIPs = sizeof(knownMaliciousIPs) / sizeof(knownMaliciousIPs[0]);

    for (int i = 0; i < numMaliciousIPs; i++) {
        if (ip == knownMaliciousIPs[i]) {
            return 1; // Malicious IP found
        }
    }
    return 0; // Not a malicious IP
}

// Main function for the NIDS
int main() {
    char ip[16];
    
    printf("Enter IP address to analyze: ");
    scanf("%15s", ip);
    
    unsigned int ipInt = ipToInt(ip);
    
    // Check for malicious IP
    if (isMaliciousIP(ipInt)) {
        logSuspiciousActivity(ip);
    } else {
        printf("IP address %s is safe.\n", ip);
    }

    return 0;
}
