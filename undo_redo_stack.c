#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Stack Structure
typedef struct {
    char stack[MAX][MAX];
    int top;
} Stack;

// Stack Operations
void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char *val) {
    if (s->top < MAX - 1) {
        strcpy(s->stack[++s->top], val);
    }
}

char* pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->stack[s->top--];
    }
    return NULL;
}

char* peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->stack[s->top];
    }
    return "";
}

// Text Editor Functions
void type(Stack *undoStack, Stack *redoStack, char c) {
    char newText[MAX];
    strcpy(newText, peek(undoStack));
    int len = strlen(newText);
    newText[len] = c;
    newText[len + 1] = '\0';
    
    push(undoStack, newText);
    initStack(redoStack);  // Clear redoStack since new input invalidates redo history
}

void undo(Stack *undoStack, Stack *redoStack) {
    if (undoStack->top > 0) {  
        push(redoStack, pop(undoStack));  
        printf("Undo performed! Current Text: %s\n", peek(undoStack));
    } else {
        printf("Nothing to undo!\n");
    }
}

void redo(Stack *undoStack, Stack *redoStack) {
    if (!isEmpty(redoStack)) {  
        push(undoStack, pop(redoStack));  
        printf("Redo performed! Current Text: %s\n", peek(undoStack));
    } else {
        printf("Nothing to redo!\n");
    }
}

// Main Function
int main() {
    Stack undoStack, redoStack;
    initStack(&undoStack);
    initStack(&redoStack);
    
    push(&undoStack, ""); // Initial empty text
    
    int choice;
    char c;

    while (1) {
        printf("\nCurrent Text: %s\n", peek(&undoStack));
        printf("1. Type Character\n2. Undo\n3. Redo\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a character to type: ");
                scanf(" %c", &c);  // Space before %c to ignore whitespace
                type(&undoStack, &redoStack, c);
                break;
            case 2:
                undo(&undoStack, &redoStack);
                break;
            case 3:
                redo(&undoStack, &redoStack);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
