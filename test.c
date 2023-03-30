#include <stdio.h>

int main(void)
{
    int a = 4, b;
    b = (a++) + (++a) + (a * 10);
    printf("a: %d\nb: %d\n", a, b);

    return 0;
}