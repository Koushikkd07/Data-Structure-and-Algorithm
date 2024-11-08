#include<stdio.h>
#include<conio.h>
int main(){
    int Arr1[10][10];
    int n;
    printf("Enter the number of rows and columns of the matrix:\n");
    scanf("%d",&n);
    printf("Enter the elements of the matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&Arr1[i][j]);
        }
    }

    printf("\nyour array is:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",Arr1[i][j]);
        }
        printf("\n");
    }

    printf("\nTranspose matrix is:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",Arr1[j][i]);
        }
        printf("\n");
    }

}