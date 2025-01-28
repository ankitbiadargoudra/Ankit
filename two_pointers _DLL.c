#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node {
    int value;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;
struct node* tail = NULL;

struct node* createnode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->value = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void insertatend(int value) {
    struct node* newnode = createnode(value);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void displayDLL(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}


void findPairWithSum(struct node* head, struct node* tail, int target) {
    struct node* left = head;
    struct node* right = tail;
    int found = 0;

    while (left != NULL && right != NULL && left != right ) {
        int sum = left->value + right->value;
        if (sum == target) {
            printf("Pair found: %d + %d = %d\n", left->value, right->value, target);
            found = 1;
           return;
        } else if (sum < target) {
            left = left->next;
        } else {
            right = right->prev;
        }
    }

    if (!found) {
        printf("No pair found with sum %d.\n", target);
    }
}

int main() {
    char input[100];
	fgets(input,sizeof(input),stdin);
	char * token;
	token= strtok(input," ");
	while(token!=NULL)
	{
		int num= atoi(token);
		insertatend(num);
		token= strtok(NULL," ");
	}

    printf("Doubly Linked List: ");
    displayDLL(head);

    int target;
    printf("Enter target sum: ");
    scanf("%d", &target);

    findPairWithSum(head, tail, target);

    return 0;
}