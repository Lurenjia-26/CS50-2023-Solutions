#include <cs50.h>
#include <stdio.h>
#define LENGTH 20

int main(void)
{
    long num, tmp_num;
    int digits = 1;
    int a[LENGTH] = { 0 };
    bool isValid = false;

    do
    {
        num = get_long("Number: ");

        //算出位数
        for (tmp_num = num; tmp_num > 10; digits++)
        {
            tmp_num /= 10;
        }

        //如果位数有效，则进行更精确的号码真伪识别
        if (digits == 13 || digits == 15 || digits == 16)
        {
            //将每一位数储存在数组中
            for (digits = 1, tmp_num = num; tmp_num > 10; digits++)
            {
                a[LENGTH - digits] = tmp_num % 10;
                tmp_num /= 10;
            }
            //求和
            for (int i = LENGTH - 2; i > LENGTH -1 - digits; i -= 2)
            {
                
            }
        }
        if (!isValid)
        {
            printf("foo\n");
        }
    }
    while (!isValid);
}