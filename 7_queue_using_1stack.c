#include<stdio.h>
#include<stdlib.h>

int  stack[25];
int top = -1;

//user function
void push(int  ele)
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

int  pop()
{
    if(top==-1)
    {
        printf("Stack underflow\n");
         printf("\n");
        return -1;

    }
    else{
        int cur = stack[top];
        top--;
        
        return cur;
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
            printf("%d",stack[top]); 
            printf("\n");
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
        printf("%d-",stack[i]);
    }
    printf("\n");
}
}


void insert(int ele)
{
    if(top==-1)
    {
        push(ele);
        return ;
    }

    int cur = pop();
    insert(ele);
    push(cur);
}
void enqueue(int ele)
{
     if(top==24)
    {
        printf("Queue full overflow");
         printf("\n");
        exit;
    }
    else if(top==-1)
    {
        top++;
        stack[top]==ele;
        return;
    }
    else{
        
        insert(ele);

    }
}

void size()
{
    int count=0;
    for(int i=top; i>=0 ; i--)
    {
        count++;

    }
    printf("%d",count);


}

//main funtion
int main()
{
printf("Queue usinf 1 stack operations \n enter operations\n");
int c;
printf("1.enqueue\n 2.dequeue\n 3. peak \n 4.display \n 5. size\n");


while(1)
{

    scanf("%d",&c);
if(c==1)
{printf("enter elemnet");
int ele;
scanf("%d",&ele);
    enqueue(ele);
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
else if(c==5)
{
    size();
}
else 
{
printf("Enter valid operation");
break;
}
}
}