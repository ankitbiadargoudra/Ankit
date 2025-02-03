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

struct node* reverseKNodes(struct node* head, int k) {
    struct node* current = head;
    struct node* prev = NULL;
    struct node* next = NULL;
    int count = 0;
    
    // Reverse the first k nodes of the list
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    
    // If there are more nodes to be reversed, recursively reverse the next group
    if (next != NULL) {
        head->next = reverseKNodes(next, k);
    }
    
    return prev;
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
    int n, k;
    
    printf("Enter the size of the list: ");
    scanf("%d", &n);
    
    struct node* head = createList(n);
    
    printf("Enter the group size (k): ");
    scanf("%d", &k);
    
    printf("Original List: ");
    printList(head);
    
    head = reverseKNodes(head, k);
    
    printf("Reordered List: ");
    printList(head);
    
    return 0;
}
