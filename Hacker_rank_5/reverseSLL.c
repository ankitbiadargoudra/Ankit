
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


struct node{
    int value;
    struct node* next;
    
};

struct node* head=NULL;

struct node* createnode(int value)
{
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    newnode->value= value;
    newnode->next = NULL;
    return newnode;
}

void insertatend(int value)
{
    struct node*  newnode= createnode(value);
    if(head==NULL)
    {
        head = newnode;
        return;
        
    }
    struct node* temp =head;
    while(temp->next !=NULL)
    {
        temp= temp->next;
    }
    temp->next= newnode;
    
}

void displaySLL()

{
    struct node* temp=  head;
    if(temp==NULL)
    {
        printf("\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->value);
        
        temp=temp->next;
        
    }
    
}

struct node* reverseSLL(struct node* head)
{
    struct node* prev=NULL;
    struct node* current = head;
    struct node* next= NULL;
    
    while(current !=NULL)
    {
        next = current ->next;
        current ->next= prev;
        prev = current;
        current = next;
        
    }
    return prev;
    
}



int main()
{
   char input[100];
   fgets(input,sizeof(input),stdin);
   char *token;
   token = strtok(input," ");
   int number;
   while(token!= NULL)
   {
       number = atoi(token);
       insertatend(number);
       token = strtok(NULL," ");
   }
 
  head = reverseSLL(head);
   displaySLL();

    return 0;
}
