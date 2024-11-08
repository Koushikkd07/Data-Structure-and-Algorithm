#include<stdio.h>
#define ROWS 5
#define COLS 5

int main()
{
    int row,column,product[ROWS][COLS];
    int i,j;
    printf("    ");
    for (j=1;j<=COLS;j++){
        printf("%4d",j);       // Print column headers
    }
    //printf("\n");
    printf("\n_______________________________________\n");
    for (i=0;i<ROWS;i++)
    {
        row=i+1;
        printf("%2d |",row);            // Print row header
        for (j=1;j<=COLS;j++){
            column=j;
            product[i][j]=row*column;
            printf("%4d",product[i][j]);
            }
            printf("\n");
        }

    }
