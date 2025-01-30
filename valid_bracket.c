#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char ele) {
    if (top < MAX - 1) {
        top++;
        stack[top]=ele;
    }
}


char* pop() {
    if (top >= 0) {
         stack[top--];
    }
    else{
        printf("no  left\n");
    }
}
void display()
{
    for(int i=top;i>=0;i--)
    {
        printf("%c",stack[i]);
    }
}


void solve(char* input)
{
    int length = strlen(input);
    int flag=0;
    for(int i=0; i<length;i++)
    {
        
        char ele= input[i];
        if(ele=='('||ele=='{'||ele=='[')
        {
            push(ele);
        }
        else{
            if((ele==')' && stack[top]=='(' ) || (ele=='}' && stack[top]=='{') ||  (ele==']' && stack[top]=='['))
            {
                    pop();
            }
            else{
                flag==1;
                printf("flase");
                return;
            }

        }
    }
    if(flag==0)
    {
    printf("True");
    return;
    }
}

int main() {
    char input[MAX];

   
    printf("Enter input\n: ");
    scanf("%s", input);

    
    solve(input);
    return 0;
}
