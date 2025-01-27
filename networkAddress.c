#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int ipToInt(const char *ip) {
    unsigned int result = 0;
    int octet;
    char *ipCopy = strdup(ip);
    char *token = strtok(ipCopy, ".");

    while (token != NULL) {
        octet = atoi(token);
        result = (result << 8) | (octet & 0xFF);
        token = strtok(NULL, ".");
    }

    free(ipCopy);
    return result;
}

void intToIp(unsigned int ip, char *buffer) {
    sprintf(buffer, "%u.%u.%u.%u", (ip >> 24) & 0xFF, (ip >> 16) & 0xFF, (ip >> 8) & 0xFF, ip & 0xFF);
}
