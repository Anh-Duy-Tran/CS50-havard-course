#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int dx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    int gx[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int gy[9] = {-1, 0, -2, 0, 0, 0, 1, 0, 2};

    RGBTRIPLE edged_image[height][width];
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            edged_image[i][j] = image[i][j];

    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            int sumGx[3] = {0, 0, 0};
            int sumGy[3] = {0, 0, 0};

            for (int x = 0; x < 9; x++)
            {
                sumGx[0] += image[i + dx[x]][j + dy[x]].rgbtRed * gx[x];
                sumGx[1] += image[i + dx[x]][j + dy[x]].rgbtGreen * gx[x];
                sumGx[2] += image[i + dx[x]][j + dy[x]].rgbtBlue * gx[x];

                sumGy[0] += image[i + dx[x]][j + dy[x]].rgbtRed * gy[x];
                sumGy[1] += image[i + dx[x]][j + dy[x]].rgbtGreen * gy[x];
                sumGy[2] += image[i + dx[x]][j + dy[x]].rgbtBlue * gy[x];

                int temp[3];
                for (int k = 0; k < 3; k++)
                    {
                        temp[k] = sqrt(sumGx[k]*sumGx[k] + sumGy[k]*sumGy[k]);
                        if (temp[k] > 255)
                            temp[k] = 255;
                    }

                edged_image[i][j].rgbtRed = temp[0];
                edged_image[i][j].rgbtGreen = temp[1];
                edged_image[i][j].rgbtBlue = temp[2];
            }

        }
    }

    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            image[i][j] = edged_image[i][j];

    return;
}
