#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key, val;
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
       arr[i]=NULL;
    }
    return arr;
}

void insert(node **arr, int val, int k)
{
    int index = hash(val, k);
    node* new = (node*)malloc(sizeof(node));
    new->val= val;
    new->key= index;
    new->next = arr[index];
    arr[index]= new;
    
}
void solve(node **arr, int k)
{
    int flag = 0;
    for (int i = 1; i <= k / 2; i++)
    {
        node *temp1 = arr[i];
        node *temp2 = arr[k - i];
        int count1=0, count2=0;
        while(temp1!=NULL)
        {
            temp1= temp1->next;
            count1++;
        }
        while(temp2!=NULL)
        {
            temp2= temp2->next;
            count2++;
        }
        printf("%d %d, \n",count1, count2);

        if (count1 != count2)
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
void display(node** arr, int k)
{
    for(int i =0; i<k ; i++)
    {
        node* temp = arr[i];
        while(temp!=NULL)
    {
        printf("(%d->%d) ",temp->key, temp->val);
        temp = temp->next;
    }
    }
}
int main()
{

    printf("enter k \n");
    int k;
    scanf("%d", &k);
    node **map = createhashmap(k);
    int arr[10] = {9, 7, 5, 3};
    for (int i = 0; i < 4; i++)
    {
        insert(map, arr[i], k);
    }
    solve(map, k);
    display(map,k);
    // Free allocated memory
    for (int i = 0; i < k; i++)
    {
        free(map[i]);
    }
    free(map);
}
