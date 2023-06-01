#include <stdio.h>

int main()
{
    char *p = "abcdef";
    p[1] = 'B';
    printf("%s", p);
    return 0;
}