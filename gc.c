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
    for (int k = 1; k < n / 2 + 1; k++)
    {
        for (int i = 2; i < k; i++)
        {
            for (int j = 2; j < 2 * k; j++)
            {
                if (2 * k == i + j && isPrime(i) && isPrime(j))
                {
                    printf("%d=%d+%d\n", 2 * k, i, j);
                }
            }
        }
    }


    return 0;
}