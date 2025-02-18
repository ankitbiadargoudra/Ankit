#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node {
    char val;
    int count;
    struct node* next;
};

struct node* arr[10];

int hash(char key) {
    return (key - 'a') % 10;
}

void insert(char val) {
    int index = hash(val);
    struct node* temp = arr[index];

    while (temp) {
        if (temp->val == val) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->val = val;
    newNode->count = 1;
    newNode->next = arr[index];
    arr[index] = newNode;
}

void delete(char val) {
    int index = hash(val);
    struct node* temp = arr[index], *prev = NULL;

    while (temp) {
        if (temp->val == val) {
            temp->count--;
            if (temp->count == 0) {  // Remove node if count reaches 0
                if (prev) prev->next = temp->next;
                else arr[index] = temp->next;
                free(temp);
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

unsigned int distinct() {
    unsigned int count = 0;
    for (int i = 0; i < 10; i++) {
        struct node* temp = arr[i];
        while (temp) {
            if (temp->count > 0) count++;
            temp = temp->next;
        }
    }
    return count;
}

void NULLALL() {
    for (int i = 0; i < 10; i++) {
        struct node* temp = arr[i];
        while (temp) {
            struct node* nextNode = temp->next;
            free(temp);
            temp = nextNode;
        }
        arr[i] = NULL;
    }
}

void solve(char* str, int k, int n) {
    int minLen = 0;

    for (int i = 0; i < n; i++) {
        NULLALL(); // Reset before checking a new substring

        for (int j = i; j < n; j++) {
            insert(str[j]);

            int num = distinct();
            if (num == k) {
                int size = j - i + 1;
                if (size > minLen) {
                    minLen = size;
                }
            }
        }
    }

    printf("%d\n", (minLen == n + 1) ? -1 : minLen);
}

int main() {
    int k;
    char str[100];

    scanf("%d", &k);
    scanf("%s", str);

    int n = strlen(str);
    NULLALL(); // Initialize the global array
    solve(str, k, n);

    return 0;
}
