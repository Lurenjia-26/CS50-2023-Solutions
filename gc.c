#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n)
{
    if (n <= 3)
    {
        return (n > 1);
    }
    if (n % 6 != 1 && n % 6 != 5)
    {
        return false;
    }

    int sq = (int)sqrt(n);
    for (int i = 5; i < sq; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i += 2)
    {
        for (int j = 2; j < i; j++)
        {
            int k = i - j;
            if (isPrime(j) && isPrime(k))
            {
                printf("%d=%d+%d\n", i, j, k);
                break;
            }
        }
    }

    return 0;
}