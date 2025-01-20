
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
    if (head == NULL ) 
        return head;
    
    
    struct node*temp = head;
    struct node* prev = NULL;
    while(temp!=NULL)
    {
        if(temp->value == k)
        {
            struct node* del = temp;
            if(prev!=NULL)
            {
                prev->next = temp->next;
                
                
            }
            else{
                head = temp->next;
            }
            temp= temp->next;
            free(del);
        }
        else{
            prev=temp;
            temp=temp->next;
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
