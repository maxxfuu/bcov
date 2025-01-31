#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "conversion.h"

#define BUFFER 1000

/* enum to create integral constants for readability */
typedef enum {
    INPUT_BINARY,
    INPUT_DECIMAL,
    INPUT_HEXA
} InputType;

typedef enum {
    OUTPUT_BINARY,
    OUTPUT_DECIMAL,
    OUTPUT_HEXA
} OutputType;

int main(int argc, char **argv) {

    int choice;
    char *result = NULL;

    char input[BUFFER];
    char cleanedString[BUFFER];

    if (argc != 4) {
        fprintf(stderr, "\nERROR\n\n");
        fprintf(stderr, "Usage:\n");
        fprintf(stderr, "  %s -b|-d|-x -b|-d|-x <Input Value>\n\n", argv[0]);
        fprintf(stderr, "Examples:\n");
        fprintf(stderr, "  %s -b -d 010010   (binary to decimal)\n", argv[0]);
        fprintf(stderr, "  %s -x -b FF       (hex FF to binary)\n", argv[0]);
        return 1;
    }
    
    /* Validate input flag */
    InputType inputType; 
    if (strcmp(argv[1], "-b") == 0) {
        inputType = INPUT_BINARY;
    } else if (strcmp(argv[1], "-d") == 0) {
        inputType = INPUT_DECIMAL;
    } else if (strcmp(argv[1], "-h") == 0) {
        inputType = INPUT_HEXA;
    } else {
        printf("Unknow input flag: %s\n", argv[1]);
        return 1;
    }
    
    /* Validate output flag */
    OutputType outputType;
    if (strcmp(argv[2], "-b") == 0) {
        outputType = OUTPUT_BINARY;
    } else if (strcmp(argv[2], "-d") == 0) {
        outputType = OUTPUT_DECIMAL;
    } else if (strcmp(argv[2], "-h") == 0) {
        outputType = OUTPUT_HEXA;
    } else {
        printf("Unknow output flag: %s\n", argv[2]);
        return 1;
    }

    char *str = argv[3];
    // printf("%s\n", argv[3]);

    /* if (*str == '0') {
        (str)++;
        if (*str == 'x' || *str == 'b' || *str == 'X' || *str == 'B') {
            (str)++;
        }
    } */ 
    
    strcpy(cleanedString, str);
    // printf("Cleaned String: %s\n", cleanedString); /* Clean User Input*/

    /* Main Conversion Logic */
       switch (inputType) {
        case INPUT_BINARY:
            switch (outputType) {
                case OUTPUT_BINARY:
                   result = strdup(cleanedString);
                    break;
                case OUTPUT_DECIMAL:
                    result = binToDec(cleanedString);
                    break;
                case OUTPUT_HEXA:
                    result = binToHex(cleanedString);
                    break;
            }
            break;

        case INPUT_DECIMAL:
            switch (outputType) {
                case OUTPUT_BINARY:
                    result = decToBin(cleanedString);
                    if (result == NULL) {
                        fprintf(stderr, "Error: Conversion Failed\n");
                        return 1;
                    } else {
                        printf("Result: %s\n", result);
                    }
                    break;
                case OUTPUT_DECIMAL:
                    // Decimal to Decimal
                    result = strdup(cleanedString);
                    break;
                case OUTPUT_HEXA:
                    result = decToHex(cleanedString);
                    break;
            }
            break;

        case INPUT_HEXA:
            switch (outputType) {
                case OUTPUT_BINARY:
                    result = hexToBin(cleanedString);
                    break;
                case OUTPUT_DECIMAL:
                    result = hexToDec(cleanedString);
                    break;
                case OUTPUT_HEXA:
                    // Hex to Hex
                    result = strdup(cleanedString);
                    break;
            }
            break;
    }
    
    if (result == NULL) {
        printf("Error: Conversion Failed"); 
        return 1;
    }

    printf("%s\n", result);
    free(result);

    return 0;
}
