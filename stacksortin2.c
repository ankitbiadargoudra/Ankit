#include<stdio.h>
#include<stdlib.h>

int stack1[25], stack2[25];
int top1 = -1, top2 = -1;

void push(int stack[], int *top, int ele) {
    if (*top == 24) {
        printf("Stack overflow\n");
        return;
    } else {
        (*top)++;
        stack[*top] = ele;
    }
}

int pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        int value = stack[*top];
        (*top)--;
        return value;
    }
}

int isEmpty(int *top) {
    return *top == -1;
}

void sortStack() {
    while (!isEmpty(&top1)) {
        int temp = pop(stack1, &top1);
        while (!isEmpty(&top2) && stack2[top2] > temp) {
            push(stack1, &top1, pop(stack2, &top2));
        }
        push(stack2, &top2, temp);
    }
    while (!isEmpty(&top2)) {
        push(stack1, &top1, pop(stack2, &top2));
    }
}

void display() {
    for (int i = top1; i >= 0; i--) {
        printf("%d ", stack1[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        int ele;
        scanf("%d", &ele);
        push(stack1, &top1, ele);
    }
    sortStack();
    display();
    return 0;
}
