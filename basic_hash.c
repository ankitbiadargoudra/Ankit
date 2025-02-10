#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int key, value;
    struct node* next;
}node;

struct node* hashtable[20];

int hashfunction(int key)
{
    return key%20;
}
void insert(int key , int value)
{
    int index = hashfunction(key);
    struct node* new= (struct node*)malloc(sizeof(struct node));
    new->key= key;
    new->value= value;
    new->next= hashtable[index];
    hashtable[index]= new;
}
int search(int key)
{
    int index= hashfunction(key);
    struct node* temp = hashtable[index];
    while(temp)
    {
        if(temp->key == key)
        {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

void delete(int key)
{
    int index = hashfunction(key);
    struct node* temp = hashtable[index];
    struct node* prev = NULL;
    while(temp)
    {
        if(temp->key==key)
        {
            if(prev)
            {
                prev->next = temp->next;
            }
            else{
                hashtable[index]= temp->next;
            }
            free(temp);
            return;

        }
        prev = temp;


        temp= temp->next;

    }
}

void display()
{
    for(int i=0; i<20; i++)
    {
        struct node* temp= hashtable[i];
        while(temp)
        {
            printf("(%d->%d) ",temp->key, temp->value);
            temp = temp->next;
        }
       
    }
}

int main()

{
    insert(1, 10);
    insert(2, 20);
    insert(11, 30); 
    insert(21,40);
    // Collision with key 1
    display();
    
    printf("Search key 2: %d\n", search(2));
    
    delete(1);
    display();
    
    return 0;
}