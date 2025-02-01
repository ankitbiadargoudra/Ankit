#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printList(struct node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
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

struct node* multiplyTwoLists(struct node* first, struct node* second) {
    int num1 = 0, num2 = 0;
    int factor = 1;
    
    // Convert first linked list to an integer
    while (first != NULL) {
        num1 += first->data * factor;
        factor *= 10;
        first = first->next;
    }

    // Convert second linked list to an integer
    factor = 1;
    while (second != NULL) {
        num2 += second->data * factor;
        factor *= 10;
        second = second->next;
    }

    // Multiply the numbers
    int product = num1 * num2;

    // Convert the product back to a linked list
    struct node* result = NULL;
    struct node* temp = NULL;
    
    if (product == 0) {
        return newNode(0);
    }
    
    while (product > 0) {
        int digit = product % 10;
        temp = newNode(digit);
        temp->next = result;
        result = temp;
        product /= 10;
    }
    
    return result;
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

    struct node* result = multiplyTwoLists(first, second);

    printf("Product: ");
    printList(result);

    return 0;
}
