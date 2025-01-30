#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top ;
};

void initStack(struct Stack* stack) {
    stack->top = NULL;
}
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        struct Node* temp = stack->top;
        printf("Popped element: %d\n", stack->top->data);
        stack->top = stack->top->next;
        free(temp);
    }
}

void peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", stack->top->data);
    }
}

void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
    } else {
        struct Node* temp = stack->top;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack1; 
    initStack(&stack1);

    struct Stack stack2; 
    initStack(&stack2);
    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);

    //second 
    push(&stack2, 40);
    push(&stack2, 50);
    push(&stack2, 60);
    display(&stack1);
    
    display(&stack2);
    
    return 0;
}
