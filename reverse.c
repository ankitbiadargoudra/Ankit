#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100  

char stack[MAX];
int top = -1;  

int isEmpty() {
    return top == -1;
}

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;  
    } else {
        printf("Stack overflow!\n");
    }
}

char pop() {
    if (!isEmpty()) {
        return stack[top--]; 
    } else {
        printf("Stack underflow!\n");
        return '\0';  
    }
}

void reverseString(char* str) {
    int length = strlen(str);
    
    for (int i = 0; i < length; i++) {
        push(str[i]);
    }
    
    printf("Reversed string: ");
    for (int i = 0; i < length; i++) {
        printf("%c", pop());
    }
    printf("\n");
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    scanf("%s",str);
    

    reverseString(str);
    
    return 0;
}
