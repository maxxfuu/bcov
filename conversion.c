#include "conversion.h"

char *hexToBin(const char *input) {
    unsigned long value = strtoul(input, NULL, 16); 
    char *result = malloc(20);      /* Max 64bit for unsinged long is 20 characters */

    if (!result) {
        return NULL;
    }
    //snprintf(result, 20, "%lu", input); 
    return result;
}

char *hexToDec(const char *input) {
    char *endptr; 
    unsigned long value = strtoul(input, endptr, 10);

    if (endptr != '\0') {
        printf("Conversion Stopped at %c\n", *endptr); 
    }

    

    return result; 
}
