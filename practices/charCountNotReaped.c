#include <stdio.h>
#include <string.h>

int main(void)
{
    int search(char *, char);
    char str[95]={0}, ch;
    int i;
    ch = getchar();
    i = 0;
    while(ch!='\n'&&ch!=EOF)
    {
        if(!search(str, ch))
        {
            str[i] = ch;
            i++;
        }
        ch = getchar();
    }
    printf("%d\n", strlen(str));
    return 0;
}

int search(char * str, char ch)
{
    int i;
    for(i=0; str[i]; i++)
    {
        if(str[i]==ch)
            return 1;
    }
    return 0;
}