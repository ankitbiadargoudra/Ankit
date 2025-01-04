
#include <stdio.h>
#include <stdlib.h>

struct Item {
    char *gun;
    int gun_cost;
};

int main() {
    int n;
    printf("Enter the number of guns: ");
    scanf("%d", &n);
    
    struct Item *items = (struct Item *)malloc(n * sizeof(struct Item));

    for (int i = 0; i < n; i++) {
        items[i].gun = (char *)malloc(sizeof(char));
        printf("Enter name of GUn : ");
        scanf("%s", items[i].gun);
        printf("Enter cost of Gun : ");
        scanf("%d", &items[i].gun_cost);
    }

    printf("\nGuns List:\n");
    for (int i = 0; i < n; i++) {
        printf("Guns %d: Gun = %s, Cost = %d\n", i + 1, items[i].gun, items[i].gun_cost);
        free(items[i].gun);
    }

    free(items);
}