#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define BUFFER 1000

/* Create functions in header file to change between different data notation */

int main(void) {
    
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
    printf("Cleaned String: %s\n", cleanedString); 

    return 0; 
}

/*Take a string, check for the first two characters, check if the last char is end of line character*/

