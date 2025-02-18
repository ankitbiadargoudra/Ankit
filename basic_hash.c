#include<stdio.h>
#include<stdlib.h>

struct node {
    int val, count;
    struct node* next;

};

struct node* arr[10]={NULL};

int hash(int key)
{
    return key%10;
}

void insert(int ele)
{
    int index= hash(ele);
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    newnode->val= ele;
    newnode-> count=1;
    newnode->next = NULL;
    struct node* temp = arr[index];
    if(temp==NULL)
    {
        arr[index]=newnode;
    }
    while(temp!=NULL)
    {   
        if(temp->val ==ele)
        {
            temp->count++;
        }
        temp = temp->next;
    }

}

void display()
{
    for(int i=0; i<10 ; i++)
    {
        struct node*temp= arr[i];
        while(temp!=NULL)
        {
            printf("%d->%d\n",temp->val,temp->count);
            temp = temp->next;
        }
    }
}
int main()
{
    int n,ele;
    scanf("%d",&n);
    for(int i=0; i<n ; i++)
    {
        scanf("%d",&ele);
        insert(ele);
    }
    display();
}