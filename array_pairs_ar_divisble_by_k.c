#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key, count;
    struct node *next;
} node;

int hash(int key, int k)
{
    int index = key % k;
    return index;
}
node **createhashmap(int size)
{
    node **arr = (node **)malloc(size * sizeof(node *));
    for (int i = 0; i < size; i++)
    {
        arr[i] = (node *)malloc(sizeof(node));
        arr[i]->count = 0;
        arr[i]->key = i;
        arr[i]->next = NULL;
    }
    return arr;
}

void insert(node **arr, int val, int k)
{
    int index = hash(val, k);
    struct node *temp = arr[index];
    temp->count++;
}
void solve(node **arr, int k)
{
    int flag = 0;
    for (int i = 1; i <= k / 2; i++)
    {
        node *temp1 = arr[i];
        node *temp2 = arr[k - i];
        if (temp1->count != temp2->count)
        {
            flag = 1;
            printf("False\n");
            return;
        }
    }
    if (flag == 0)
    {
        printf("True\n");
        return;
    }
    

}
int main()
{

    printf("enter k \n");
    int k;
    scanf("%d", &k);
    node **map = createhashmap(k);
    int arr[10] = {9, 7, 5, 3};
    for (int i = 0; i < 5; i++)
    {
        insert(map, arr[i], k);
    }
    solve(map, k);

    // Free allocated memory
    for (int i = 0; i < k; i++)
    {
        free(map[i]);
    }
    free(map);
}
