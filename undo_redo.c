#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void push(char *stack, int *top, char val)
{
    (*top)++;
    stack[*top]=val;
}

char pop(char*stack, int *top)
{
    char ele = stack[*top];
    (*top)--;
    return ele;
}


void calfun(char *stack1, int *top1, char *stack2, int *top2)
{
        char ele = pop(stack1, top1);
        push(stack2,top2,ele);
       
}




int main()
{
    char str[100];
    char stack1[100];
    char stack2[100];
    int top1=-1,top2=-1;

    printf("enter the string\n");
    scanf("%[^\n]",str);
    int length= strlen(str);
    for(int i=0; i<length; i++)
    {
        push(stack1,&top1,str[i]);
    }
    while(1)
    {
        char ca;
        int k=0;
        scanf("%c %d",&ca,&k);
        if(ca=='z')
        {
            for(int j=0; j<k ; j++)
            {
            calfun(stack2,&top2,stack1,&top1);
            }
            printf("string: ");
             for(int i=0; i<=top1;i++)
             {
                 printf("%c",stack1[i]);
             }
               printf("\n");
        }
        else if(ca=='y')
        {
             for(int j=0; j<k ; j++)
            {
            calfun(stack1, &top1,stack2,&top2);
            }
             printf("string: ");
             for(int i=0; i<=top1;i++)
             {
                 printf("%c",stack1[i]);
             }
             printf("\n");
        }
        else if(ca=='x')
        {
            printf("exiting\n");
            return 0;
        }
    }
}