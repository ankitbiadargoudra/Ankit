#include<stdlib.h>
#include<stdio.h>

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

void insertatabeg(int value)
{
    struct node* newnode=  createnode(value);
    newnode->next = head;
    head = newnode;
}

void insertatpos(int value,int position)
{
    if(position<0)
    {
        printf("invalid");
        return;
    }
    if(position==1)
    {
        insertatabeg(value);
        return;
    }
    struct node* newnode= createnode(value);
    struct node* temp=head;
    for(int i=1;i<position-1&& temp!=NULL;i++)
    {
        temp= temp->next;
    }
    if (temp==NULL)
    {
        printf("invalid position");
        free(newnode);
        return;
    }
    newnode->next= temp->next;
    temp->next= newnode;
    
}

void updateatpos(int value, int postion)
{
    if(postion<1)
    {
        printf("invalid");
        return;
    }
    struct node* temp = head;
    for(int i=1; i< postion-1&& temp!=NULL;i++)
    {
        temp = temp->next;
    }
    
    if(temp==  NULL)
    {
        printf("Invalid position");
        return;
    }
    
    temp->next->value = value;
}

void deleteatbeg(){
    if(head ==NULL)
    {
        printf("invalid position");
        return;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    
}

void deleteatend()
{
    if(head ==NULL)
    {
        printf("Invalid position");
        return;
    }
    if(head->next ==NULL)
    {
        free(head);
        head->next=NULL;
        return;
    }
    struct node* temp = head;
    while(temp->next->next!=NULL)
    {
        temp= temp->next;
    }
     
     free(temp->next);
     temp->next=NULL;
    
}

void deleteatpos(int position)
{
    if(position<1|| head==NULL)
    {
        printf("invalid position");
        return;
        
    }
    
    if(position==1)
    {
        deleteatbeg();
        return;
        
    }
    struct node* temp = head;
    for(int i=1; i< position-1&& temp!=NULL;i++)
    {
        temp= temp->next;
    }
    if(temp==NULL || temp->next ==NULL)
    {
     printf("invalid position");
     return;
    }
    struct node* delnode= temp->next;
    temp->next = delnode->next;
    free(delnode);
    
    
    
}


void display()

{
    struct node* temp=  head;
    if(temp==NULL)
    {
        printf("\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d->",temp->value);
        
        temp=temp->next;
        
    }
    printf("\n");
}

int main()
{
    int operations;
    scanf("%d",&operations);
    for(int op=0; op<operations; op++)
    {
        int operand,value,position;
        scanf("%d",&operand);
        switch(operand)
        {
            case 1:
            scanf("%d",&value);
            insertatend(value);
            break;
            
            case 2:
            scanf("%d",&value);
            insertatabeg(value);
            break;
            
            case 3:
            scanf("%d %d",&position,&value);
            insertatpos(value,position);
            break;
            
            case 4:
            display();
            break;
            
            case 5:
            scanf("%d %d",&position,&value);
            updateatpos(value,position);
            break;
            
            case 6:
            deleteatbeg();
            break;
            
            case 7:
            deleteatend();
            break;
            
            case 8:
            scanf("%d",&position);
            deleteatpos(position);
            break;
            
            default:
            printf("invalid");
            break;
        }
        
    }

    return 0;
}