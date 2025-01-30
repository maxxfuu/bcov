#ifndef CONVERSION_H
#define CONVERSION_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

static void reverseString(char *input);

/* Function Prototype Here */ 

char *hexToDec(const char *input); 
char *hexToBin(const char *input); 

char *decToHex(const char *input); 
char *decToBin(const char *input);

char *binToHex(const char *input); 
char *binToDec(const char *input); 

#endif 
