
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

struct node* removenode(struct node* head, int k)
{
    struct node* temp= head;
    
    int pos =1;
    if(k==1)
    {
        while(temp->next!=NULL)
        {
        struct node* del = temp;
        temp = temp->next;
        free(del);
        }
        
        return NULL;
    }
    while(temp!=NULL&& pos<k)
    {
        if(pos+1==k)
        {
            struct node* del = NULL;
            del = temp->next;
            temp->next = temp->next->next;
            free(del);
            pos=1;
            temp= temp->next;
        }
        else{
        
        temp = temp->next;
         pos++;
        }
       
    }
    return head;
}

int main()
{
   char input[100];
   fgets(input,sizeof(input),stdin);
   int k;
   scanf("%d",&k);
   char *token;
   token = strtok(input," ");
   int number;
   while(token!= NULL)
   {
       number = atoi(token);
       insertatend(number);
       token = strtok(NULL," ");
   }

  
 
 
 
  head = removenode(head,k );
  displaySLL();
    
}
