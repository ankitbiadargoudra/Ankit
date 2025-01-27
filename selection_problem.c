#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int value;
	struct node * next;
};

struct node* head1 = NULL;

struct node* head2 = NULL;

struct node* createnode(int value)
{
	struct node* newnode = (struct node*)malloc( sizeof(struct node));
	newnode->value= value;
	newnode->next = NULL;
	return newnode;
}

void insertatend( struct node**head, int value)
{
	struct node* newnode= createnode(value);
	if(*head==NULL)
	{
		*head = newnode;
		return;
	}
	struct node* temp = *head;

	while(temp->next !=NULL)
	{
		temp= temp->next;
	}
	temp->next = newnode;

}

void displaySLL(struct node* head)
{
	struct node* temp = head;
	while(temp!=NULL)
	{
		printf("%d-",temp->value);
		temp= temp->next;
	}
	printf("\n");
}

struct node* swap(struct node*a, struct node*b)
{
	int temp= a->value;
	a->value= b->value;
	b->value=  temp;
}

void selectionsortSLL(struct node**head)
{
	struct node*temp = *head;
	
	struct node*min = NULL;
	
	while(temp->next!=  NULL)
	{
	    struct node*j = temp->next;
	    min = temp;
	    while(j!=NULL)
	    {
	        if(j->value< min->value)
	        {
	            min =j;
	        }
	        j=j->next;
	    }
	    
	    
	    if(min!=temp)
	    {
	    swap(min,temp);
	    }
	    temp = temp->next;
	}

}

struct node* merge(struct node* head1, struct node* head2)
{
    struct node* newhead = NULL;
    struct node* temp1=head1;
    struct node * temp2 = head2;
    
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->value <= temp2->value)
        {
            insertatend(&newhead, temp1->value);
            temp1= temp1->next;       
        }
        else
        {
            insertatend(&newhead, temp2->value);
            temp2= temp2->next;  
        }
    }
    while(temp1!=NULL)
    {
        insertatend(&newhead, temp1->value);
            temp1= temp1->next;  
    }
    while(temp2!=NULL)
    {
        insertatend(&newhead, temp2->value);
        temp2= temp2->next; 
    }
    return newhead;
}

int main()
{
    //1 ll
	char input[100];
	printf("Enter first LL:  ");
	fgets(input,sizeof(input),stdin);
	char * token;
	token= strtok(input," ");
	while(token!=NULL)
	{
		int num= atoi(token);
		insertatend(&head1,num);
		token= strtok(NULL," ");
	}
	
	printf("\n");
	//2 ll
	char input2[100];
	printf("Enter second LL:  ");
	fgets(input2,sizeof(input2),stdin);
	char * token2;
	token2= strtok(input2," ");
	while(token2!=NULL)
	{
		int num2= atoi(token2);
		insertatend(&head2,num2);
		token2= strtok(NULL," ");
	}
	
	
	
	
	selectionsortSLL(&head1);
	selectionsortSLL(&head2);
	printf("\n After sorting:  ");
	displaySLL(head1);
	displaySLL(head2);
        
printf("Mergeing:  ");
struct node* newhead= merge(head1,head2);
displaySLL(newhead);
	
}