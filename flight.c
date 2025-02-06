#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int hour,min,totmin;
    char flight[100];
    struct node*next;
};
struct node*head =NULL;

struct node* createnode(int hour, int min, char*str)
{
    struct node *new= (struct node*)malloc(sizeof(struct node));
    strcpy(new->flight,str);
    new->totmin=(hour*60)+min;
    new->hour= hour;
    new->min= min;
}
void insertatend(struct node**head, int hour, int min, char*str)
{   
    if(strcmp(str,"NULL")==0)
    {
        return;
    }
    struct node*new= createnode(hour,min,str);
    if(*head==NULL)
    {
        *head= new;
        return;
    }
    struct node*temp = *head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next=new;

}

void display(struct node *head)
{
    struct node*temp= head;
    while(temp!=NULL)
    {
        printf("(%s,%d:%d)->",temp->flight,temp->hour,temp->min);
        temp= temp->next;
    }
    printf("NULL\n");
}
void swap(struct node*temp1,struct node *temp2)
{
    int temp = temp1->totmin;
    temp1->totmin= temp2->totmin;
    temp2->totmin= temp;

    temp = temp1->hour;
    temp1->hour= temp2->hour;
    temp2->hour= temp;

    temp = temp1->min;
    temp1->min= temp2->min;
    temp2->min= temp;

    char ele[100];
    strcpy(ele,temp1->flight);
    strcpy(temp1->flight,temp2->flight);
    strcpy(temp2->flight,ele);

}

void sort(struct node**head)
{
    struct node*temp= *head;
    while(temp->next->next!=NULL)
    {
        
        struct node* temp2= temp->next;
        struct node* min=temp2;
        while(temp2!=NULL)
        {
            if(min->totmin>temp2->totmin)
            {
                min = temp2;
            }
            temp2= temp2->next;
        }
         swap(temp,min);
         temp= temp->next;
    }

}
int main()
{
    char input[100]="(AA101, 18:30) ->(BA205,15:45) ->(UA303,20:15) ->NULL";
    // scanf("%[^/n]",input);

    char*token = strtok(input," ()\"->");
    while(token!=NULL)
    {
        int hour=0, min=0;
        char str[100];
        sscanf(token, "%[^,], %d:%d",str,&hour,&min);
        insertatend(&head,hour,min, str);

        token= strtok(NULL,"\"() ->");
    }
    display(head);
    sort(&head);
printf("\n");
     display(head);


}