#include <stdio.h>
#include <stdlib.h>
#define LONG 21
#define SHORT 17
#define TOTAL 150
#define LENG(a, b) (LONG*(a)+SHORT*(b))
#define REMAIN(a, b) TOTAL-LENG((a), (b))


struct _Method
{
    /* split method */
    int long_m;
    int short_m;
    int remain;
    /* pointer */
    struct _Method * next;
};

typedef struct _Method Method;
Method * listInit();
void listAdd(Method *, int , int , int);
void listPrint(Method *);
void listDestroy(Method **);
int listCount(Method *);
int deal(Method *, Method *, int, int);

int main(void)
{
    int a, b, re, sum;
    int m, n;
    Method * Head, *Head2;

    // save methods
    Head = listInit();
    Head2 = listInit();
    for(a=0; a<=TOTAL/LONG; a++)
    {
        for(b=0; b<=TOTAL/SHORT; b++)
        {
            sum = LENG(a, b);
            re = TOTAL - sum;
            if ( sum<=TOTAL && re<SHORT)
            {
                listAdd(Head, a, b, re);
            }        
        }
    }

    // get m for long you need and n for short you need
    printf("m for long material:");
    scanf("%d", &m);
    printf("n for short material:");
    scanf("%d", &n);

    //print some basic info
    printf("\n+++++++++++++++++++++++++++++++\n");
    printf("a material's total length: %d\n", TOTAL);
    printf("long material's length: %d\n", LONG);
    printf("short material's length: %d\n", SHORT);
    printf("long materital you need: %d\n", m);
    printf("short material you need: %d\n", n);
    printf("+++++++++++++++++++++++++++++++\n\n");

    //show split methods of one material
    printf("For one material, there are %d split methods\n", listCount(Head));
    listPrint(Head);
    printf("\n");

    //deal with m and n
    deal(Head, Head2, m, n);

    //show methods and how many materials you should buy
    printf("The method is here.\n", listCount(Head2));
    listPrint(Head2);
    printf("you should buy at least [%d] materials\n", listCount(Head2));
    printf("The total remaining material length is: %d\n\n", TOTAL*listCount(Head2)-m*LONG-n*SHORT);
    
    //release memory
    listDestroy(&Head);
    listDestroy(&Head2);
    
    return 0;
}

//initilize method list
Method * listInit(void)
{
    Method * p = NULL;
    p = (Method *)malloc(sizeof(Method));
    if (p==NULL)
    {
        printf("Memory allocation failed!\n");
        exit(-1);
    }
    p->long_m = -1;
    p->short_m = -1;
    p->remain = -1;
    p->next = NULL;
    return p;
}

//add a new method into list (orderly add)
void listAdd(Method * pHead, int _long_m, int _short_m, int _remain)
{
    Method * pm = NULL, * ptr, *pInto, * temp;
    // allocate memory space for a method
    pm = (Method *)malloc(sizeof(Method));
    if (pm==NULL)
    {
        printf("Memory allocation failed!\n");
        exit(-1);
    }
    // method
    pm->long_m = _long_m;
    pm->short_m = _short_m;
    pm->remain = _remain;
    // add the method into list
    pInto = pHead;
    for (ptr=pHead; ptr->next!=NULL; ptr=ptr->next)
    {
        if (pm->remain > ptr->next->remain)
        {
            pInto = ptr->next;
        }
    }
    temp = pInto->next;
    pInto->next = pm;
    pm->next = temp;
}

//print all methods in list
void listPrint(Method * pHead)
{
    Method *ptr=NULL;
    int i;
    printf("===================================\n");
    printf("index\tlong\tshort\tremain\n");
    printf("===================================\n");
    for (i=1, ptr=pHead->next; ptr!=NULL; ptr=ptr->next, i++)
    {
        printf("No.%02d\t%d\t%d\t%d\n", i, ptr->long_m, ptr->short_m, ptr->remain);
    }
    printf("===================================\n");
}

//release all the memory the list used
void listDestroy(Method ** pHead)
{
    Method * current = *pHead;
    Method * next;
    while (current!=NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *pHead = NULL;
}

//get count of the list 
int listCount(Method * pHead)
{
    int i;
    Method * p;
    for (i=0, p=pHead->next;p!=NULL; p=p->next)
    {
        i++;
    }
    return i;
}

//m n deal
int deal(Method * pHead, Method * pHead2, int long_need, int short_need)
{
    Method * p1;
    for (p1=pHead->next; p1!=NULL; p1=p1->next)
    {
        if (long_need<=p1->long_m && short_need<=p1->short_m)
        {
            listAdd(pHead2, long_need, short_need, REMAIN(long_need,short_need));
            return 0;
        }
    }
    for (p1=pHead->next; p1!=NULL; p1=p1->next)
    {
        if (long_need>=p1->long_m && short_need>=p1->short_m)
        {
            listAdd(pHead2, p1->long_m, p1->short_m, p1->remain);
            long_need = long_need-p1->long_m;
            short_need = short_need-p1->short_m;
            deal(pHead, pHead2, long_need, short_need);
            break;
        }
    }
}