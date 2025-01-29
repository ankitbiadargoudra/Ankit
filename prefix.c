#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char  stack[25];
int top = -1;

//user function
void push(int ele)
{
    if(top==24)
    {
        printf("Stack overflow");
         printf("\n");
        return;
    }
    else{
        top++;
        stack[top]=ele;
    }
} 

void pop()
{
    if(top==-1)
    {
        printf("Stack underflow\n");
         printf("\n");
        return;

    }
    else{
        top--;
    }
}

void peak()
{
    if(top==-1)
        {
            printf("No elements");
 printf("\n");
        }
        else{
            printf("%d",stack[top]); printf("\n");
        }
}
void display()
{
 if(top==-1)
{
    printf("no elemts");
 printf("\n");
}
else{
    for(int i=top; i>=0;i--)
    {
        printf("%c",stack[i]);
    }
    printf("\n");
}
}


//stack operation over here


int isoperand(char ele)
{
    if((ele>='A' && ele<='Z') || (ele>='a' &&ele<='z'))
    {
        return 1;
    }
    else {
        return 0;
    }
}
//prefix to infix
 void pretoin(char* pre)
 {
    char ele;
    int len = strlen(pre)-1;
    for(int i=len;i>=0;i--)
    {
        ele = pre[i];

        if(isoperand(ele))
        {
            push(ele);
            push(' ');
        }
        else{
           
            for(int j=top-1;j>=0;j--)
            {
                if(stack[j]==' ')
                {
                    
                    stack[j]=ele;
                     break;
                }
            }
        }
    }
    display();
 }

int main()
{
printf("PRefix to infix\nEnter preifx");
char pre[25];
scanf("%s",&pre);

pretoin(pre);



}