#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EXIT 1

/* save the user's choice */
int Option;  
/* Record whether the user chooses to continue */
int Cotinue; 
/* Detect whether the user's current input is valid */ 
int Invalid;
/* This function is used to clear the input buffer */
void clear(void);

int main(void)
{   
    void encode(void);
    void decode(void);
    void welcome(void);
    void bye(void);
    void setContinue(int *);
    
    while (1) 
    {
        welcome();
        scanf("%1c", &Option);
        clear();

        switch (Option)
        {
        case '1':
            /* go to encode */
            do
            {   
                encode();
                setContinue(&Cotinue);
            } while (Cotinue);
            break;
        case '2':
            /* go to decode */
            do
            {
                decode();
                setContinue(&Cotinue);
            } while (Cotinue);
            break;   
        case '0':
            bye();
            return (EXIT);  
        default:
            Invalid = 1;
            
            break;
        }
    }

    return 0;
}

void encode(void)
{   
    void print_b(unsigned char);
    unsigned char ch;
    
    system("cls");
    printf("Input your sentence: ");
    while ( (ch = getchar()) && (ch != '\n') )
    {
        // printf("0x%X ", ch);
        print_b(ch);
    }
    printf("\n==============================================================\n");    
}

void decode(void)
{
    int fake_byte;
    int real_byte;
    /*how to extend? */
    char string[400];   
    int bit;
    int count = 0;
    system("cls");
    printf("Input your sentence(End with a '#'): ");
    while (scanf("%d", &fake_byte))
    {
        int i;
        for (i=0; i<8; i++)
        {
            bit = fake_byte%10;
            fake_byte = fake_byte/10;
            real_byte += bit * pow(2, i);
        }
        string[count] = (unsigned char)real_byte;
        real_byte = 0;
        count++;
    }
    string[count] = '\0';
    printf("%s\n", string);
    printf("\n==============================================================\n");
    clear();
}

void bye(void)
{   
    system("cls");     
    printf("***************************************************************\n");
    printf("* bye...\n");
}

void welcome(void)
{
    system("cls");
    /* welcome page */
    printf("***************************************************************\n");
    printf("*                                                             *\n");
    printf("*        WELCOME TO  LSP ENCODING & DECODING SYSTEM           *\n");
    printf("*                                                             *\n");
    printf("***************************************************************\n");
    printf("*    1. ------------------- Encoding                          *\n");
    printf("*    2. ------------------- Decoding                          *\n");
    printf("*    0. ------------------- Exit                              *\n");
    printf("***************************************************************\n");
    if (Invalid) 
    {
        printf("The choice you input is invalid!!!\nPlease input again: ");
        Invalid = 0;
    }
    else
    {
        printf("Input your choice:");
    }
}

void setContinue(int * Continue)
{
    printf("Do you want to continue? 1 for yes and 0 for no\n");
    printf("Enter your choice: ");
    /* If the user input is not 1 or 0, ask to re-enter */
    while (!scanf("%d", Continue) || (*Continue != 0 && *Continue != 1) )
    {
        printf("The choice you input is invalid...\nEnter your choice angin: ");
        clear();
    }
    clear();
}

/* Convert a char character to 8-bit binary output */
void print_b(unsigned char ch)
{
    int bits = sizeof(unsigned char) * 8;
    unsigned char str[bits];
    int len = bits;
    while (bits > 0) 
    {
        str[bits-1] = ch % 2;
        ch = ch / 2;
        bits--; 
    }
    for (int i=0; i<len; i++)
    {
        printf("%u", str[i]);
    }
    printf(" ");
}

/* This function is used to clear the input buffer */
void clear(void)
{
    char c;
    while ( (c = getchar()) != EOF && c != '\n'){}
}