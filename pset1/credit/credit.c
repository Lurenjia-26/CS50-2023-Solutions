#include <cs50.h>
#include <stdio.h>
#define LENGTH 20

int main(void)
{
    long num, tmp_num;
    int digits = 1;
    int a[LENGTH] = {0};
    int sum = 0;

    do
    {
        num = get_long("Number: ");
    }
    while (num <= 0 || num >= 1e17);

    // 将每一位数储存在数组中
    for (digits = 0, tmp_num = num; tmp_num > 1; digits++)
    {
        a[digits] = tmp_num % 10;
        tmp_num /= 10;
    }

    // 隔一位乘2并求和
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

    // 与未乘的数加起来
    for (int i = 0; i < digits; i += 2)
    {
        sum += a[i];
    }
    
    //有效性判断
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        num /= 1e12;
        if (num >= 4 && num < 5)
        {
            printf("VISA\n");
        }
        else if (num >= 340 && num < 350)
        {
            printf("AMEX\n");
        }
        else if (num >= 370 && num < 380)
        {
            printf("AMEX\n");
        }
        else if (num >= 4000 && num < 5000)
        {
            printf("VISA\n");
        }
        else if (num >= 5100 && num < 5600)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}
