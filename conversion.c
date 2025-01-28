#include "conversion.h"

/* Need to fix function logic */

char *hexToDec(const char *input) {
    errno = 0;
    char *endptr;

    unsigned long result = strtoul(input, &endptr, 16);

    if (errno != 0 || *endptr != '\0') {
        printf("Error: Invalid Hexadecimal or out of range\n"); 
        return 0;
    }
    
    /* Calculate digits needed for decimal representation */
    unsigned long temp = result; 
    int numOfDigits = (temp == 0) ? 1 : 0;

    while (temp > 0) {
        temp /= 10; 
        numOfDigits++;
    }

    /* Allocate Memory for Fixed-Sized Array */
    char *decStr = malloc(numOfDigits + 1);
    if (!numOfDigits) {
        printf("Memory Allocation Error\n");
    }
    
    snprintf(decStr, numOfDigits + 1, "%lu", result); 

    return decStr;
}

char *hexToBin(const char *input) {
    char *result = malloc(4 * strlen(input) + 1); 
    
    /* malloc automatically changes the pointer to the correct type */
    const char *hexToBinTable[] = {
        "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
        "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"
    }; 
    
    for (int i = 0; i < strlen(input); i++) {
        (result)++; 
    }

    result[-1] = '\0'; 

    return result; 
} 

