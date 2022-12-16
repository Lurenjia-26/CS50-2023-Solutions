#include <cs50.h>
#include <stdio.h>
#define LENGTH 20

int main(void)
{
    long num, tmp_num;
    int digits = 1;
    int a[LENGTH] = { 0 };
    int sum = 0;
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
            for (digits = 0, tmp_num = num; tmp_num > 1; digits++)
            {
                a[digits] = tmp_num % 10;
                tmp_num /= 10;
            }
            //隔一位乘2并求和
            for (int i = 1; i < digits; i += 2)
            {
                if (a[i] < 5)
                {
                    sum += a[i] * 2;
                }
                else
                {
                    sum += a[i] / 5 + (a[i] * 2) % 10;
                }
            }
            //与未乘的数加起来
            for (int i = 0; i < digits; i += 2)
            {
                sum += a[i];
            }
            if (sum % 10 == 0)
            {
                isValid = true;
            }
        }
        if (!isValid)
        {
            printf("foo\n");
        }
    }
    while (!isValid);
    
}