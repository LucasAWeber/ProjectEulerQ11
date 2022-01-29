#include <stdio.h>
#define ADJACENT 4
#define LEN 20

int main(void)
{
    FILE * fptr = fopen("test.txt", "r");
    int num[LEN][LEN];
    int maxProduct = 0;
    int curProduct = 0;

    // reads to array
    for (int i = 0; i < LEN; i++)
    {
        for (int j = 0; j < LEN; j++)
        {
            fscanf(fptr, "%d", &num[i][j]);
        }
    }

    // prints array
    for (int i = 0; i < LEN; i++)
    {
        for (int j = 0; j < LEN; j++)
        {
            printf("%d ", num[i][j]);
        }
        printf("\n");
    }

    // reads product of 4 horizontal adjacent nums
    for (int i = 0; i < LEN; i++)
    {
        for (int j = 0; j < LEN-3; j++)
        {
            curProduct = num[i][j] * num[i][j+1] * num[i][j+2] * num[i][j+3];
            if (maxProduct < curProduct)
            {
                maxProduct = curProduct;
            }
        }
    }

    // reads product of 4 vertical adjacent nums
    for (int i = 0; i < LEN; i++)
    {
        for (int j = 0; j < LEN-3; j++)
        {
            curProduct = num[j][i] * num[j+1][i] * num[j+2][i] * num[j+3][i];
            if (maxProduct < curProduct)
            {
                maxProduct = curProduct;
            }
        }
    }

    // reads product of 4 diagonal left to right
    for (int i = 0; i < LEN-3; i++)
    {
        for (int j = 0; j < LEN-3; j++)
        {
            curProduct = num[i][j] * num[i+1][j+1] * num[i+2][j+2] * num[i+3][j+3];
            if (maxProduct < curProduct)
            {
                maxProduct = curProduct;
            }
        }
    }

    // reads product of 4 diagonal right to left
    for (int i = 3; i < LEN; i++)
    {
        for (int j = 3; j < LEN; j++)
        {
            curProduct = num[i][j] * num[i+1][j-1] * num[i+2][j-2] * num[i+3][j-3];
            if (maxProduct < curProduct)
            {
                maxProduct = curProduct;
            }
        }
    }

    printf("%d\n", maxProduct);

    return 0;
}