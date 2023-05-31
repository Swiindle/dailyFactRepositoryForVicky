#include <stdio.h>

/**
* This function will encrypt a string
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
void printEncryptString(char str[], int arrSize)
{
    int i, j = 0;
    printf("%s", str);
    while (i < arrSize)
    {
        printf("%c",str[i]);
        if(j == 40)
        {
            printf("\n");
            j = 0;
        }
        i++;
        j++;
    }
}

int main()
{
    char a[] = "Even if the variable is uninitialized,\nthere should be no way printf reaches a point where it could print a minus sign when the format specifier was";
    int a_size = (int) sizeof(a)/sizeof(a[0]);
    printf("Round 1: %s\n",a);
    printf("Round 2: %s\n",encryptString(a,a_size));
    printf("Round 3: %s\n",decryptString(a,a_size));
    return 0;
}