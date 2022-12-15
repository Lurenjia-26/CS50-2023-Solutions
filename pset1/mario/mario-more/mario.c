#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h = get_int("Height:");

    for (int i = 0; i < h; i++)
    {
        for(int j = 0; j < h; j++)
        {
            if (j < h - i - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}