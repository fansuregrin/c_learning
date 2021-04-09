#include <stdio.h>
#include <math.h>

int main(void)
{
    int isPrime(int);
    int n, prm1, prm2, i, temp;
    int twoPrime = 0, selfIsPrime = 0;
    prm1 = 2;
    prm2 = 2;
    printf("Input num:");
    scanf("%d", &n);
    if (n > 2) 
    {
        i = 3;
        do{
            if (isPrime(i))
            {
                temp = prm2;
                prm2 = i;
                prm1 = selfIsPrime ? prm1 : temp;
                if (prm2 == n)
                    selfIsPrime = 1;
                //printf("prm1=%d prm2=%d\n", prm1, prm2);
            }
            i++;
        }while(prm2<=n);
        if (fabs(prm1 - n) == fabs(prm2 - n))
            twoPrime = 1;
        else 
            prm1 = fabs(prm2 - n) < fabs(prm1 - n) ? prm2 : prm1;
    }
    else if (n == 2)
        prm1 = 3;
    if (twoPrime)
        printf("Prime number are %d,%d\n", prm1, prm2);
    else
        printf("Prime number is %d\n", prm1);
    
    return 0;
}

int isPrime(int n)
{
    int i;
    for (i=2; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            return 0;
        }
            
    }
    return 1;
}