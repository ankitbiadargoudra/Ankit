#include<stdio.h>
#include<stdlib.h>
int toptemp=-1, tempstack[100];
//
int stack1[100],stack2[100], top1=-1, top2=-1;


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
void addbottom(int * stack, int *top, int ele)
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
        toptemp=-1;

    }
}

int  solve(int * stack1, int * stack2, int *top1, int* top2, int max)
{
    int sum =0, temp, count=0;
    while(sum <max)
    {
        if(stack1[*top1]<stack2[*top2])
        {
            temp= pop(stack1, top1);
        }
        else{
                 temp= pop(stack2, top2);
        }
        if((sum+temp)>max)
        {
            break;
        }
        count++;
        sum = sum + temp;
    }
    return count;


}

int main()
{
    int t, first=1;
    scanf("%d",&t);
    for(int q=0; q<t; q++)
    {
    int n, m, max, top1=-1, top2=-1;
    scanf("%d %d %d",&n,&m,&max);
        
        stack1[n], stack2[m];
        for(int i=0; i<n ; i++)
        {
            int num;
            scanf("%d",&num);
            addbottom(stack1,&top1,num);
        }
        for(int i=0; i<m ; i++)
        {
            int num;
            scanf("%d",&num);
            addbottom(stack2,&top2,num);
        }

        

        

   int ans =  solve(stack1,stack2,&top1,&top2,max);
   top1=-1; top2=-1;
    printf("%d",ans);
        
    }
}