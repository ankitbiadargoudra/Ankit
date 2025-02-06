#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int arr[100];
    int front,rear;
};
void init(struct node*q)
{
    q->front=-1;
    q->rear=-1;
}

void enqueue( char queue[][100],int *front,int *rear ,char*ele)
{
    if(*front==-1)
    {
        (*front)=0;
        *rear=0;
        strcpy(queue[*front],ele);
    }
    else{
        (*rear)++;
         strcpy(queue[*rear],ele);
    }
   
}
void dequeue( char queue[][100],int *front,int *rear )
{
    if(*front == -1 || *front > *rear)
    {
        printf("Nothing to pop\n");
        return;
    }
    printf("poped string: %s\n",queue[*front]);
    (*front)++;
    if (*front > *rear) {  // Reset queue if empty
        *front = -1;
        *rear = -1;
    }
}

void display(char queue[][100], int front, int rear)
{
    if(front==rear)
    {
        printf("Nothing to print\n");
        return;
    }
    for(int i=front; i<=rear;i++)
    {
        printf("%s->",queue[i]);
    }
    printf("\n");
}
int main()
{
    struct node q;
    init(&q);
    char input[100][100]= {"ankit","abhishek","rohit","sanket","manju","rakesh"};
    for(int i=0; i<6;i++)
    {

        enqueue(queue,&front,&rear,input[i]);
    }
    display(queue,front,rear);

    dequeue(queue,&front,&rear);
    dequeue(queue,&front,&rear);
    dequeue(queue,&front,&rear);
    display(queue,front,rear);

}