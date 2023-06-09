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
        if(str[i] > 33)
            str[i] = str[i] + 3;
    }
}

/**
* This function will print a fact into a nice, readable format
*/
void printFact(struct fact* fact)
{
    int i = 0, j = 0, textLength = 110;
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
        // Formatting BUG HERE !!!
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
    decryptString(str);
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
    system("clear"); // to-do cls for windows

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
    char a[] = "Daily Fact Repository 2020 - 2023\nBuilt by Mark, just for Vicky!\nInput and press enter anything to navigate to the next fact.";
    struct fact head = {.id = 0, .size = strlen(a), .factData = a, .next = NULL};
    struct fact *head_ptr = &head;

    // LIST OF FACTS INITIALIZATION
    char fact1[] = "Fk /-.-) ?bidf^k obpb^o`ebop peltba qe^q Efqibo jfdeq e^sb e^a Gbtfpe ^ka >cof`^k ^k`bpqlop+";
    char fact2[] = "Qeb mof`b lc ob^i T^p^_f `lpqp ^ijlpq 1-- alii^op mbo HD+ T^p^_f fp ob^iiv afccf`riq ql dolt) ebk`b qeb lkbp tb kloj^iiv b^q fk prpef obpq^ro^kqp ^ob ^ jfu lc elopbo^afpe ^ka `efkbpb jrpq^oa!";
    char fact3[] = "G O+ O+ Qlihbfk) tofqbo lc qeb Iloa lc qeb Ofkdp) fksbkqba jriqfmib i^kdr^dbp ql prmmloq qeb tloia _rfiafkd lc Jfaaib*b^oqe+";
    char fact4[] = "M^sils^ fp k^jba ^cqbo >kk^ M^sils^ qeb ?^iibofk^ cliiltfkd ebo qlro fk >rpqo^if^ # Kbt Wb^i^ka+";
    char fact5[] = "Qeb .6.3 Wlkfkd Obplirqflk af`q^qbp qe^q qeb q^iibo qeb _rfiafkd fk Kbt Vloh) qeb pj^iibo b^`e pr_pbnrbkq cillo tfii _b+ Qeb obplirqflk) ^iqelrde mo^`qf`^i) fp ^ ob^plk tev j^kv _rfiafkdp ^olrka qeb tloia illh qeb t^v qebv al!";
    char fact6[] = "Ilkd*cfkkba bbip `^k pljbqfjbp _b clrka ptfjjfkd fk qeb mlkap lc Pvakbv$p Olv^i ?lq^kf` D^oabk+ Qebpb bbip ^ob lkiv qbjmlo^ofiv ifsfkd fk Pvakbv) qebv tfii jfdo^qb _^`h eljb ql _obba ^ka afb ^cqbo {1- vb^op+";
    char fact7[] = "Qeb ^``bkq J^oh kloj^iiv rpbp fp c^hb+ Eb e^p ^ jlob ^pf^k plrkafkd ^``bkq qe^q lkiv ^mmb^op ql c^jfiv jbj_bop+";
    char fact8[] = "J^oh$p ilsb lc c^`qp `ljbp colj Do^ab 1) tebk efp qb^`ebo ^phba efj ql obpb^o`e ^ka mobpbkq c^`qp ql qeb obpq lc efp `i^pp+";
    char fact9[] = "Qtl lc Pvakbv$p abcrk`q jlklo^fi pbosf`b `^oof^dbp `^k _b clrka fk qeb Dlldib lccf`bp+";
    char fact10[] = "Mlkqb @fqv fp qeb k^jb lc ^ lk`b iruroflrp _rfiafkd clo qeb of`e ^ka tb^iqev fk Plrqe >cof`^+ >cqbo qeb >m^oqebfa fq _b`^jb ^ pirj+";
    char fact11[] = "Glek slk Kbrj^kk) jlpq c^jlrp clo efp ^o`efqb`qrob fk `ljmrqbo p`fbk`b) fp ^ipl hkltk clo efp tloh lk qeb J^ke^qq^k Molgb`q";
    char fact12[] = "Jb^profkd lo l_pbosfkd nr^kqrj m^oqf`ibp tfii `e^kdb qebfo _be^sflro ao^pqf`^iiv+ Qefp mebkljbk^ fp hkltk ^p qeb L_pbosbo Bccb`q+";
    char fact13[] = "Qeb cobk`e tloa Ci^kbro abp`of_bp ^ ^k ^j_fs^ibkq mboplk lc ro_^k ^ccirbk`b) obmobpbkqfkd qeb ^_fifqv ql t^kabo abq^`eba colj pl`fbqv tfqe kl lqebo mromlpb qe^k ql _b ^k ^`rqb l_pbosbo lc fkarpqof^ifwba) `lkqbjmlo^ov ifcb+";

    linkedlistAdd(head_ptr,fact1);
    linkedlistAdd(head_ptr,fact2);
    linkedlistAdd(head_ptr,fact3);
    linkedlistAdd(head_ptr,fact4);
    linkedlistAdd(head_ptr,fact5);
    linkedlistAdd(head_ptr,fact6);
    linkedlistAdd(head_ptr,fact7);
    linkedlistAdd(head_ptr,fact8);
    linkedlistAdd(head_ptr,fact9);
    linkedlistAdd(head_ptr,fact10);
    linkedlistAdd(head_ptr,fact11);
    linkedlistAdd(head_ptr,fact12);
    linkedlistAdd(head_ptr,fact13);

    //MAIN LOGIC
    printlinkedList(head_ptr);
    return 0;
}