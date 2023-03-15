#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#define BLOCK_SIZE 512;

bool isJPEG(uint8_t *buffer);

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

    FILE *output = NULL;
    uint8_t buffer[BLOCK_SIZE];
    char filename[8];
    int i = 1;
    while (fread(buffer, 1, BLOCK_SIZE, raw_file) == BLOCK_SIZE)
    {
        if (isJPEG(buffer) != true)
        {
            continue;
        }
        if (output != NULL)
        {
            fclose(output);
        }
        sprintf(filename, "03i.jpg", i);
        output = fopen(filenname, "w");
        fwrite(buffer, 1, BLOCK_SIZE, output);
        i++;
    }

    fclose(raw_file);
    fclose(output);

    return 0;
}

bool isJPEG(uint8_t *buffer)
{
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    return false;
}