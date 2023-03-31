#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n);

int main(void)
{

    int l = get_int("Length: ");
    for (int i = 0; i < l; i++)
    {
        if (isPrime(i))
        {
            printf("%d\n", i);
        }
    }
    return 0;
}

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