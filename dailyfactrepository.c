#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LinkedList data structure
struct fact {
    int size;
    char *factData;
    struct fact *next;
};

/**
* This function will encrypt a string, probably won't be used in live version
*/
void encryptString(char *str)
{
    for(int i = 0; str[i] != '\0' ; i++)
    {
        if(str[i] > 36)
            str[i] = str[i] - 3;
    }
}

/**
* This function will decrypt a string
*/
void decryptString(char *str)
{
    for(int i = 0; str[i] != '\0' ; i++)
    {
        if(str[i] > 36)
            str[i] = str[i] + 3;
    }
}

/**
* This function will print a fact into a nice, readable format
*/
void printFact(char *str, int arrSize)
{
    int i = 0, j = 0, textLength = 110;
    //decryptString(str);
    //system("clear"); // todo: change to "cls" for windows
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

/**
* This function will add a new fact to the LinkedList
*/
void linkedlistAdd(struct fact* head, char *str)
{
    struct fact *curr = head;
    struct fact *new = (struct fact*) malloc(sizeof(struct fact));
    int strSize = strlen(str);
    encryptString(str);
    new->size = strSize;
    new->factData = str;
    new->next = NULL;
    while(curr->next != NULL)
        curr = curr->next;
    curr->next = new;
}

/**
 * This function counts the number of items within the LinkedList
*/
int linkedlistCount(struct fact* head)
{
    int i = 0;
    struct fact *curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
        i++;
    }
    i++;
    return i;
}

/*
* Prints the content of an entire Linkedlist
*/
void printlinkedList(struct fact* head)
{
    struct fact *curr = head;
    while(curr->next != NULL)
    {
        printFact(curr->factData,curr->size);
        curr = curr->next;
    }
    printFact(curr->factData,curr->size);
}

int main()
{
    // HEAD INITIALIZATION
    char a[] = "Even if the variable is uninitialized, there should be no way printf reaches a point where it could print a minus sign when the format specifier was";
    struct fact head = {.size = strlen(a), .factData = a, .next = NULL};
    struct fact *head_ptr = &head;
    encryptString(a);

    // LIST OF FACTS INITIALIZATION
    char b[] = "Test 123 hello world!";
    char c[] = "My name is mark!";
    char d[] = "wow what an interesting fact!";
    linkedlistAdd(head_ptr,b);
    linkedlistAdd(head_ptr,c);
    linkedlistAdd(head_ptr,d);

    //MAIN LOGIC
    printlinkedList(head_ptr);
    printf("Linkedlist count: %d\n",linkedlistCount(head_ptr));
    return 0;
}