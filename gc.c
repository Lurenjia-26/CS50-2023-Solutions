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

int main(void)
{
    scanf("%d", &n);
    output();

    return 0;
}