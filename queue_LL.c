#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear  = NULL;

int isEmpty() {
    return front == NULL;
}


void enqueue(int ele)
{
    struct node * temp = (struct node*)malloc(sizeof(struct node)) ;
    temp->next =NULL;
    temp->data = ele;
    if(isEmpty())
    {
        front = temp;
        rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }

}

void dequeue()
{
    if(isEmpty())
    {
        printf("no element to remove");
        return;
    }
    printf(" dequeue element: %d\n",front->data);
    struct node* temp = front;
    front = front->next;
    free(temp);
}
void peek()
{
    if(isEmpty())
    {
        printf("no element to peek");
        return;
    }
    else{
        printf("%d",front->data);
    }
}
void display()
{
    if(isEmpty())
    {
        printf("no element to display ");
        return;

    }
    else{
        struct node*temp = front;
        while(temp!=rear->next)
        {
            printf("%d--",temp->data);
            temp= temp->next;

        }
        printf("\n");
    }
}

void size()
{
    struct node *temp = front;
    int count =0;
        while(temp!=rear->next)
        {
           count++;
           temp=temp->next;
        }
        printf("%d",count); 
}
int main()
{
printf("Queue operations \n enter operations\n");
int c;
printf("1.enqueue\n 2.dequeue \n 3. peek \n 4.display\n5. size\n");


while(1)
{

    scanf("%d",&c);
if(c==1)
{printf("enter elemnet");
int ele;
scanf("%d",&ele);
    enqueue(ele);
}
else if(c==2)
{
    dequeue();
}
else if(c==3)
{
    peek();
}
else if(c==4)
{
    display();
}
else if(c==5)
{
    size();
}
else 
{
printf("Enter valid operation");
break;
}
}
}
