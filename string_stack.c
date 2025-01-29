#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX][MAX];
int top = -1;


void push(char *str) {
    if (top < MAX - 1) {
        top++;
        strcpy(stack[top], str);
    }
}


void  pop() {
    if (top >= 0) {
        printf("poped elemenet:%s\n",stack[top]);
        stack[top--];
    }
    else{
        printf("no string left\n");
    }
}
void peak()
{
    if (top >= 0) {
        printf("peak elemenet:%s\n",stack[top]);
        
    }
    else{
        printf("no string left\n");
    }
}

void display()
{
    for(int i=top;i>=0;i--)
    {
        printf("%s",stack[i]);
    }
}

//main function

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
char ele[20];
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