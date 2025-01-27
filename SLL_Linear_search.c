#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int value;
	struct node * next;
	struct node* prev;
};

struct node* head = NULL;

struct node* createnode(int value)
{
	struct node* newnode = (struct node*)malloc( sizeof(struct node));
	newnode->value= value;
	newnode->next = NULL;
	newnode->prev= NULL;
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
	newnode->prev= temp;

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
	a->value = b->value;
	b->value=  temp;
}


void Linearsearch(struct node ** head , int k)
{
    struct node* temp = *head;
    int count =0,flag=0;
    while(temp!=NULL)
    {
        if(temp->value==k && (count+1)%2==0)
        {
            swap(temp, temp->next);
            temp = temp->next;
            flag=1;
            return ;
        }
        else if(temp->value==k && (count+1)%2!=0)
        {
           while(temp!=NULL)
           {
               struct node*del=  temp->next;
               temp ->next = del->next;
               temp = del->next;
               free(del);
               flag=1;
               
           }
           return;
        }
        count++;
         temp = temp->next;
    }
    if(flag==0)
    {
       printf("Not found!");
       return;
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
	printf("\n Enter k (number of elements to Search\n");
	scanf("%d",&k);
	
    Linearsearch(&head, k);
    
    printf("After operations\n:");
    displaySLL(head);
    
     
}