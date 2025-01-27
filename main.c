#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define BUFFER 1000

/* Create functions in header file to change between different data notation */

int main(void) {
    int choice; 
    
    while(1) {
    
        // Display Menu 
        printf("\n--- Conversion Menu ---\n");
        printf("1. Hexadecimal to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Binary to Hexadecimal\n");
        printf("4. Exit\n");
        printf("-------------------------\n");
        printf("\nEnter your choice: "); 
        
        /* Check User Input */
        if (scanf("%d", &choice) != 1) {
            printf("Invalid Input. Please Enter A Number.\n"); 
            while (getchar() != '\n')      /* Clears Buffer */
                continue; 
        }

        if (choice == 4) {
            printf("\n\nExiting...\n");
            exit(1); 
        }




    }




    printf("Byte Conversion - Enter a HexaDecimal, Binary Value, Decimal Value, to be converted into one of following choices\n\n");
    printf("Input > "); 

    /* User Conversion Option*/
    

    /* Get User Input */

    char input[BUFFER]; /* To create an array with fixed size buffer */
    char cleanedString[BUFFER]; 
    
    if (!fgets(input, sizeof(input), stdin)) {
        exit(1); 
    }
    
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    } 

    char *str = input; 

    if (*str == '0') {
        (str)++; 
        if (*str == 'x' || *str == 'b' || *str == 'X' || *str == 'B') {
            (str)++;
        }
    } 
    
    strcpy(cleanedString, str); 
    printf("Cleaned String: %s\n", cleanedString); /* Clean User Input*/

        

    return 0; 
}

/*Take a string, check for the first two characters, check if the last char is end of line character*/

