#include<stdio.h>
# define capacity 1000
void Insert_at_Index(int arr[],int *size,int index,int element){
    if(index<0 || index>size){
        printf("Invalid Index");
        return;
    }else if (*size>=capacity){
        printf("Array is full.\n");
        return;
    }
    for (int i = *size-1; i >= index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    (*size)++;
    PrintArray(arr,*size);
}
void PrintArray(int arr[],int size){
    for (int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[capacity]={12,23,45,65,78,94,55};
    int size=7;
    int index,Element_To_Insert;
    printf("Enter index at which you want to insert element: ");
    scanf("%d",&index);
    printf("Enter element to be inserted: ");
    scanf("%d",&Element_To_Insert);
    Insert_at_Index(arr,&size,index,Element_To_Insert);
}