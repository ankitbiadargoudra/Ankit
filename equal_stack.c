#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
// stackes
int stack1[100],stack2[100],stack3[100],tempstack[100];
int top1=-1, top2=-1, top3=-1,toptemp=-1;
int size1=0, size2=0, size3=0, min_size=INT_MAX;


int  isempty(int *stack, int *top)
{
    return *top==-1;
}

void push(int* stack, int *top, int ele)
{
    (*top)++;
    stack[*top] = ele;
}

int  pop(int * stack, int *top)
{
    int temp = stack[*top];
    (*top)--;
     return temp;
}

void display(int *stack, int top)
{
    for(int i=top; i>=0; i--)
    {
        printf("%d ",stack[i]);
    }
    printf("\n");
}
void atbottom(int * stack, int *top, int ele)
{
    if(*top==-1)
    {
        (*top)++;
        stack[*top]=ele;
    }
    else{
        while(!isempty(stack,top))
        {
                int cur = pop(stack,top);
                push(tempstack,&toptemp,cur);

        }
        push(stack,top,ele);
        while(!isempty(tempstack,&toptemp))
        {
            int cur = pop(tempstack,&toptemp);
            push(stack,top,cur);
        }   

    }
}

int size(int *stack , int top)
{
    int sum=0;
    for(int i=top; i>=0; i--)
    {
        sum += stack[i];
    }
    return sum;
}

int  getmin(int a, int b , int c)
{
    int temp = (a<b)?a:b;
    int min = (temp<c)?temp:c;

    return min;
}

int main()
{
    printf("\nEnter\n");
    int a , b, c,num;
    scanf("%d %d %d",&a,&b,&c);
    for(int i=0; i< a ;i++)
    {
        scanf("%d",&num);
        atbottom(stack1,&top1,num);
    }
     for(int i=0; i< b ;i++)
    {
        scanf("%d",&num);
          atbottom(stack2,&top2,num);
    }
     for(int i=0; i< c ;i++)
    {
        scanf("%d",&num);
          atbottom(stack3,&top3,num);
    }
    

    display(stack1,top1);
    display(stack2,top2);
    display(stack3,top3);
    printf("\n");
    size1= size(stack1,top1);
    size2= size(stack2,top2);
    size3= size(stack3,top3);

    min_size= getmin(size1,size2,size3);

    while(!(size1==size2 && size2==size3))
    {
        int flag=0;
        if(size1>min_size)
        {
            int temp = pop(stack1,&top1);
            flag++;
        }
        if(size2>min_size)
        {
            int temp = pop(stack2, &top2);
            flag++;
        }
        if(size3>min_size)
        {
            int temp = pop(stack3, &top3);
            flag++;
        }
        size1= size(stack1,top1);
         size2= size(stack2,top2);
        size3= size(stack3,top3);

        
        min_size= getmin(size1,size2,size3);
        
        if(flag==0)
        {
            break;
        }
    }

    printf("\n   ---%d----\n",size1);
}