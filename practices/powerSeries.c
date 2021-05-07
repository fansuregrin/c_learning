#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 40
#define TRUE 1
#define FALSE 0

typedef int Bool;

struct _Item
{
    int coefficient;    //系数
    int degree;          //次数
    struct _Item * next;
};
typedef struct _Item Item, *ItemPtr, *Polynomial;

typedef struct _Monomial
{
    int coef;
    int degree;
} Monomial;

struct _Char
{
    char data;
    struct _Char * next;
};
typedef struct _Char Char, * CharList;

Bool isNumber(char ch)
{
    if(ch>='0'&&ch<='9')
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}

Polynomial InitPolynomial(void)
{
    Polynomial polynom = NULL;
    return polynom;
}

void AddItem(Polynomial *polynom, int coef, int degree)
{
    ItemPtr item;
    item = (ItemPtr)malloc(sizeof(Item));
    if(item==NULL)
    {
        printf("allocation error!\n");
        exit(-1);
    }
    else if(*polynom==NULL)
    {
        item->next = NULL;
        item->coefficient = coef;
        item->degree = degree;
        *polynom = item;
    } 
    else
    {
        item->next = *polynom;
        item->coefficient = coef;
        item->degree = degree;
        *polynom = item;
    } 
}

void AddItemByOrder(Polynomial *polynom, int coef, int degree)
{
    if(coef==0)
        return;
    ItemPtr ptr, item, prev;
    item = (ItemPtr)malloc(sizeof(Item));
    if(item==NULL)
    {
        printf("allocation error!\n");
        exit(-1);
    }
    item->coefficient = coef;
    item->degree = degree;
    if(*polynom==NULL)
    {
        item->next = NULL;
        *polynom = item;
        return;
    }
    ptr = *polynom;
    while(ptr!=NULL && degree<ptr->degree)
    {
        prev = ptr;
        ptr = ptr->next;      
    }
    if(ptr!=*polynom)
    {
        if(ptr!=NULL && ptr->degree==degree)
        {
            ptr->coefficient += coef;
            free(item);
        }
        else
        {
            item->next = ptr;
            prev->next = item; 
        }
    }
    else
    {
        if(ptr->degree==degree)
        {
            ptr->coefficient+=coef;
            free(item);
        }
        else
        {
            item->next = ptr;
            *polynom = item;
        }
    }
}

void PrintPolynomial(Polynomial polynom)
{
    int first=1;
    while(polynom!=NULL)
    {
        if(first)
        {
            if(polynom->coefficient==1)
            {
                if(polynom->degree==0)
                    printf("1");
            }
            else if(polynom->coefficient==-1)
            {
                if(polynom->degree!=0)
                    printf("-");
                else
                    printf("-1");
            }
            else
                printf("%d", polynom->coefficient);
            if(polynom->degree<0)
                printf("x^(%d)", polynom->degree);
            else if(polynom->degree==0);
            else if(polynom->degree==1)
                printf("x");
            else
                printf("x^%d", polynom->degree);
            first=0;
            polynom = polynom->next;
        }
        else
        {
            if(polynom->coefficient==1)
            {
                if(polynom->degree!=0)
                    printf("+");
                else
                    printf("+1");
            }
            else if(polynom->coefficient==-1)
            {
                if(polynom->degree!=0)
                    printf("-");
                else
                    printf("-1");
            }
            else
                printf("%+d", polynom->coefficient);
            if(polynom->degree<0)
                printf("x^(%d)", polynom->degree);
            else if(polynom->degree==0);
            else if(polynom->degree==1)
                printf("x");
            else
                printf("x^%d", polynom->degree);
            polynom = polynom->next;
        }
    }
    printf("\n");
}

void DeletePolynomial(Polynomial *polynom)
{
    ItemPtr ptr, next;
    ptr = *polynom;
    while(ptr!=NULL)
    {
        next = ptr->next;
        free(ptr);
        ptr = next;
    }
    *polynom = NULL;
}

void ClearPolynomial(Polynomial *polynom)
{
    ItemPtr ptr, next;
    ptr = *polynom;
    while(ptr!=NULL)
    {
        next = ptr->next;
        free(ptr);
        ptr = next;
    }
    *polynom = ptr;
}

/*
 * Function:  AddTwoPolynomial
 * --------------------
 * add two polynomials like this:
 *      3x^4-56x^(-2)
 *
 *  polynom1: a polynomial
 *  polynom2: another polynomial
 *  polynomSum: the sum of two polynomials
 *
 *  returns: void
 */
void AddTwoPolynomial(Polynomial polynom1, Polynomial polynom2, Polynomial * polynomSum)
{
    void ClearPolynomial(Polynomial *);
    void AddItemByOrder(Polynomial *, int, int);
    ItemPtr p1, p2;
    p1 = polynom1;
    p2 = polynom2;
    ClearPolynomial(polynomSum);
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->degree==p2->degree)
        {
            AddItemByOrder(polynomSum, p1->coefficient + p2->coefficient, p1->degree);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->degree>p2->degree)
        {
            AddItemByOrder(polynomSum, p1->coefficient, p1->degree);
            p1 = p1->next;
        }
        else
        {
            AddItemByOrder(polynomSum, p2->coefficient, p2->degree);
            p2 = p2->next;
        }
    }
    if(p1==NULL && p2==NULL){}
    else
    {
        while(p2!=NULL)
        {
            AddItemByOrder(polynomSum, p2->coefficient, p2->degree);
            p2 = p2->next;
        }
        while(p1!=NULL)
        {
            AddItemByOrder(polynomSum, p1->coefficient, p1->degree);
            p1 = p1->next;
        }
    }
}

CharList InitCharList(void)
{
    CharList list = NULL;
    return list;
}

Bool IsEmpty(CharList list)
{
    if(list==NULL)
        return TRUE;
    else
        return FALSE;
}

int GetLen(CharList list)
{
    int count=0;
    while(list!=NULL)
    {
        list = list->next;
        count++;
    }
    return count;
}

void AppendChar(CharList * list, char ch)
{
    Char * newChar, * ptr;
    ptr = *list;
    if(ptr==NULL)
    {
        newChar = (Char *)malloc(sizeof(Char));
        if(newChar==NULL)
        {
            printf("allocation error!\n");
            exit(-1);
        }
        newChar->next = NULL;
        newChar->data = ch;
        *list = newChar;
    }
    else
    {
        newChar = (Char *)malloc(sizeof(Char));
        if(newChar==NULL)
        {
            printf("allocation error!\n");
            exit(-1);
        }
        newChar->data = ch;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        newChar->next = ptr->next;
        ptr->next = newChar;
    }
}

void InsertChar(CharList * list, char ch, int index)
{
    void AppendChar(CharList *, char);
    int GetLen(CharList);
    int len, i;
    Char * ptr, * newChar;
    len = GetLen(*list);
    ptr = *list;
    if(index<0 || index>=len)
        return;
    newChar = (Char *)malloc(sizeof(Char));
    if(newChar==NULL)
    {
        printf("allocation error!\n");
        exit(-1);
    }
    newChar->data = ch;
    if(index==0)
    {
        newChar->next = ptr;
        *list = newChar;
    }
    else
    {
        for(i=0; i<index-1; i++)
        {
            ptr = ptr->next;
        }
        newChar->next = ptr->next;
        ptr->next = newChar;
    }
}

void DeleteCharList(CharList * list)
{
    Char * ptr, * next;
    ptr = *list;
    while(ptr!=NULL)
    {
        next = ptr->next;
        free(ptr);
        ptr = next;
    } 
    *list = NULL;
}

void DeteleSpsce(CharList * list)
{
    Char * ptr, *prev, *next;
    ptr = *list;
    prev = ptr;
    while(ptr!=NULL)
    {
        if(ptr->data==' ')
        {
            if(ptr==*list)
            {
                next = ptr->next;
                *list = ptr->next;
                free(ptr);
                ptr = next;
                prev = ptr;
            }
            else
            {
                prev->next = ptr->next;
                free(ptr);
                ptr = prev->next;
            }
        }
        else
        {
            prev = ptr;
            ptr = ptr->next;
        }
    }
}

Monomial * IdentifyNum(CharList list)
{
    Bool isNumber(char);
    Monomial * monomial;
    int i, hasX, indexOfX, coef, degree, flag;
    monomial = (Monomial *)malloc(sizeof(Monomial));
    if(monomial==NULL)
    {
        printf("allocation error!\n");
        exit(-1);
    }
    monomial->coef = 1;
    monomial->degree = 0;
    i = 0;
    coef = 0;
    flag = 1;
    hasX = FALSE;
    Char * ptr = list;
    while(ptr!=NULL)
    {
        if(ptr->data=='x')
        {
            hasX = TRUE;
            indexOfX = i;
            break;
        }
        ptr = ptr->next;
        i++;
    }
    if(hasX)
    {
        i = 0;
        if(list->data=='-')
            flag = -1;
        for(i, ptr=list; i<indexOfX && list->next->data!='x'; i++, ptr=ptr->next)
        {
            if(isNumber(ptr->data))
            {
                coef = coef*10 + (ptr->data-'0');
            }
        }
        if(i!=0)
        {
            monomial->coef = flag*coef;
        }
        else if(list->data=='-' && list->next->data=='x')
        {
            monomial->coef = -1;
        }
        else if(isNumber(list->data) && list->next->data=='x')
        {
            monomial->coef = (list->data-'0');
        }

        for(ptr=list; ptr->data!='x'; ptr=ptr->next);
        i = 0;
        flag = 1;
        for(i, ptr=ptr->next; ptr!=NULL; ptr=ptr->next, i++)
        {
            if(ptr->data=='-')
                flag = -1;
            if(isNumber(ptr->data))
            {
                degree = degree*10 + (ptr->data-'0');
            }
        }
        if(i==0)
            monomial->degree = 1;
        else
            monomial->degree = flag*degree;
    }
    else
    {
        if(list->data=='-')
            flag = -1;
        for(ptr=list; ptr!=NULL; ptr=ptr->next)
        {
            if(isNumber(ptr->data))
            {
                coef = coef*10 + (ptr->data-'0');
            }
        }
        monomial->coef = coef*flag;
        monomial->degree = 0;
    }

    return monomial;
}

void DealInput(CharList *list)
{
    void AppendChar(CharList *, char);
    char ch;
    ch = getchar();
    while(ch!='\n')
    {
        if(ch==' ')
            ;
        else
            AppendChar(list, ch);
        ch = getchar();
    }
}

CharList Extract(CharList *list)
{
    CharList InitCharList(void);
    void AppendChar(CharList *, char);
    Char * ptr, *current;
    char prevCh;
    CharList new;
    new = InitCharList();
    int first=TRUE;
    ptr = *list;
    while(ptr!=NULL)
    {
        if(first)
        {
            first = FALSE;
            AppendChar(&new, ptr->data);
            current = ptr;
            *list = ptr->next;
            prevCh = ptr->data; 
            ptr = ptr->next;
            free(current);
        }
        else
        {
            if( (prevCh!='('&&ptr->data=='-') || ptr->data=='+')
            {
                *list = ptr;
                break;
            }
            AppendChar(&new, ptr->data);
            current = ptr;
            prevCh = ptr->data;
            *list = ptr->next; 
            ptr = ptr->next;
            free(current);
            
        }
    }

    return new;
}

int main(void)
{
    Polynomial InitPolynomial(void);
    void AddItemByOrder(Polynomial *, int, int);
    void PrintPolynomial(Polynomial);
    void DeletePolynomial(Polynomial *);
    void AddTwoPolynomial(Polynomial, Polynomial, Polynomial *);
    CharList InitCharList(void);
    void AppendChar(CharList *, char);
    Monomial * IdentifyNum(CharList);
    void DealInput(CharList *);
    CharList Extract(CharList *);
   
    Polynomial p1, p2, p3;
    CharList chLi, chLi2;
    Monomial * mo = NULL;

    p1 = InitPolynomial();
    p2 = InitPolynomial();
    p3 = InitPolynomial();
    chLi = InitCharList();

    printf("polynomial input format must be this, for example:\n");
    printf("3x^5, -x^(-3), 343, x^(-43), x^777, -45x...\n");
    
    printf("input polynomial of p1:");
    DealInput(&chLi);
    while(chLi!=NULL)
    {
        chLi2 = Extract(&chLi);
        mo = IdentifyNum(chLi2);
        AddItemByOrder(&p1, mo->coef, mo->degree);
        DeleteCharList(&chLi2);
        free(mo);
        mo = NULL;
    }
    DeleteCharList(&chLi);

    printf("input polynomial of p2:");
    DealInput(&chLi);
    while(chLi!=NULL)
    {
        chLi2 = Extract(&chLi);
        mo = IdentifyNum(chLi2);
        AddItemByOrder(&p2, mo->coef, mo->degree);
        DeleteCharList(&chLi2);
        free(mo);
        mo = NULL;
    }
    DeleteCharList(&chLi);

    printf("p1: ");
    PrintPolynomial(p1);
    printf("p2: ");
    PrintPolynomial(p2);

    AddTwoPolynomial(p1, p2, &p3);
    printf("p1+p2: ");
    PrintPolynomial(p3);

    DeletePolynomial(&p1);
    DeletePolynomial(&p2);
    DeletePolynomial(&p3);

    //system("pause");
    return 0;
}