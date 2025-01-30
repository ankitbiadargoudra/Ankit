#include <stdio.h>

#define MAX 5  


int queue[MAX];  
int front = 0;   
int rear = 0;    

void enqueue(int value) {
    queue[rear] = value;
    rear = (rear + 1) % MAX;  // Wrap around if necessary
}


int dequeue() {
    int dequeuedValue = queue[front];
    front = (front + 1) % MAX;  // Wrap around if necessary
    return dequeuedValue;
}

void display() {
    printf("Queue: ");
    for (int i = front; i != rear; i = (i + 1) % MAX) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
 
   
    printf("queue operations \n enter operations\n");
int c;


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
    display();
}
else 
{
printf("Enter valid operation");
break;
}
}
}
