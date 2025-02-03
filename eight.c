#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 10 


struct node{
    
    char movie[100];
    int screen;
    int seat;
    int amount;   
    struct node*next;
};

struct node* head1= NULL;
struct node* head2 = NULL;

struct node* createnode(char*movie, int screen, int seat, int amt)
{
    printf("creating started\n");
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->screen = screen;
    new->amount= amt;
    new->seat= seat;
    strcpy(new->movie,movie);
    new->next= NULL;
    printf("created\n");
    return new;
}

void enqueue(struct node**head,struct node*new)
{
    printf("enque stated\n");
    struct node*temp = *head;
    
    if(*head==NULL)
    {
        *head = new;
        printf("enque at head\n");
        return;
    }
    while(temp->next!=NULL)
    {
        temp = temp->next;

    }
    temp->next= new;  
    printf("enque ended\n"); 
}

void book(struct node*head)
{
    int screen,seat,amt;
    char movie[100];
     printf("enter movie name\n");
     getchar();
    scanf("%[^\n]s",movie);
    printf("Enter screen, seat, amt(space seperated)\n");
    scanf("%d %d %d",&screen,&seat,&amt);
    struct node*new = createnode(movie,screen,seat,amt);
    enqueue(&head1,new);
    printf("Booked\n");
}

struct node* dequeue(struct node**head)
{
    struct node* temp= *head;
    *head= (*head)->next;
    temp->next=NULL;
    return temp;
}
void approve(struct  node**head1, struct node**head2)
{
    struct node* temp1= *head1;
    struct node* temp2 = *head2;
    if(*head1==NULL)
    {
        printf("No Booking left to approve\n");
        return;
    }
    struct node* booked = dequeue(head1);
    enqueue(head2,booked);
    printf("Approved, seat numer->%d\n",booked->seat);

}

void display(struct node**head,int a)
{
    if(a==1)
    {
        printf("Booking pending to be approved:\n");
    }
    else{
        printf("Booking approved\n");
    }
    struct node* temp = *head;
    while(temp!=NULL)
    {
        printf("moive:%s, screen:%d, seat_no:%d, amount:%d\n",temp->movie,temp->screen,temp->seat,temp->amount);
        temp= temp->next;
    }
    printf("All done\n");
}

int main()
{
   
    while(1)
    {
         printf("Enter your choice \n1.BOOK \n2.APPROVE \n3.BOOKED \n4.APPROVED\n5.exit \n");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1 :
        book(head1);
        break;

        case 2:
        approve(&head1,&head2);
        break;

        case 3:
       display(&head1,1);
        break;

        case 4:
        display(&head2,2);
        break;

        case 5:
        return 0;
        break;

        default:
        printf("Enter valid operation");
        break;

    }
    }
}

