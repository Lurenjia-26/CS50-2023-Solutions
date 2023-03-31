#include <stdio.h>

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
    for (int i = 1; i <= n; i++)
    {
        sum += f(i);
    }
    printf("%llu\n", sum);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    sf(n);

    return 0;
}