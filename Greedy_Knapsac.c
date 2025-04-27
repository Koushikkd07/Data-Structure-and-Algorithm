#include<stdio.h>
#include<stdlib.h>
int swap(float *a,float *b){
    float temp=*a;
    *a=*b;
    *b=temp;
}
int swapInt(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int knapsack(int n,int capacity,int w[],int p[]){
    float ratio[n];
    float profit=0;
    for(int i=0;i<n;i++){
        ratio[i]=(float)p[i]/w[i];
    }
    for (int i = 0; i < n; i++){
        for(int j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                swap(&ratio[i],&ratio[j]);
                swapInt(&w[i],&w[j]);
                swapInt(&p[i],&p[j]);
            }
        }
    }
    for (int i = 0; i < n; i++){
       if(capacity==0){
            break;
        } 
        if(capacity>=w[i]){
            printf("Item %d with weight %d and profit %d is included in the knapsack\n",i+1,w[i],p[i]);
            capacity-=w[i];
            profit+=p[i];
        }else{
            printf("Item %d with weight %d and profit %d is partially included in the knapsack\n",i+1,w[i],p[i]);
            profit+=ratio[i]*capacity;
            capacity=0;
        }
    }
    printf("Total profit: %.2f\n",profit);
    printf("Remaining capacity: %d\n",capacity);
    return 0;
}
int main(){
    int n,capacity;
    printf("Enter the number of items: ");
    scanf("%d",&n);
    int w[n],p[n];
    float ratio[n];
    printf("Enter the weights of the items: ");
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    printf("Enter the profits of the items: ");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d",&capacity);
    knapsack(n,capacity,w,p);
    return 0;
}