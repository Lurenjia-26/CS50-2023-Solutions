#include <stdio.h>

int s(int a[], int l);

int main(void)
{
    int a[101], l;
    scanf("%d", &l);

    for (int i = 0; i < l; i++)
    {
        scanf("%d", &a[i]);
    }

    int cnt = s(a, l);

    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
    {
        if (a[i])
        {
            printf("%d ",a[i]);
        }
    }

    return 0;
}

int s(int a[], int l)
{
    int min = a[0];
    int cnt = 1;
    for (int i = 0; i < l - 1; i++)
    {
        for (int j = i + 1; j < l; j++)
        {
            if (a[i] == a[j])
            {
                a[i] = 0;
                cnt--;
            }
            else if (a[i] > a[j])
            {
                a[j] += a[i];
                a[i] = a[j] - a[i];
                a[j] -= a[i];
            }
        }
        cnt++;
    }

    return cnt;
}