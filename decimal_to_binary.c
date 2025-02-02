#include <stdio.h>
#include <stdlib.h>

// Definition for a singly linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Function to convert a binary linked list to a decimal number
int binaryToDecimal(struct ListNode* head) {
    int decimalValue = 0;
    
    // Traverse the linked list
    while (head != NULL) {
        // Shift left (multiply by 2) and add the current node's value
        decimalValue = decimalValue * 2 + head->val;
        
        // Move to the next node
        head = head->next;
    }
    
    return decimalValue;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) {
            printf("->");
        }
        head = head->next;
    }
    printf("\n");
}

// Function to input the linked list
struct ListNode* inputList(int size) {
    int value;
    struct ListNode* head = NULL;
    struct ListNode* current = NULL;
    
    for (int i = 0; i < size; i++) {
        printf("Enter value for node %d (0 or 1): ", i+1);
        scanf("%d", &value);
        
        struct ListNode* newNode = createNode(value);
        
        if (head == NULL) {
            head = newNode;
            current = head;
        } else {
            current->next = newNode;
            current = current->next;
        }
    }
    
    return head;
}

int main() {
    int size;
    
    // Input the size of the linked list
    printf("Enter size of the binary linked list: ");
    scanf("%d", &size);
    
    // Input the elements for the linked list
    struct ListNode* head = inputList(size);
    
    // Convert the binary linked list to decimal
    int decimalValue = binaryToDecimal(head);
    
    // Print the result
    printf("The decimal equivalent of the binary linked list is: %d\n", decimalValue);
    
    return 0;
}
