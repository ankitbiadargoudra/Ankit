#include<stdio.h>
#include<stdlib.h>

int stack[100];
int top=-1;

void push(int stack[], int *top,int ele)
{
    (*top)++;
    stack[*top]=ele;
}

int pop(int stack[],int *top )
{
    if(*top==-1)
    {
        return -1;
    }
    else{
        int ele = stack[*top];
        (*top)--;
        return ele;
    }
}

int peek(int stack[],int top)
{
    int ele = stack[top];
    return ele;
}
int sizestack(int stack[], int top)
{
    int count=0;
    while(top>=0)
    {
        top--;
        count++;
    }
    return count;
}

void isempty(int sack[], int top)
{
    if(top==-1)
    {
        printf("True\n");
    }
    else{
        printf("False\n");
    }

}

void insert(int stack[], int*top, int ele)
{
    if(*top==-1)
    {
        push(stack,top,ele);
        return;
    }
    int poped= pop(stack,top);
    insert(stack,top,ele);
    push(stack,top,poped);
}
int main()
{
int n ;
scanf("%d",&n);
for(int i=0; i<n ; i++)
{
    int choice,ele,size;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        scanf("%d",&ele);
        insert(stack,&top,ele);
        break;

        case 2:
        ele = pop(stack,&top);
        if(ele==-1)
        {
            printf("None\n");
        }
        else{
            printf("%d",ele);
        }
        break;

        case 3:
        ele = peek(stack,top);
        if(ele==-1)
        {
            printf("None\n");
        }
        else{
            printf("%d",ele);
        }
        break;

        case 4:
        isempty(stack, top);
        break;

        case 5:
        size = sizestack(stack, top);
        printf("%d",size);
        break;

        default:
        printf("Enter valis number\n");
        break;

    }
}
}
