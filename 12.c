#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Push function
void push(char stack[][100], int *top, const char *val) {
    if (*top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    (*top)++;
    strcpy(stack[*top], val);
}

// Pop function
char* pop(char stack[][100], int *top) {
    if (*top == -1) {
        return NULL;
    }
    static char temp[100];
    strcpy(temp, stack[*top]);
    (*top)--;
    return temp;
}

// Display function
void display(char stack[][100], int top) {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    while (top >= 0) {
        printf("%s--", stack[top]);
        top--;
    }
    printf("\n");
}

// Solve function (handling the decoding logic)
void solve(char stack[][100], int *top) {
    char stack2[MAX][100];
    int top2 = -1;
    char str[100] = "";

    // Process the stack while it has elements
    while (*top >= 0) {
        // Pop the top element
        char *ele = pop(stack, top);
        if (!ele) break;

        if (strcmp(ele, "]") == 0) {
            // Start decoding when we encounter a closing bracket ']'
            char temp[100] = "", ele2[100];
            while (*top >= 0) {
                // Pop until we get to the opening bracket '['
                strcpy(ele2, pop(stack, top));

                if (strcmp(ele2, "[") == 0) {
                    break;  // Exit when we reach the opening bracket '['
                }
                strcat(temp, ele2);  // Build the string inside the brackets
            }

            // Pop the number (times to repeat) before '['
            char *numStr = pop(stack, top);
            if (numStr) {
                int num = atoi(numStr);
                // Repeat the string 'num' times and push to stack2
                for (int i = 0; i < num; i++) {
                    push(stack2, &top2, temp);
                }
            }
        } else {
            // Otherwise, just push it onto stack2 (temporary storage)
            push(stack2, &top2, ele);
        }
    }

    // Display the final result
    printf("Decoded result:\n");
    while (top2 >= 0) {
        printf("%s", stack2[top2]);
        top2--;
    }
    printf("\n");
}

int main() {
    char stack[MAX][100];
    int top = -1;

    printf("Enter the string: ");
    char str[MAX];
    scanf("%s", str);  // Read the string input

    // Push each character of the string onto the stack
    for (int i = 0; i < strlen(str); i++) {
        char temp[2] = {str[i], '\0'};
        push(stack, &top, temp);
    }

    // Display the stack elements
    display(stack, top);

    // Process the string to decode it
    solve(stack, &top);

    return 0;
}
