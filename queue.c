#include <stdio.h>
#include <stdlib.h>

#define MAX 5  


struct Queue {
    int items[MAX];
    int front, rear;
};


void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}


int isEmpty(struct Queue* q) {
    return (q->front == -1);
}


int isFull(struct Queue* q) {
    return (q->rear == MAX - 1);
}


void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
    } else {
        if (q->front == -1) {  
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("%d enqueued to the queue\n", value);
    }
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;  
    } else {
        int dequeuedValue = q->items[q->front];
        if (q->front == q->rear) {  
            q->front = q->rear = -1; 
        } else {
            q->front++;
        }
        
    }
}


void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue q; 
    initQueue(&q);
    printf("queue operations \n enter operations\n");
int c;


while(1)
{

    scanf("%d",&c);
if(c==1)
{printf("enter elemnet");
int ele;
scanf("%d",&ele);
     enqueue(&q, ele);
}
else if(c==2)
{
    dequeue(&q);
}

else if(c==3)
{
    display(&q);
}
else 
{
printf("Enter valid operation");
break;
}
}
}
