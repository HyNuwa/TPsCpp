#include <omp.h>
#include "stdio.h"
int main()
{
    int TAM = 50;
    int i, j, k;
    long double matrix1[TAM][TAM];
    long double matrix2[TAM][TAM];
    double matrix3[TAM][TAM];
    /* asignamos valores a las las matrices */
    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            matrix1[i][j] = (double)i * j;
            matrix2[i][j] = (double)i - j;
            matrix3[i][j] = (double)0;
        }
    }
#pragma omp parallel for schedule(static) private(i, j, k)
    for (i = 0; i < TAM; i++)
    {
        for (j = 0; j < TAM; j++)
        {
            for (k = 0; k < TAM; k++)
            {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
