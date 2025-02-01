#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* addTwoLists(struct node* first, struct node* second) {
    struct node* result = NULL;
    struct node* temp = NULL;
    struct node* prev = NULL;
    int carry = 0, sum;
    
    while (first != NULL || second != NULL) {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = sum / 10;
        sum = sum % 10;
        
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = sum;
        temp->next = NULL;
        
        if (result == NULL) {
            result = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
        
        if (first != NULL) first = first->next;
        if (second != NULL) second = second->next;
    }
    
    if (carry > 0) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = carry;
        temp->next = NULL;
        prev->next = temp;
    }
    
    return result;
}

void printList(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct node* createList(int n) {
    struct node* head = NULL;
    struct node* temp = NULL;
    struct node* prev = NULL;
    
    int data;
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        temp = newNode(data);
        
        if (head == NULL) {
            head = temp;
        } else {
            prev->next = temp;
        }
        
        prev = temp;
    }
    
    return head;
}

int main() {
    int n1, n2;
    
    printf("Enter the size of the first number: ");
    scanf("%d", &n1);
    
    struct node* first = NULL;
    printf("Enter the digits for the first number (space separated): ");
    first = createList(n1);

    printf("Enter the size of the second number: ");
    scanf("%d", &n2);
    
    struct node* second = NULL;
    printf("Enter the digits for the second number (space separated): ");
    second = createList(n2);

    struct node* result = addTwoLists(first, second);

    printf("Sum: ");
    printList(result);

    return 0;
}
