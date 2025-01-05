#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }else{
        return 0;
    }
}
int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }else{
        return 0;
    }
}
int push(struct stack *ptr,int data){
    if(isFull(ptr)){
        printf("Stack Overflow\n");
        return -1;
    }else{
        ptr->top++;
        ptr->arr[ptr->top]=data;
        return;
    }
}
int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("stack is empty.\n");
        return -1;
    }else{
        int data=ptr->arr[ptr->top];
        ptr->top--;
        return data;
    }
}
int peek(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is empty.\n");
        return -1;
    }else{
        int data=ptr->arr[ptr->top];
        return data;
    }
}
int display(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is empty.\n");
        return -1;
    }else{
        for(int i=ptr->top;i>=0;i--){
            printf("%d ",ptr->arr[i]);
        }
    }
}
int main() {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));  // Allocate memory for struct stack

    printf("Enter the size of the stack: ");
    scanf("%d", &s->size);

    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));  // Allocate memory for stack array

    int choice = 0, data;
    while (choice != 5) {
        printf("\nMenu:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(s, data);
                break;
            case 2:
                data = pop(s);
                if (data != -1) {
                    printf("Popped element: %d\n", data);
                }
                break;
            case 3:
                data = peek(s);
                if (data != -1) {
                    printf("Top element: %d\n", data);
                }
                break;
            case 4:
                display(s);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    free(s->arr);  // Free memory for stack array
    free(s);       // Free memory for struct stack
    return 0;
}