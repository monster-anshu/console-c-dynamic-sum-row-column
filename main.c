// Code by Himanshu Gunwant
// git hub https://github.com/monster-anshu
#include <stdio.h>
#include <stdlib.h>
int **Mat, *rowSUM, *colSUM, row, col, i, j;
void inputMat()
{
    printf("Enter number of rows : ");
    scanf("%d", &row);
    printf("Enter number of colum : ");
    scanf("%d", &col);

    Mat = (int **)calloc(sizeof(int), row);
    for (i = 0; i < row; i++)
    {
        Mat[i] = (int *)calloc(sizeof(int), col);
    }

    rowSUM = (int *)calloc(sizeof(int), row);
    colSUM = (int *)calloc(sizeof(int), col);

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            fflush(stdin);
            printf("Enter Mat[%d][%d] : ", i + 1, j + 1);
            scanf("%d", &Mat[i][j]);
        }
    }
}

void sumRow()
{
    for (i = 0; i < row; i++)
    {
        rowSUM[i] = 0;
        for (j = 0; j < col; j++)
        {

            rowSUM[i] = rowSUM[i] + Mat[i][j];
        }
    }
}

void sumCol()
{

    for (i = 0; i < col; i++)
    {
        colSUM[i] = 0;
        for (j = 0; j < row; j++)
        {

            colSUM[i] = colSUM[i] + Mat[j][i];
        }
    }
}
void displayMatAndSum()
{
    for (j = 1; j <= col * 11; j++)
    {
        printf("-");
    }
    printf("\n");
    for (i = 0; i < row; i++)
    {
        printf("\t");
        for (j = 0; j < col; j++)
        {
            printf(" %d\t", Mat[i][j]);
        }
        printf("|= %d", rowSUM[i]);
        printf("\n");
        if (i == row - 1)
        {
            for (j = 1; j <= col * 11; j++)
            {
                printf("-");
            }
            printf("\n");
            printf("SUM =\t");
            for (j = 0; j < col; j++)
            {
                printf(" %d \t", colSUM[j]);
            }
        }
    }
}
void main()
{
    inputMat();
    sumRow();
    sumCol();
    displayMatAndSum();
}
