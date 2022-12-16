#include <cs50.h>
#include <stdio.h>
#define LENGTH 20

int main(void)
{
    double num, tmp_num;
    int digits;
    double a[LENGTH] = {0};
    int sum = 0;

    do
    {
        num = get_double("Number: ");
    } while (num <= 0 || num >= 1e17);

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
        if (num >= 4e13 && num < 5e13)
        {
            printf("VISA\n");
        }
        else if (num >= 3.4e15 && num < 3.5e15)
        {
            printf("America Express\n");
        }
        else if (num >= 3.7e15 && num < 3.8e15)
        {
            printf("America Express\n");
        }
        else if (num >= 4e16 && num < 5e16)
        {
            printf("VISA\n");
        }
        else if (num >= 5.1e16 && num < 5.6e16)
        {
            printf("MarsterCard\n");
        }
    }
}