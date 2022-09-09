#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
            {
                BYTE tmp;
                tmp = (image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtRed) / 3;
                image[i][j].rgbtBlue = tmp;
                image[i][j].rgbtGreen = tmp;
                image[i][j].rgbtRed = tmp;
            }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
    //sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
    //sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sRed, sGreen, sBlue;
            sRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            sGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            sBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

            if (sRed > 255)
                sRed = 255;
            if (sGreen > 255)
                sGreen = 255;
            if (sBlue > 255)
                sBlue = 255;
            
            image[i][j].rgbtRed = sRed;
            image[i][j].rgbtGreen = sGreen;
            image[i][j].rgbtBlue = sBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - j];
            image[i][width - j] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int ofsX[8] = { 1, 1, 1,  0, 0, -1, -1, -1};
    int ofsY[8] = {-1, 0, 1, -1, 1, -1,  0,  1};

    RGBTRIPLE blured[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0, sumGreen = 0, sumBlue = 0, count = 0;
            for (int d = 0; d < 8; d++)
                {
                    int x = i + ofsX[d];
                    int y = j + ofsY[d];
                    if (x < 0 || x >= height || y < 0 || y >= width)
                        continue;
                    sumRed += image[x][y].rgbtRed;
                    sumGreen += image[x][y].rgbtGreen;
                    sumBlue += image[x][y].rgbtBlue;
                    count++;
                }
            blured[i][j].rgbtRed = sumRed / count;
            blured[i][j].rgbtGreen = sumGreen / count;
            blured[i][j].rgbtBlue = sumBlue / count;
        }
    }

    for (int i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            image[i][j] = blured[i][j];

    return;
}
