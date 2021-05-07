#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char * convertion(char * str, int from, int to)
{
    int length, i;
    int decNum, temp;
    char * num1, * num2;
    decNum = 0;
    length = strlen(str);
    num1 = (char *)malloc((length+1)*sizeof(char));
    *(num1+length) = 0;
    strcpy(num1, str);
    for(i=0; i<length; i++)
    {
        decNum += (num1[length-i-1]-'0')*pow(from, i);
    }

    temp = decNum;
    for(length=0; temp!=0; length++,temp/=to);
    num2 = (char *)malloc((length+1)*sizeof(char));
    num2[length] = 0;
    for(i=0; decNum!=0; i++)
    {
        num2[length-i-1] = decNum%to + '0';
        decNum /= to;
    }

    return num2;
}

int main(void)
{
    char * convertion(char *, int, int);
    printf("%s\n", convertion("123", 100, 2));
    printf("%s\n", convertion(convertion("123", 100, 2), 2, 100));
    return 0;
}