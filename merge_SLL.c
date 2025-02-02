#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printList(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void insertatend(struct node ** head, int val)
{
    printf("Function inseratend start");
    struct node*temp= *head;
    struct node *new= newNode(val);
    if(*head==NULL)
    {
        *head= new ;
        return;
    }
    while(temp->next!=NULL)
    {
        temp= temp->next;
    }
    
 temp->next=new;
 temp= new;
 printf("Function inseratend end");
}

struct node* createList(int n) {
     printf("Function createsll start\n");
    struct node* head = NULL;
    struct node* temp = NULL;
    struct node* prev = NULL;
    
    int data;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        temp = newNode(data);
        
        if (head == NULL) {
            head = temp;
        } else {
            prev->next = temp;
        }
        
        prev = temp;
    }
     printf("Function createsll end\n");
    return head;
}

struct node* mergesll(struct node* first, struct node* second) {
    printf("Function start");
    struct node* result = NULL;

    
    while(first!=NULL&& second!=NULL)
    {
        if(first->data< second->data)
        {
            insertatend(&result, first->data);
            first= first->next;

        }
        else {
            insertatend(&result, second->data);
            second = second->next;
        }
    }
    while(first!=NULL)
    {
           insertatend(&result, first->data);
            first= first->next;
    }
    while(second!=NULL)
    {
           insertatend(&result, second->data);
            second = second->next;
    }
    printf("Function end");
    return result;
}

int main() {
    int n1, n2;
    
    printf("Enter the size of the first number: ");
    scanf("%d", &n1);
    
    struct node* first = NULL;
    printf("Enter the digits for the first number (space separated): ");
    first = createList(n1);

    printf("Enter the size of the second number: ");
    scanf("%d", &n2);
    
    struct node* second = NULL;
    printf("Enter the digits for the second number (space separated): ");
    second = createList(n2);

    struct node* head3 = mergesll(first, second);

    printf("Product: ");
    printList(head3);

    return 0;
}
