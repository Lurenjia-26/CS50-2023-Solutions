#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover infile.\n");
        return 1;
    }

    FILE *input = fopen(argv[1], 'r');

    return 0;
}