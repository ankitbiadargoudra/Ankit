#include <stdio.h>
#define MAX 5   

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    if ((rear + 1) % MAX == front) {
        return 1;  // Queue is full
    }
    return 0;
}

int isEmpty() {
    if (front == rear) {
        return 1;  // Queue is empty
    }
    return 0;
}

void peek() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot peek.\n");
    } else {
        printf("Peek: %d\n", queue[front]);
    }
}

void  enqueue(int value) {
    if (isFull()) {
        printf("stack is full. Cannot enqueue %d\n", value);
        return;
    }
    if (front == -1) {
        front = 0;  // Initialize front when the first element is enqueued
    }
    rear = (rear + 1) % MAX;  // Circular increment for rear
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to dequeue an element from the queue
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int dequeuedValue = queue[front];
    if (front == rear) {  // If the queue has only one element
        front = rear = -1;  // Reset the queue
    } else {
        front = (front + 1) % MAX;  // Circular increment for front
    }
    return dequeuedValue;
}


void push(int value)
{
    enqueue(value);
    int temprear=rear;
    while(front!=temprear)
    {
        int value= dequeue();
        enqueue(value);

    }
}
// Function to display the queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;  // Circular increment for index
    }
    printf("%d\n", queue[rear]);  // Print the last element
}

int main() {
    printf("Queue operations \nEnter operations\n");
    int c;
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n");

    while (1) {
        printf("\nEnter operation (1-4): ");
        scanf("%d", &c);

        if (c == 1) {
            printf("Enter element to enqueue: ");
            int ele;
            scanf("%d", &ele);
            push(ele);
        }
        else if (c == 2) {
            dequeue();
        }
        else if (c == 3) {
            peek();
        }
        else if (c == 4) {
            display();
        }
        else {
            printf("Invalid operation. Exiting...\n");
            break;
        }
    }

    return 0;
}
