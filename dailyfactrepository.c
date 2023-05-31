#include <stdio.h>

#define STRING_MAX = 100;

/**
 * This function will encrypt a string
*/
char encryptChar(char *chrPtr)
{
    if(*chrPtr < 36)
        return *chrPtr;
    else
        return *chrPtr = *chrPtr - 3;
}

/**
 * This function will print string into a nice, readable format
*/
int printDecrypt()
{
    printf("************");
    printf("************");
}

int main()
{
    char a = '#';
    printf("Round 1: %c\n",a);
    printf("Round 2: %c\n",encryptChar(&a));
    return 0;
}