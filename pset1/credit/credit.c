#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long num, tmp_num;
    int digits = 1;
    int a[20] = { 0 };
    bool isValid = false;

    // do
    // {
        num = get_long("Number: ");

        //算出位数
        for (tmp_num = num; tmp_num > 10; digits++)
        {
            tmp_num /= 10;
        }

        if (digits == 13 || digits == 15 || digits == 16)
        {
            //如果位数有效，则进行更精确的号码真伪识别
            for (digits = 1, tmp_num = num; tmp_num > 10; digits++)
            {
                a[20 - digits] = tmp_num % 10;
                tmp_num /= 10;
            }
        }
        for (int i = 19; i > 0; i--)
        {
            printf("%d", a[i]);
        }
        if (!isValid)
        {
            printf("foo\n");
        }
    // }
    // while (!isValid);
}