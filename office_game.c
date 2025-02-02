#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char str[100];
    struct node* next;
};

struct node* head1=NULL;
struct node* head2 = NULL;
struct node* head3= NULL;

struct node* createnode(char * val)
{
   
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
   strcpy(newnode->str,val);
   newnode->next= NULL;
   
   return newnode;
 
}

void insertatend(struct node**head, char * val)
{
   
    struct node* temp = * head;
    struct node* new = createnode(val);
    if(*head==NULL)
    {
        *head = new;
     
    }
    else{
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next=new;
    
    temp = new;
    }
    
}

void solve( struct node* head1, struct node*head2)
{
    struct node* temp1 =  head1;
    struct node* temp2= head2;
    while(temp1!=NULL)
    {
       
        while(temp2!=NULL)
        {
            if(strcmp(temp1->str,temp2->str)==0)
            {
                printf(" --%s--",temp2->str);
                strcpy(temp2->str,"abc");
            }
            

            temp2 = temp2->next;
        }

        temp1= temp1->next;
        temp2= head2;
    }
    printf("\n");
    temp1= head1;
    temp2 = head2 ;
    while(temp1!=NULL)
    {
        
        printf(" \"%s \" ",temp1->str);
        
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        if(strcmp(temp2->str,"abc")!=0)
        {
        printf(" \"%s \" ",temp2->str);
        }
        temp2=temp2->next;
    }
}

int main(){

printf("Enter space seperated first Linked list\n");
char input[100];
fgets(input,sizeof(input),stdin);
char * token= strtok(input," \n");
while(token!= NULL)
{
    char temp[50];
    strcpy(temp,token);
    insertatend(&head1,temp);
    token = strtok(NULL," \n");
}

printf("\nEnter space seperated second Linked list\n");
fgets(input,sizeof(input),stdin);
token= strtok(input," \n");
while(token!= NULL)
{
    char temp[50];
    strcpy(temp,token);
    insertatend(&head2,temp);
    token = strtok(NULL," \n");
}

solve(head1, head2);

}