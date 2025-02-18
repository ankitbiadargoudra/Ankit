#include<stdlib.h>
#include<stdio.h>

struct node{
    int val, count;
    struct node* next;

};

struct node* arr[10];

int hash(int key)
{
    return key%10;
}

void insert(int val)
{
    int index = hash(val);
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->val= val;
    new->count =1;
    new->next = NULL;
    struct node* temp = arr[index];
    if(temp==NULL)
    {
        arr[index]=new;
        return ;
    }
    int flag = 0;
    while(temp!=NULL)
    {
        if(temp->val==val)
        {
            temp->count++;
            free(new);
            return ;
        }
        temp = temp->next;
    }
    new->next= arr[index];
    arr[index]= new;
}

void delete(int val)
{
    int index = hash(val);
    struct node* temp = arr[index];
    while(temp!=NULL)
    {
        if(temp->val==val)
        {
            temp->count--;
            return;
        }
        temp = temp->next;
    }
}

unsigned int distinct()
{
    unsigned int count=0; 
    for(int i=0; i< 10; i++)
    {
        struct node*temp = arr[i];
        while(temp!=NULL)
        {
            if(temp->count>0)
            {
                count++;
            }
            temp = temp->next;
        }
    }
    return count;
}

void solve(int arr[], int k, int n)
{

    int start=0, last=k-1, dst=0;;
    for( int i=start; i<=last; i++)
    {
        insert(arr[i]);
    }
    while(last<n)
    {

        int num = distinct();
        printf("%d-", num);
        delete(arr[start]);
        start++;
        last++;
        insert(arr[last]);
    }
}

int main()
{
    int n , k ,ele;
    scanf("%d %d",&n,&k);
    int arr[n];
    for( int i=0; i<n ; i++)
    {
        scanf("%d",&arr[i]);
    }
    solve(arr,k,n);
}