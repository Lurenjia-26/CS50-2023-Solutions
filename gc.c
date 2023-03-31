#include <stdio.h>
#include <stdbool.h>
#include <math.h>

unsigned long long f(int n)
{
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }

    return result;
}

void sf(int n)
{
    unsigned long long sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += f(n);
    }
    printf("%lld", sum);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    sf(n);

    return 0;
}