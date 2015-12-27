// Nathan Sosnovske
// Cracking the Coding Interview (5th ed)
// Question 1-7
//
// Algorithm that writes zeros to all rows and cols if an element in those rows/cols has a 0

#include "zero_matrix.h"

void print_matrix(int **image, int width, int height)
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            printf("%d ", image[i][j]);
        }

        printf("\n");
    }
    printf("\n\n");
}

int main()
{
    int **image = malloc(3 * sizeof(int*));

    for(int i = 0; i < 3; i++)
    {
        *(image+i) = malloc(3 * sizeof(int*));
    }

    image[0][0] = 1;
    image[0][1] = 2;
    image[0][2] = 3;
    image[1][0] = 4;
    image[1][1] = 5;
    image[1][2] = 0;
    image[2][0] = 7;
    image[2][1] = 8;
    image[2][2] = 9;

    print_matrix(image, 3, 3);
    zero_matrix(image, 3, 3);
    print_matrix(image, 3, 3);

}