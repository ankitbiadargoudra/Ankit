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

struct node* swap(struct node*a, struct node*b)
{
	int temp= a->value;
	a->value= b->value;
	b->value=  temp;
}
void bubblesortSLL(struct node**head)
{
	int flag=1;
	while(flag==1)
	{
		struct node *temp = * head;
		flag=0;
		while(temp->next !=NULL)
		{
			if(temp->value >  temp->next->value)
			{
				swap(temp, temp->next);
				flag=1;
			}
			temp= temp->next;
		}
	}

}

void reverseknodes(struct node**head, int k)
{
	struct node* temp = *head;
	int count =0;
	struct node* prev=NULL;
	struct node* cur = temp;
	struct node* next = NULL;
	while(count<k && temp!=NULL)
	{

		next = cur->next;
		cur->next= prev;
		prev =cur;
		cur = next;

		count++;
	}
	(*head)->next = cur;
	*head= prev;
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
	printf("\n Enter k (number of nodes to reverse");
	scanf("%d",&k);
	
	bubblesortSLL(&head);
    printf("Normaly sorted\n");
	displaySLL(head);
    printf("\nreversed k nodes:\n");
	reverseknodes(&head, k);
	displaySLL(head);
}