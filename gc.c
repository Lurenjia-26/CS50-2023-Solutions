#include <stdio.h>

int n;
int s[60] = {0};
int a[60] = {0};

void mul(int t)
{
    int x = 0;
    for (int i = 0; i < 60 i++)
    {
        a[i] = a[i] * t + x;
        x = a[i] / 10;
        a[i] %= 10;
    }
}

void add()
{
    int x = 0;
    a[0] = 1;
    for (int i = 1; i < 60; i++)
    {
        s[i] += a[i] + x;
        x = s[i] / 10;
        s[i] %= 10;
    }
}

int main(void)
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        mud(i);
        add();
    }
    output();

    return 0;
}