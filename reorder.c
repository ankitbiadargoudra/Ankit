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

struct node* findMiddle(struct node* head) {
    struct node* slow = head;
    struct node* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

struct node* reverseList(struct node* head) {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

void reorderList(struct node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    struct node* middle = findMiddle(head);
    struct node* secondHalf = middle->next;
    middle->next = NULL;  // Split the list into two halves
    
    secondHalf = reverseList(secondHalf);  // Reverse the second half
    
    struct node* firstHalf = head;
    
    // Merge the two halves
    while (secondHalf != NULL) {
        struct node* temp1 = firstHalf->next;
        struct node* temp2 = secondHalf->next;
        
        firstHalf->next = secondHalf;
        secondHalf->next = temp1;
        
        firstHalf = temp1;
        secondHalf = temp2;
    }
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
    int n;
    
    printf("Enter the size of the list: ");
    scanf("%d", &n);
    
    struct node* head = createList(n);
    
    printf("Original List: ");
    printList(head);
    
    reorderList(head);
    
    printf("Reordered List: ");
    printList(head);
    
    return 0;
}
