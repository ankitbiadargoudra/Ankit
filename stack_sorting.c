#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int stack1[25], stack2[25];
int top1 = -1, top2 = -1;

// Push function
void push(int stack[], int *top, int ele) {
    if (*top == 24) {
        printf("Stack overflow\n");
        return;
    } else {
        (*top)++;
        stack[*top] = ele;
    }
}

// Pop function
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

// Peak function
void peak(int stack[], int *top) {
    if (*top == -1) {
        printf("No elements\n");
    } else {
        printf("%d\n", stack[*top]);
    }
}

// Display function
void display(int stack[], int *top) {
    if (*top == -1) {
        printf("No elements\n");
    } else {
        for (int i = *top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Get max function using recursion
int getmax(int stack[], int *top) {
    if (*top == -1) {
        return INT_MIN;
    }

    int cur = pop(stack, top);
    int maxInRest = getmax(stack, top);
    int max = (cur > maxInRest) ? cur : maxInRest;

    push(stack, top, cur);  // Restore the stack

    return max;
}

// Sort stack function
void sortstack(int size) {
    for (int i = 0; i < size; i++) {
        int max = getmax(stack1, &top1);
        push(stack2, &top2, max);
    }
}

// Main function
int main() {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);

    printf("Enter the elements of stack1\n");
    for (int i = 0; i < size; i++) {
        int ele;
        scanf("%d", &ele);
        push(stack1, &top1, ele);
    }

    sortstack(size);

    printf("Sorted stack2: ");
    display(stack2, &top2);

    return 0;
}