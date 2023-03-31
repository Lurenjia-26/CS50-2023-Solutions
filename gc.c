#include <stdio.h>

void f(int *a, int n)
{
    for (int i = 1; i < 60; i++)
    {
        
    }

    return;
}

void sf(int n)
{
    int sum[60] = {-1};
    int a[60] = {0};

    for (int i = 1; i < 60; i++)
    {
        f(i);
    }

    for (int i = 0; i < 60; i++)
    {
        if (sum[i] != -1)
        {
            printf("%d",sum[i]);
        }
    }

    return;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    sf(n);

    return 0;
}