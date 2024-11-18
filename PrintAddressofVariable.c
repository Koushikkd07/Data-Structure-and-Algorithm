#include<stdio.h>
int main(){
    int a;
    char c;
    float p;
    a=5;
    c='a';
    p=5.1;

    printf("%d is stored at the address:%u\n",a,&a);
    printf("%c is stored at the address:%u\n",c,&c);
    printf("%f is stored at address :%u\n",p,&p);

}