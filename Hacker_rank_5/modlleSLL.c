
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

struct node* removemidSLL(struct node* head)
{
      if (head == NULL || head->next == NULL) {
        
        free(head);
        return NULL;
    }

    struct node* temp = head;
    int count =0;
    while(temp!= NULL)
    {
        temp= temp->next;
        count++;
    }
    
    
    int location = (count/2);
    temp = head;
    for(int i=1; i<location;i++)
    {
        temp= temp->next;
    }
    struct node* del= temp->next;
    temp->next= del->next;
    free(del);
    
     
    return head;
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

  
 
  head = removemidSLL(head);
  displaySLL();
    return 0;
}
