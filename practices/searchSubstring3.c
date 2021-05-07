#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INIT_SIZE 100
#define INCREASE_SIZE 50

int main(void)
{
    char * myGets(void);
    int * subStrMatch(char *, char *);
    char *str, *subStr;
    int * foundPos, i;
    printf("Input string:");
    str = myGets();
    printf("Input substring:");
    subStr = myGets();
    
    foundPos = subStrMatch(str, subStr);

    if(foundPos[0]==-1)
    {
        printf("No substring %s\n", subStr);
    }
    else
    {
        printf("Substring %s position:", subStr);
        for(i=0; foundPos[i]!=-1; i++)
        {
            printf("%d ", foundPos[i]);
        }
        printf("\n");
    }
    free(str);
    free(subStr);
    free(foundPos);
    return 0;
}

char * myGets(void)
{   
    char * str, *temp; 
    char ch;
    int strLen, i;
    str = (char *)calloc(INIT_SIZE, sizeof(char));
    if(str==NULL)
    {
        printf("memory error!\n");
        exit(-1);
    }
    strLen = INIT_SIZE;
    ch = getchar();
    i = 0;
    while(ch!='\n'&&ch!=EOF)
    {
        if(i>=strLen)
        {
            temp = (char *)realloc( str, (strLen+INCREASE_SIZE)*sizeof(char) );
            if(temp==NULL)
            {
                free(str);
                printf("memory error!\n");
                exit(-1);
            }
            else
            {
                str = temp;
            }
            strLen += INCREASE_SIZE;
        }
        str[i] = ch;
        ch = getchar();
        i++;
    }
    if(i>=strLen)
    {
        temp = (char *)realloc( str, (strLen+INCREASE_SIZE)*sizeof(char) );
        if(temp==NULL)
        {
            free(str);
            printf("memory error!\n");
            exit(-1);
        }
        else
        {
            str = temp;
        }
        strLen += INCREASE_SIZE;
    }
    str[i+1] = 0;
    return str;
}

int * subStrMatch(char *_str, char *_subStr)
{
    int * foundPos, foundPosLen, * temp;
    int subStrLen, i, j;
    char * toBeCmp;
    subStrLen = strlen(_subStr);
    foundPos = (int *)malloc(INIT_SIZE*sizeof(int));
    if(foundPos==NULL)
    {
        printf("memory error!\n");
        exit(-1);
    }
    foundPosLen = INIT_SIZE;
    toBeCmp = (char *)calloc(subStrLen+1, sizeof(char));
    if(toBeCmp==NULL)
    {
        printf("memory error!\n");
        exit(-1);
    }
    for(i=0,j=0; _str[i]; i++)
    {
        if(_str[i]==_subStr[0])
        {
            strncpy(toBeCmp, _str+i, subStrLen);
            if(strcmp(toBeCmp, _subStr)==0)
            {
                if(j>=foundPosLen)
                {
                    temp = (int *)realloc(foundPos, (foundPosLen+INCREASE_SIZE)*sizeof(int));
                    if(temp==NULL)
                    {
                        free(foundPos);
                        printf("memory error!\n");
                        exit(-1);
                    }
                    else
                    {
                        foundPos = temp;
                    }
                    foundPosLen += INCREASE_SIZE;
                }
                foundPos[j] = i;
                j++;
            }
        }
    }
    foundPos[j] = -1;
    free(toBeCmp);
    return foundPos;
}