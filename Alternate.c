#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
	int value;
	struct node* next;
	struct node* prev;
};

struct node* createnode(int value)
{
	struct node* newnode= (struct node*)malloc(sizeof(struct node));
	newnode->value= value;
	newnode->next= NULL;
	newnode->prev= NULL;
	return newnode;
}

struct node* head= NULL;
struct node* tail = NULL;

void insertatend(struct node** head, struct node** tail,int value)
{
	struct node* newnode= createnode(value);
	if(*head==NULL)
	{
		*head = newnode;
		*tail = newnode;
		return;
	}
	(*tail)->next = newnode;
	newnode->prev= *tail;
	*tail = newnode;
}


void lefttoright(struct node ** head,struct node  ** tail, int *count)
{
	struct node* temp = * head;
	int skip =0;
	while(temp!=NULL)
	{
		struct node*cur = temp;
		temp = temp->next;

		if(skip==0) {
			if(cur == *head)
			{
				*head = (*head)->next;

			}
			if(cur == *tail)
			{
				*tail = (*tail)->prev;
			}

			struct node* prev = cur->prev;
			struct node* next = cur->next;
			if (prev) prev->next = next;
			if (next) next->prev = prev;


			free(cur);
			(*count)--;
		}
		skip=1-skip;
	}
}


void righttoleft(struct node ** head,struct node  ** tail, int *count)
{
	struct node* temp = *tail;
	int skip=0;
	while(temp!=NULL)
	{
		struct node*cur = temp;
		temp = temp->prev;

		if(skip==0)
		{
			if(cur == *head)
			{
				*head = (*head)->next;

			}
			if(cur == *tail)
			{
				*tail = (*tail)->prev;
			}

			struct node* prev = cur->prev;
			struct node* next = cur->next;
			if (prev) prev->next = next;
			if (next) next->prev = prev;

			free(cur);
			(*count)--;
		}
		skip  = 1- skip;
	}
}
void displayDLL(struct node* head) {
	struct node* temp = head;
	while (temp != NULL) {
		printf("%d", temp->value);
		temp = temp->next;
	}

}


int main() {

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n ;
	scanf("%d",&n);
	int count =n;

	for(int i=1; i<=n; i++)
	{
		insertatend(&head,&tail,i);
	}

	while(count>1)
	{
		lefttoright(&head,&tail,&count);
		if(count>1)
		{
			righttoleft(&head,&tail,&count);
		}

	}

	printf("%d",head->value);
	return 0;
}
