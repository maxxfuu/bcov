#include "conversion.h"

/* Helper Functions */
static void reverseString(char *input) {
    int length = sizeof(input);
    for (int i = 0; i < length; i++) {
        char temp = input[i]; 
        input[i] = input[length - i - 1];
        input[length - i - 1] = temp; 
    }
}

/* Main Logic */
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
    size_t length = strlen(input); 
    char *result = malloc(4 * length + 1);
    
    /* malloc automatically changes the pointer to the correct type */
    const char *hexToBinTable[] = {
        "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"
    };
    
    char *ptr = result;

    for (int i = 0; i < length; i++) {
        char c = input[i];
        int index; 

        if (c >= '0' && c <= '9') {
            index = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            index = c - 'A' + 10;
        } else if (c >= 'a' && c <= 'f') {
            index = c - 'a' + 10; 
        } else {
            printf("Error: Input invalid, unable to convert information");
            free(result);
            return NULL; 
        }
        strcpy(ptr, hexToBinTable[index]);
        ptr += 4; 
    }
    *ptr = '\0'; /* NULL Terminate the string */

    return result; 
}

char *decToHex(const char* input) {
    errno = 0;
    char *endptr;

    unsigned long value = strtoul(input, &endptr, 10);
    char *result = malloc(20);
    snprintf(result, 20, "%lx", value);

    return result;
}

char *decToBin(const char* input) {
    char *endptr;
    unsigned long value = strtoul(input, &endptr, 10);
    char *result = malloc(65); 
    
    if (value == 0) {
        strcpy(result, "0");
        return result;
    }
    
    int index = 0; 
    while (value > 0) {
        result[index++] = (value % 2) + '0';
        value /= 2;
    }
    result[index] = '\0';
    reverseString(result);

    return result;
}

char *binToHex(const char *input) {
    char *endptr; 
    unsigned long value = strtoul(input, &endptr, 2); 
    
    if (*endptr != '\0') {
        return NULL;
    }
    
    char *result = malloc(17); 
    if (!result) {
        return NULL;
    }

    snprintf(result, 17, "%lx", value); 
    return result; 
}

char *binToDec(const char *input) {
    char *endptr; 
    unsigned long value = strtoul(input, &endptr, 2);
    
    char *result = malloc(20);

    snprintf(result, 20, "%lu", value); 
    return result;
}

