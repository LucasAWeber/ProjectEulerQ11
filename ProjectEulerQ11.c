#include <stdio.h>
#define ADJACENT 4

int main(void)
{
    FILE * fptr = fopen("test.txt", "r");
    int num[20][20];
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            fscanf(fptr, "%d", &num[i][j]);
        }
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            printf("%d", num[i][j]);
        }
    }
}