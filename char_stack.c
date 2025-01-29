#include<stdio.h>
#include<stdlib.h>

char  stack[25];
int top = -1;

//user function
void push(char* ele)
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
            printf("%s",stack[top]); printf("\n");
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
        printf("%s-",stack[i]);
    }
    printf("\n");
}


}
//main funtion
int main()
{
printf("stack operations \n enter operations\n");
int c;


while(1)
{

    scanf("%d",&c);
if(c==1)
{printf("enter elemnet");
char ele[5];
scanf("%s",&ele);
    push(ele);
}
else if(c==2)
{
    pop();
}
else if(c==3)
{
    peak();
}
else if(c==4)
{
    display();
}
else 
{
printf("Enter valid operation");
break;
}
}
}