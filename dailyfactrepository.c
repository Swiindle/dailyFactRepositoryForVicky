#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fact data structure
struct fact {
    int id;
    int size;
    char *factData;
    struct fact *next;
};

/**
* This function will encrypt a string, probably won't be used in final version
* This function shifts ASCII value backwards 3, taking into account the last ASCII value.
* Technically can be used as a decryption function, if the enryption function is used first.
* @input *str - pointer to string to be encrypted 
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
* This function moves the ASCII value forward 3, taking into account the last ASCII value.
* Technically can be used as a decryption function, if the enryption function is used first.
* @input *str - pointer to string to be decrypted.
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
* This function takes a fact structure and prints it out into a readable format.
* @input fact* fact: pointer to the fact structure that you want to print
*/
void printFact(struct fact* fact)
{
    int i = 0, j = 0, textLength = 110;
    // PART ONE: THE ROOF OF THE CONSOLE
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
        if(fact->factData[i] == '\n')
            j = 0;
        if(j > textLength && fact->factData[i] == ' ')
        {
            printf("\n");
            j = 0;
        }
        i++;
        j++;
    }
    printf("\n\n\n");
    // PART THREE: THE FLOOR OF THE CONSOLE
    i = 0;
    while(i < textLength)
    {
        printf("#");
        i++;
    }
    printf("\n");
}

/**
* This function counts the number of items within the LinkedList. Useful function for general logic.
* @input - fact* head: the head item of the LinkedList.
* Note: the head needs to be defined by the programmer somewhere.
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
* The function adds an item to the LinkedList.
* @input - fact* head: the head item of the LinkedList.
* @input - *str: the String containing the fact.
* Note: the head needs to be defined by the programmer somewhere.
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

/**
* The function acts as the User Interface of the program. Allows the user to cycle through the different facts.
* @input - fact* head: the head item of the LinkedList.
*/
void printlinkedList(struct fact* head)
{
    struct fact *curr = head;
    char input[50];
    system("cls"); // to-do cls for windows

    while (curr != NULL)
    {
        printFact(curr);
        curr = curr->next;
        printf("Press enter for next fact: ");
        fgets(input, sizeof(input), stdin);
        system("cls"); // to-dgito cls for windows
    }
}

int main()
{
    // HEAD INITIALIZATION
    char a[] = "Daily Fact Repository 2020 - 2023\nBuilt by Mark, for Vicky's 24th birthday!\nPress enter to navigate to the next fact.";
    struct fact head = {.id = 0, .size = strlen(a), .factData = a, .next = NULL};
    struct fact *head_ptr = &head;

    // LIST OF FACTS INITIALIZATION
    char fact1[] = "Fk /-.-) ?bidf^k obpb^o`ebop peltba qe^q Efqibo jfdeq e^sb e^a Gbtfpe ^ka >cof`^k ^k`bpqlop+";
    char fact2[] = "Qeb mof`b lc ob^i T^p^_f `lpqp ^ijlpq 1-- alii^op mbo HD+ T^p^_f fp ob^iiv afccf`riq ql dolt) ebk`b qeb lkbp tb kloj^iiv b^q fk prpef obpq^ro^kqp ^ob ^ jfu lc elopbo^afpe ^ka `efkbpb jrpq^oa!";
    char fact3[] = "G O+ O+ Qlihbfk) tofqbo lc qeb Iloa lc qeb Ofkdp) fksbkqba jriqfmib i^kdr^dbp ql prmmloq qeb tloia _rfiafkd lc\nJfaaib*b^oqe+";
    char fact4[] = "M^sils^ fp k^jba ^cqbo >kk^ M^sils^ qeb ?^iibofk^ cliiltfkd ebo qlro fk >rpqo^if^ # Kbt Wb^i^ka+";
    char fact5[] = "Qeb .6.3 Wlkfkd Obplirqflk af`q^qbp qe^q qeb q^iibo qeb _rfiafkd fk Kbt Vloh) qeb pj^iibo b^`e pr_pbnrbkq cillo tfii _b+ Qeb obplirqflk) ^iqelrde mo^`qf`^i) fp ^ ob^plk tev j^kv _rfiafkdp ^olrka qeb tloia illh qeb t^v qebv al!";
    char fact6[] = "Ilkd*cfkkba bbip `^k pljbqfjbp _b clrka ptfjjfkd fk qeb mlkap lc Pvakbv$p Olv^i ?lq^kf` D^oabk+ Qebpb bbip ^ob lkiv qbjmlo^ofiv ifsfkd fk Pvakbv) qebv tfii jfdo^qb _^`h eljb ql _obba ^ka afb ^cqbo {1- vb^op+";
    char fact7[] = "Qeb ^``bkq J^oh kloj^iiv rpbp fp+++ c^hb+ Eb e^p ^ jlob ^pf^k plrkafkd ^``bkq qe^q lkiv ^mmb^op ql c^jfiv jbj_bop+";
    char fact8[] = "J^oh$p ilsb lc c^`qp `ljbp colj Do^ab 1) tebk efp qb^`ebo ^phba efj ql obpb^o`e ^ka mobpbkq c^`qp ql qeb obpq lc efp `i^pp+";
    char fact9[] = "Qtl lc Pvakbv$p abcrk`q jlklo^fi pbosf`b `^oof^dbp `^k _b clrka fk qeb Dlldib lccf`bp+";
    char fact10[] = "Mlkqb @fqv fp qeb k^jb lc ^ lk`b iruroflrp _rfiafkd clo qeb of`e ^ka tb^iqev fk Plrqe >cof`^+ >cqbo qeb >m^oqebfa fq _b`^jb ^ pirj+";
    char fact11[] = "Glek slk Kbrj^kk) jlpq c^jlrp clo efp ^o`efqb`qrob fk `ljmrqbo p`fbk`b) fp ^ipl hkltk clo efp tloh lk qeb J^ke^qq^k Molgb`q";
    char fact12[] = "Jb^profkd lo l_pbosfkd nr^kqrj m^oqf`ibp tfii `e^kdb qebfo _be^sflro ao^pqf`^iiv+ Qefp mebkljbk^ fp hkltk ^p qeb L_pbosbo Bccb`q+";
    char fact13[] = "Qeb cobk`e tloa Ci^kbro abp`of_bp ^ ^k ^j_fs^ibkq mboplk lc ro_^k ^ccirbk`b) obmobpbkqfkd qeb ^_fifqv ql t^kabo abq^`eba colj pl`fbqv tfqe kl lqebo mromlpb qe^k ql _b ^k ^`rqb l_pbosbo lc fkarpqof^ifwba) `lkqbjmlo^ov ifcb+";
    //char lastFact[] = "Ql Sf`hv7\n\nFc vlr’ob ob^afkd qefp) vlr e^sb “plisba” JV pb`obq jbpp^db! @lkdo^qri^qflkp! F elmb qe^q vlr ifhba qeb c^`qp+\n\nF grpq t^kqba ql ibq vlr hklt qe^q vlr ^ob lkb lc qeb jlpq tlkabocri mblmib F’sb jbq! >ka ^ipl dlq ql jbbq! F m^oqf`ri^oiv ilsb qe^q vlr ifhb a^fiv c^`qp) mf`qrobp lc qeb phv ^ka `lafkd IfkhbaIfpqp rkabo G^`^o^ka^ qobbp %telpb ib^sbp c^ii ^ka qrok _oltk ^ka bka rm illhfkd afpdrpqfkd&+ Qe^kh vlr clo _bfkd ^ dbkrfkb mboplk+ Hbbm _bfkd vlropbic!\n\nF elmb qe^q qefp vb^o) vlr tfii bumbofbk`b jlob FD*pqlov*tloqev bumbofbk`bp ifhb dob^q clla) `lk`boqp) crk cofbkap) qofmp) c^iifkd ^pibbm lk `^ii<<<<<< ^ka j^kv j^kv j^kv jlob a^fiv c^`qp+\n\nTb jfdeq q^ih ibpp klt qe^q tb dbq _rpfbo tfqe FOI pqrcc mirp @LSFA fp dlfkd ^t^v+ ?rq alk’q tloov) objbj_bo qe^q “F tfii ^it^vp `^ob ^_lrq vlr ^ka ^it^vp tfii” * qe^q’p m^oq lc lro ab^i!\n\nE^mmv ?foqea^v ^ka qe^kh vlr clo qeb qeobb vb^op)\n\nJ^oh!!";

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
    //linkedlistAdd(head_ptr,lastFact);

    //MAIN LOGIC
    printlinkedList(head_ptr);
    printf("Program finished.\nTotal facts: %d\n",linkedlistCount(head_ptr) - 1);
    return 0;
}