#include <stdio.h>

int main(void)
{
    void clear(void);
    char gender, diteHeathy;;
    double faH, moH, height;
    int sport;

    printf("Boys(M) or girl(F):");
    gender = getchar();
    clear();
    printf("Input father height(cm):");
    scanf("%lf", &faH);
    clear();
    printf("Input mother height(cm):");
    scanf("%lf", &moH);
    clear();
    printf("Do you like sports(3/2/1):");
    scanf("%d", &sport);
    clear();
    printf("Do you have a good habit of diet(Y/N):");
    diteHeathy = getchar();
    clear();

    switch (gender)
    {
        case 'F':
        case 'f':
            height = (faH*0.923+moH)/2;
            break;
        case 'M':
        case 'm':
            height = (faH+moH)*0.54;
            break;
    }
    switch (sport)
    {
        case 3:
            height *= (1+0.02);
            break;
        case 2:
            height *= (1+0.01);
            break;
        case 1:
            break;
    }
    switch (diteHeathy)
    {
        case 'Y':
        case 'y':
            height *= (1+0.015);
            break;
        case 'N':
        case 'n':
            break;
    }

    printf("Your future height will be %.2lf(cm)\n", height);
    
    return 0;
}

void clear(void)
{
    char ch;
    while ((ch=getchar()) != '\n' && ch!=EOF);
}