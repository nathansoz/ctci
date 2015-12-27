#include "zero_matrix.h"

void zero_matrix(int **matrix, int width, int height)
{

    int colsToZero[width * height];
    int rowsToZero[width * height];
    int numColsToZero = 0;
    int numRowsToZero = 0;

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(matrix[i][j] == 0)
            {
                rowsToZero[numRowsToZero++] = i;
                colsToZero[numColsToZero++] = j;
            }
        }
    }

    for(int i = 0; i < numColsToZero; i++)
    {
        int colToZero = colsToZero[i];
        for(int j = 0; j < height; j++)
        {
            matrix[j][colToZero] = 0;
        }
    }

    for(int i = 0; i < numRowsToZero; i++)
    {
        int rowToZero = rowsToZero[i];
        for(int j = 0; j < width; j++)
        {
            matrix[rowToZero][j] = 0;
        }
    }
}