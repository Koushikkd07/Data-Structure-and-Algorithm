#include<stdio.h>
# define capacity 1000

void Delete_at_Index(int arr[],int *size,int Index_To_Deletion){
    if (Index_To_Deletion<0 || Index_To_Deletion>=*size)
    {
        printf("Wrong index.\n");
        return;
    }else if (*size==0)
    {
        printf("Array is empty");
        return;
    }
    for (int i = Index_To_Deletion; i < *size; i++)
    {
        arr[i]=arr[i+1];
    }
    (*size)--;
}
void PrintArray(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[capacity]={12,23,45,65,78,94,55};
    int size=7;
    int Index_To_Deletion;
    printf("Enter index at which you want to delete element: ");
    scanf("%d",&Index_To_Deletion);
    printf("Array before deletion:");
    PrintArray(arr,size);
    Delete_at_Index(arr,&size,Index_To_Deletion);
    printf("Array after deletion:");
    PrintArray(arr,size);
}


/*OUTPUT EXAMPLE
Enter index at which you want to delete element: 2
Array before deletion:12 23 45 65 78 94 55
Array after deletion:12 23 65 78 94 55
 */