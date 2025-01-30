#include<stdio.h>
#include<stdlib.h>

int  stack[25];
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
        printf("%s-",stack[i]);
    }
    printf("\n");
}
}

void findnearst()
{
    for(int i=0; i<=top;i++)
    {
        int min =stack[i];
        int temp=i;
        
        for(int j=i-1;j>=0;j--)
        {
            if(min>stack[j])
            {
                min= stack[j];
                temp=j;
            }   
        }
        if(temp==i)
        {
            printf("-1 ");
            
        }
        else{
            printf("%d ",min);
        }
    }
}
//main funtion
int main()
{
    int n;
printf("Enter size\n");
scanf("%d",&n);
int ele;
for(int i=0; i<n ; i++)
{
    scanf("%d",&ele);
    push(ele);
}

findnearst();


}
