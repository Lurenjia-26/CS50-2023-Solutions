#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int s(int a[], int l);

int main(void)
{
    time_t t;
    srand(time(&t));

    int a[101], l;
    scanf("%d", &l);

    for (int i = 0; i < l; i++)
    {
        a[i] = rand() % 1000 + 1;
    }

    int cnt = s(a, l);

    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}

int s(int a[], int l)
{
    int min = a[0];
    int cnt = 0;
    for (int i = 0; i < l - 1; i++)
    {
        for (int j = i + 1; j < l; j++)
        {
            if (a[i] >= a[j])
            {
                a[j] += a[i];
                a[i] = a[j] - a[i];
                a[j] -= a[i];
            }
        }
        cnt++;
    }
    for(int i = 1; i < l; i++)
    {
        if ( a[i - 1] == a[i])
        {
            cnt--;
        }
    }

    return cnt;
}