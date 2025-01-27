#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int value;
	struct node * next;

};

struct node* head = NULL;

struct node* createnode(int value)
{
	struct node* newnode = (struct node*)malloc( sizeof(struct node));
	newnode->value= value;
	newnode->next = NULL;
	
	return newnode;
}

void insertatend(int value)
{
	struct node* newnode= createnode(value);
	if(head==NULL)
	{
		head = newnode;
		return;
	}
	struct node* temp = head;

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




void binarysearchDLL(struct node**head, int k)
{
    struct node* start = *head;
    struct node*  end= NULL;
    int flag=0;
    
    while(start!=end)
    {
        struct node*mid = start;
        struct node*last = start;
        
        while(last!=end && last->next!=end)
        {
            mid- mid->next;
            last = last->next->next;
        }
        
        if(mid->value==k)
        {
            flag =1;
            printf("element Found ");
            return;
        }
        else if(mid->value<k)
        {
            start= mid->next;
        }
        else
        {
            end =mid;
        }
        
    }
    if(flag==0)
    {
        printf("not found\n");
        struct node* temp = * head;
        struct node* prev = NULL;
        while(temp->value<k && temp!=NULL)
        {
            prev = temp;
            temp = temp->next;
        }
       struct node* newnode =createnode(k);
        newnode->next = temp;
        
        prev->next = newnode;
        
        
    }
}
    
int main()
{
	char input[100];
	fgets(input,sizeof(input),stdin);
	char * token;
	token= strtok(input," ");
	while(token!=NULL)
	{
		int num= atoi(token);
		insertatend(num);
		token= strtok(NULL," ");
	}

	int k;
	printf("\n Enter k ( element to Search )");
	scanf("%d",&k);
	
    binarysearchDLL(&head,k);
    
    printf("\nAfter operations\n  :");
    
    displaySLL(head);
}