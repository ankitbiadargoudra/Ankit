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

void displayDLL(struct node* head)
{
	struct node* temp = head;
	while(temp!=NULL)
	{
		printf("%d-",temp->value);
		temp= temp->next;
	}
	printf("\n");
}

void swap(struct node*a, struct node*b)
{
	int temp= a->value;
	a->value= b->value;
	b->value=  temp;
}

struct node* partition(struct node*first, struct node* second)
{
    int pivot= second->value;
    struct node* i = first->prev;
    
    for(struct node*j = first; j!=second; j=j->next)
    {
        if(j->value<pivot)
        {
            if(i==NULL)
            {
                i=first;
            }
            else{
                i=i->next;
            }
            swap(i,j);
        }
    }
    if(i==NULL)
    {
        i=first;
    }
    else{
        i=i->next;
    }
    swap(i,second);
    return i;
}

void  quicksortDLL(struct node*head, struct node* tail)
{
    if(tail!=NULL && head!=tail && head!= tail->next)
    {
        struct node* pivot = partition(head,tail);
        quicksortDLL(head, pivot->prev);
        quicksortDLL(pivot->next,tail);
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
	char * token;
	token= strtok(input," ");
	while(token!=NULL)
	{
		int num= atoi(token);
		insertatend(num);
		token= strtok(NULL," ");
	}

	int k;
	printf("\n Enter k (number of elements to diappear");
 	scanf("%d",&k);
	
	//get end node
	struct node* temp = head;
	while(temp->next!=NULL)
	{
	    temp= temp->next;
	}
	struct node* tail= temp;

    quicksortDLL(head,tail);
    printf("Quick sorted\n");
	displayDLL(head);
    printf("After deleting\n");
     head = removenode(head,k );
     displayDLL(head);
}