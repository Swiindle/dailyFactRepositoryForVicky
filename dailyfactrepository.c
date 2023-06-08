#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LinkedList data structure
struct fact {
    int id;
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
void printFact(struct fact* fact)
{
    int i = 0, j = 0, textLength = 110;
    //decryptString(str);
    while(i < textLength)
    {
        printf("#");
        i++;
    }
    i = 0;
    printf("\n\n\n");
    if(fact->id > 0)
        printf("Daily Fact No: %d\n", fact->id);
    while (i < fact->size)
    {
        printf("%c",fact->factData[i]);
        if(j > textLength && fact->factData[i] == ' ')
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
 * This function counts the number of items within the LinkedList
*/
int linkedlistCount(struct fact* head)
{
    int i = 0;
    struct fact *curr = head;
    while(curr != NULL)
    {
        curr = curr->next;
        i++;
    }
    return i;
}

/**
* This function will add a new fact to the LinkedList
*/
void linkedlistAdd(struct fact* head, char *str)
{
    struct fact *curr = head;
    struct fact *new = (struct fact*) malloc(sizeof(struct fact));
    int strSize = strlen(str);
    //encryptString(str);
    new->id = linkedlistCount(head);
    new->size = strSize;
    new->factData = str;
    new->next = NULL;
    while(curr->next != NULL)
        curr = curr->next;
    curr->next = new;
}

/*
* Prints the content of an entire Linkedlist
*/
void printlinkedList(struct fact* head)
{
    struct fact *curr = head;
    char input[50];
    
    while (curr != NULL)
    {
        printFact(curr);
        curr = curr->next;
        printf("> ");
        fgets(input, sizeof(input), stdin);
        system("clear"); // to-do cls for windows
    }
}

int main()
{
    // HEAD INITIALIZATION
    char a[] = "Daily Fact Repository 2020 - 2023\nBuilt by Mark, just for Vicky!\nInput anything to go to next fact.";
    struct fact head = {.id = 0, .size = strlen(a), .factData = a, .next = NULL};
    struct fact *head_ptr = &head;
    //encryptString(a);

    // LIST OF FACTS INITIALIZATION
    char b[] = "Test 123 hello world!";
    char c[] = "My name is mark!";
    char d[] = "wow what an interesting fact!";
    linkedlistAdd(head_ptr,b);
    linkedlistAdd(head_ptr,c);
    linkedlistAdd(head_ptr,d);

    //MAIN LOGIC
    printlinkedList(head_ptr);
    return 0;
}