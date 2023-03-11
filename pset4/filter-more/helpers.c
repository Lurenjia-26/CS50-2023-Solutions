#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avgrgb = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = avgrgb;
            image[i][j].rgbtGreen = avgrgb;
            image[i][j].rgbtBlue = avgrgb;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double k = 0;
            int sum_red = 0, sum_green = 0, sum_blue = 0;

            for (int row = -1; row < 1; row++)
            {
                for (int col = -1; col < 1; col++)
                {
                    if (i + row < 0 || i + row > height - 1)
                    {
                        continue;
                    }
                    if (j + col < 0 || j + col > width - 1)
                    {
                        continue;
                    }

                    k++;
                    sum_red += image[i + row][j + col].rgbtRed;
                    sum_green += image[i + row][j + col].rgbtGreen;
                    sum_blue += image[i + row][j + col].rgbtBlue;
                }
            }

            temp[i][j].rgbtRed = round(sum_red / k);
            temp[i][j].rgbtGreen = round(sum_green / k);
            temp[i][j].rgbtBlue = round(sum_blue / k);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE Gx, Gy;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double k = 0;

            for (int row = -1; row < 1; row++)
            {
                for (int col = -1; col < 1; col++)
                {
                    if (i + row < 0 || i + row > height - 1)
                    {
                        k++;
                        continue;
                    }
                    if (j + col < 0 || j + col > width - 1)
                    {
                        k++;
                        continue;
                    }
                }
            }
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            image[i][j] = temp[i][j];
        }
    }
    return;
}
