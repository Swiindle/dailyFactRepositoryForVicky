#include <stdio.h>
#include <stdlib.h>

/**
* This function will encrypt a string, probably won't be used in live version
*/
char * encryptString(char str[], int arrSize)
{
    char a;
    for(int i = 0 ; i < arrSize ; i++)
    {
        char a = str[i];
        if(a < 36)
            str[i] = a;
        else
            str[i] = str[i] - 3;
    }
    return str;
}

/**
* This function will decrypt a string
*/
char * decryptString(char str[], int arrSize)
{
    char a;
    for(int i = 0 ; i < arrSize ; i++)
    {
        char a = str[i];
        if(a < 36)
            str[i] = a;
        else
            str[i] = str[i] + 3;
    }
    return str;
}

/**
* This function will print string into a nice, readable format
*/
void printString(char str[], int arrSize)
{
    int i = 0, j = 0, textLength = 110;
    system("clear"); // todo: change to "cls" for windows
    while(i < textLength)
    {
        printf("#");
        i++;
    }
    i = 0;
    printf("\n\n\n");
    while (i < arrSize)
    {
        printf("%c",str[i]);
        if(j > textLength && str[i] == ' ')
        {
            printf("\n");
            j = 0;
        }
        i++;
        j++;
    }
    printf("\n\n\n");
    i = 0;
    while(i < textLength)
    {
        printf("#");
        i++;
    }
    printf("\n");
}

int main()
{
    char a[] = "Even if the variable is uninitialized, there should be no way printf reaches a point where it could print a minus sign when the format specifier was";
    int a_size = (int) sizeof(a)/sizeof(a[0]);

    //printf("Round 1: %s\n",a);
    //printf("Round 2: %s\n",encryptString(a,a_size));
    //printf("Round 3: %s\n",decryptString(a,a_size));
    printString(a,a_size);
    return 0;
}