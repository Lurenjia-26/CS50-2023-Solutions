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
    for (int k = 2; k <= n; k += 2)
    {
        for (int i = 2; i < k / 2; i++)
        {
            for (int j = 2; j < k; j++)
            {
                if (k == i + j && isPrime(i) && isPrime(j))
                {
                    printf("%d=%d+%d\n", k, i, j);
                    break;
                }
            }
        }
    }


    return 0;
}