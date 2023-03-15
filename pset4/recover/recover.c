#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover infile.\n");
        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Not such file.\n");
        return 2;
    }

    uint8_t buffer[4];
    while (fread(buffer, 1, BLOCK_SIZE, raw_file))
    {

    }

    return 0;
}