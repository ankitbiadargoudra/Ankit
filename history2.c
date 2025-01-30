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
        printf("peak url:%s\n",stack[top]);
        
    }
    else{
        printf("no string left\n");
    }
}

void display()
{
    for(int i=top;i>=0;i--)
    {
        printf("%d: %s",top-i+12,stack[i]);
    }
}

void update(int c , char*newurl)
{
    int i = top-c+1;
   strcpy(stack[c],newurl);
}


void deleteall()
{
    for(int i=top;i>=0;i++)
    {
        strcpy(stack[i],"");
    }
}
//main funtion
int main()
{
printf("history management system \n enter operations  : \n");
int choice,op;
printf("Enter number of operations\n");
scanf("%d",&op);
    while(1) {
        printf("Choose the number:\n 1. Add a website\n 2. View history\n 3. Edit URL\n 4. Remove website\n 5. View recent\n 6. Exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter URL: ");
            char url[50];
            scanf("%s", url);  
            push(url);        
        }
        else if (choice == 2) {
            display();  
        }
        else if (choice == 3) {
            display(); 
            printf("Choose URL to change: ");
            int c;
            char newurl[50];
            scanf("%d", &c); 
            printf("Enter new URL: ");
            scanf("%s", newurl);  
            update(c, newurl);   
        }
        else if (choice == 4) {
            pop(); 
        }
        else if (choice == 5) {
            deleteall();  
        }
        else if (choice == 6) {
            peak();  
        }
        else {
            printf("Exiting...\n");
            break;  
        }
        
    }


}
