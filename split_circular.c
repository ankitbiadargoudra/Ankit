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
    struct node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

struct node* splitCircularList(struct node* head) {
    if (!head || head->next == head) {
        return NULL;  // If there's no list or only one node.
    }

    struct node* slow = head;
    struct node* fast = head;
    struct node* prev = NULL;

    // Move fast pointer two steps and slow pointer one step
    while (fast->next != head && fast->next->next != head) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the list into two halves
    struct node* secondListHead = slow->next;
    slow->next = head;  // Break the first half circular link

    // Find the last node of the second list and break its circle
    fast = secondListHead;
    while (fast->next != head) {
        fast = fast->next;
    }
    fast->next = secondListHead;  // Break the second half circular link

    return secondListHead;
}

struct node* createCircularList(int n) {
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

    prev->next = head;  // Complete the circle

    return head;
}

int main() {
    int n;
    
    printf("Enter the size of the circular linked list: ");
    scanf("%d", &n);

    struct node* head = createCircularList(n);

    printf("Original Circular List: ");
    printList(head);

    struct node* secondListHead = splitCircularList(head);

    printf("First List: ");
    printList(head);
    
    printf("Second List: ");
    printList(secondListHead);
    
    return 0;
}
