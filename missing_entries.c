#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LOG_SIZE 100000
#define MAX_ACTION_LENGTH 101
#define HASH_TABLE_SIZE 50000

typedef struct Node {
    char word[MAX_ACTION_LENGTH];
    int count;
    struct Node* next;
} Node;

Node* hashTable[HASH_TABLE_SIZE];

unsigned int hashFunction(char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31) + *str++;
    }
    return hash % HASH_TABLE_SIZE;
}

void insertOrUpdate(char* word) {
    unsigned int index = hashFunction(word);
    Node* temp = hashTable[index];

    while (temp) {
        if (strcmp(temp->word, word) == 0) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

void printBelowThreshold(int threshold) {
    int first = 1;
    printf("[");
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Node* temp = hashTable[i];
        while (temp) {
            if (temp->count < threshold) {
                if (!first) {
                    printf(", ");
                }
                printf("\"%s\"", temp->word);
                first = 0;
            }
            temp = temp->next;
        }
    }
    printf("]\n");
}

int main() {
    char input[MAX_LOG_SIZE * MAX_ACTION_LENGTH];
    int threshold;

    scanf("%[^\n]%*c", input);
    char* token = strtok(input, " ");
    while (token != NULL) {
        insertOrUpdate(token);
        token = strtok(NULL, " ");
    }

    scanf("%d", &threshold);
    printBelowThreshold(threshold);
    return 0;
}
