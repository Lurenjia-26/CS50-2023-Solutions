#include <stdio.h>

int n;
int s[101] = {0};
int a[101] = {0};

void mul(int t)
{
    for (int i = 0; i < 100; i++)
    {
        a[i] *= t;
        if(a[i] > 9)
        {
            a[i + 1] += s[i] / 10;
            a[i] %= 10;
        }
    }
}

void add()
{
    for (int i = 0; i < 100; i++)
    {
        s[i] += a[i];
        if(s[i] > 9)
        {
            s[i + 1] += s[i] / 10;
            s[i] %= 10;
        }
    }
}

void output()
{
    int i;
    for (i = 100; i >= 0; i--)
    {
        if(s[i] != 0)
            break;
    }
    for (int j = i; j >= 0; j--)
    {
        printf("%d", s[j]);
    }
}

int main(void)
{
    scanf("%d", &n);
    a[0] = 1;
    s[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        mul(i);
        add();
    }
    output();

    return 0;
}