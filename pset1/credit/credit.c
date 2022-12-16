#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long num = get_long("Number: ");
    int digits = 1;
    bool isValid = false;

    for (long tmp_num = num; tmp_num > 10; digits++)
    {
        tmp_num /= 10;
    }
    if (digits == 13 || digits == 15 || digits == 16)
    {
        //进行

    }
    if (!isValid)
    {
        printf("foo\n");
    }
}