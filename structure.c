#include<stdio.h>
struct DOJ{
    int day,month,year;
};
struct employee
{
    char name[100];
    float salary;
    struct DOJ doj;
};

void printdetails(struct employee emp){
  printf("\n Name:%s",emp.name);
  printf("\nDate Of Joining:%02d/%02d/%04d",emp.doj.day,emp.doj.month,emp.doj.year);
  printf("\nSalary is:%.2f",emp.salary);
}



int main(){
    struct employee emp[100];
    int n;
    printf("How much employee's data you want to enter:");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter details for employee %d:\n", i + 1);

        printf("enter name:");
        scanf(" %[^\n]",emp[i].name);

        printf("Enter the date of joining in DD/MM/YYYY format:");
        scanf("%d/%d/%d",&emp[i].doj.day,&emp[i].doj.month,&emp[i].doj.year);

        printf("Enter salary :");
        scanf("%f",&emp[i].salary);
    }

    printf("\n_______________________________________________________________\n");

    for (int i = 0; i <n; i++)
    {
       printf("\n\n Employee %d details:\n",i+1);
       printdetails(emp[i]);

    }
    
    
}