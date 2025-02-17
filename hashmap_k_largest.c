#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

typedef struct {
    int key;
    int value;
} HashNode;

typedef struct {
    HashNode *table[MAX_CHAR];
} HashMap;

HashMap* createHashMap() {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    for (int i = 0; i < MAX_CHAR; i++) map->table[i] = NULL;
    return map;
}

void insert(HashMap* map, char key) {
    if (map->table[(int)key] == NULL) {
        map->table[(int)key] = (HashNode*)malloc(sizeof(HashNode));
        map->table[(int)key]->key = key;
        map->table[(int)key]->value = 1;
    } else {
        map->table[(int)key]->value++;
    }
}

void erase(HashMap* map, char key) {
    if (map->table[(int)key] != NULL) {
        map->table[(int)key]->value--;
        if (map->table[(int)key]->value == 0) {
            free(map->table[(int)key]);
            map->table[(int)key] = NULL;
        }
    }
}

int countDistinct(HashMap* map) {
    int count = 0;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (map->table[i] != NULL) count++;
    }
    return count;
}

int longestSubstringKDistinct(char *s, int K) {
    int maxLen = -1, left = 0;
    HashMap* map = createHashMap();
    for (int right = 0; s[right] != '\0'; right++) {
        insert(map, s[right]);
        while (countDistinct(map) > K) {
            erase(map, s[left]);
            left++;
        }
        if (countDistinct(map) == K) {
            int len = right - left + 1;
            if (len > maxLen) maxLen = len;
        }
    }
    free(map);
    return maxLen;
}

int main() {
    char s[100];
    int K;
    scanf("%s %d", s, &K);
    printf("%d\n", longestSubstringKDistinct(s, K));
    return 0;
}
