#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* next;
};

struct node*head;

void insertatend(struct node**head, int value)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->value=value;
    new->next= NULL;

    if(*head==NULL)
    {
        *head=new;
        return ;
    }
    struct node* temp = *head;
      while(temp->next!=NULL)
      {
        temp = temp->next;
      }
    temp->next = new;

}

struct node* removeduplicates(struct node *head) {
    printf("Removing started\n");
    if (head == NULL) {
        return head;
    }

    struct node *temp = head;

    while (temp != NULL) {
        struct node *prev = temp;
        struct node *cur = temp->next;

        while (cur != NULL) {
            if (temp->value == cur->value) {
                prev->next = cur->next;
                free(cur);
                cur = prev->next; 
            } else {
                prev = cur;
                cur = cur->next;
            }
        }

        temp = temp->next;
    }

    printf("Removing ended\n");
    return head;
}

void display(struct node* head)
{
    struct node*temp = head;
    while(temp!=NULL)
    {
        printf("%d->",temp->value);
        temp= temp->next;
    }
}

struct node* getmiddle(struct node*head)
{
    printf("getting middle\n");
    struct node*slow = head;
    struct node*fast= head;
    while(fast!=NULL &&fast->next!=NULL)
    {
        fast= fast->next->next;
        if(fast!=NULL)
        {
            slow= slow->next;
        }
    }
    struct node*second = slow->next;
    slow->next = NULL;
    printf("got middle\n");
    return second;
}

struct node* merge(struct node*head1 , struct node* head2)
{
    printf("merge started\n");
    struct node* newhead= NULL;

    while(head1!=NULL&& head2!=NULL)
    {
        if(head1->value<= head2->value)
        {
            insertatend(&newhead,head1->value);
            head1= head1->next;
        }
        else{
             insertatend(&newhead,head2->value);
            head2= head2->next;
        }

    }
    while(head1!=NULL)
    {
        insertatend(&newhead,head1->value);
        head1= head1->next;
    }
    while(head2!=NULL)
    {
        insertatend(&newhead,head2->value);
        head2= head2->next;
    }
    printf("merge ended\n");
    return newhead;

 }

// struct node* merge(struct node*temp, struct node*second)
// {
    
//         if(temp==NULL) return second;
//         if(second==NULL) return temp;
        
//         if(temp->value<second->value)
//         {
//             temp->next = merge(temp->next,second);
//             return temp;
//         }
//         else{
//             second->next = merge(temp, second->next);
//             return second;
//         }
// }

struct node* mergesort(struct node* head)
{
    printf("mergesort started\n");
    if(head==NULL ||head->next ==NULL)
    {
        return head;
    }
    
    struct node*  middle= getmiddle(head);

    struct node *first= mergesort(head);
    struct node* second = mergesort(middle);
    printf("mergesort ended\n");
    return merge(first, second);

}

int main()
{
    int n; 
    printf("enter size\n");
    scanf("%d",&n);
    printf("enter elements\n");
    for(int i=0; i<n;i++)
    {
        int num;
        scanf("%d",&num);
        insertatend(&head,num);

    }
   struct node*newhead= removeduplicates(head);
    display(head);
    printf("\n");
    display(newhead);

    struct node* mergehead=mergesort(newhead);
     display(mergehead);
}
