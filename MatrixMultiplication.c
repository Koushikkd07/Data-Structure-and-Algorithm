#include<stdio.h>
void multiply(int arr1[100][100],int arr2[100][100], int row1, int column1, int column2);
int main(){
    int Arr1[100][100],Arr2[100][100]; //Result[100][100];
    int row1,column1,row2,column2;
    printf("Enter the number of rows and columns for the first matrix:\n");
    scanf("%d %d",&row1,&column1);
    printf("Enter the elements of the first matrix:\n");
    for (int i = 0; i < row1; i++){
        for ( int j = 0; j < column1; j++)
        {
            scanf("%d",&Arr1[i][j]);
        }
    }
    printf("First matrix is:\n");
    for (int i = 0; i < row1; i++){
        for (int j = 0; j < column1; j++)
        {
            printf("%d\t",Arr1[i][j]);
        }
        printf("\n");
    }
    printf("\nEnter the number of rows and columns for the second matrix:\n");
    scanf("%d %d",&row2,&column2);
    printf("Enter elements for the second matrix:\n");
    for (int i = 0; i < row2; i++){
        for (int j = 0; j < column2; j++){
            scanf("%d",&Arr2[i][j]);
        }
    }
    printf("Second matrix is:\n");
    for (int i = 0; i < row2; i++){
        for (int j = 0; j < column2; j++)
        {
            printf("%d\t",Arr2[i][j]);
        }
        printf("\n");
    }

    if (column1!=row2)
    {
        printf("Matrix multiplication is not possible");
    }else{
        multiply(Arr1,Arr2,row1,column1,column2);
    }  
}
void multiply(int arr1[100][100],int arr2[100][100], int row1, int column1, int column2){
    int result[100][100];
    for (int i = 0; i < row1; i++){
        for (int j = 0; j < column2; j++){
           for (int k = 0; k < column1; k++)
           {
            result[i][j]+=arr1[i][k]*arr2[k][j];
           }
           
        }
    }

    printf("Final Matrix is:\n");
    for (int i = 0; i < row1; i++){
        for (int j  = 0; j < column2; j++)
        {
            printf("%d\t",result[i][j]);
        }
        printf("\n");
    }   
}