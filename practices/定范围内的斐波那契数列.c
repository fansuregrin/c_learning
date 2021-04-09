#include <stdio.h>

int main(void)
{
    int m, n, temp, f1, f2;
    f1 = 1;
    f2 = 1;
    printf("Input 2 num:");
    scanf("%d%d", &m, &n);
    
    while (1)
    {
        if (f2 >= m)
        {
            break;
        }
        else
        {
            temp = f2;
            f2 = f1 + f2;
            f1 = temp;
        }
    }

    while (1)
    {
        if (f2 > n)
            break;
        else 
            printf("%d ", f2);
        temp = f2;
        f2 = f1 + f2;
        f1 = temp;
        
    }

    return 0;
}