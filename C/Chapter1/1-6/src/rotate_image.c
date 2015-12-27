#include "rotate_image.h"

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void translate(int **image, int width, int height)
{
    int startCol = 0;

    for(int i = 0; i < height; i++)
    {
        for(int j = startCol; j < width; j++)
        {
            swap(&(image[i][j]), &(image[j][i]));
        }

        startCol++;
    }
}

void rotate_cw_90(int **image, int width, int height)
{
    translate(image, width, height);

    //Swap the first and last column
    for(int i = 0; i < height; i++)
    {
        swap(&(image[i][0]), &(image[i][width - 1]));
    }
}

//Implementation should be modified to support different types of rotation
void rotate_image(int **image, int width, int height)
{
    rotate_cw_90(image, width, height);
}