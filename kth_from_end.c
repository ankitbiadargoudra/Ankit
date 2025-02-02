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

struct node* findKthFromEnd(struct node* head, int k) {
    struct node* slow = head;
    struct node* fast = head;

    for (int i = 0; i < k; i++) {
        if (fast == NULL) {
            return NULL;
        }
        fast = fast->next;
    }

    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
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
    
    printf("Enter the value of k: ");
    scanf("%d", &k);
    
    printf("Original List: ");
    printList(head);
    
    struct node* kthNode = findKthFromEnd(head, k);
    
    if (kthNode != NULL) {
        printf("The %d-th node from the end is: %d\n", k, kthNode->data);
    } else {
        printf("The list is shorter than %d nodes.\n", k);
    }
    
    return 0;
}
