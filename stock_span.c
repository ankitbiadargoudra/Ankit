#include<stdio.h>
#include<stdlib.h>

void push(int num,int *top, int stack[])
{
    (*top)++;
    stack[*top]=num;

}

int getspan(int stack[], int top)
{
    int cur = stack[top];
    int n= top;
    int count=0;
    while(cur>=stack[n]&& n!=-1)
    {
        count++;
        n--;
    }
    return count;
}
void stockspan(int stack[], int top)
{
    printf("start stockspan\n");
    int stack2[25], top2=-1;
    while(top!=-1)
    {   
        int temp = getspan(stack,top);
        push(temp,&top2,stack2);
       
        top--;
    }
    while (top2!=-1)
    {
        printf("%d--",stack2[top2]);
        top2--;
    }
    printf("\n");
printf("END stockspan\n");
}


int main()
{
    int stack[25],top=-1;
    printf("enter size\n");
    int n;
    scanf("%d",&n);
    for(int i=0; i<n ;i++)
    {
        int num ;
        scanf("%d",&num);
        push(num,&top,stack);
    }
     
    stockspan(stack,top);

}