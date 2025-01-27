#include "conversion.h"

char *hexToBin(const char *input) {

    unsigned long value = strtoul(input, NULL, 16); 
    
    /* Max 64bit for unsinged long is 20 characters */
    char *result = malloc(20); 

    if (!result) {
        return NULL;
    }
    
    //snprintf(result, 20, "%lu", input); 

    return result;
}
