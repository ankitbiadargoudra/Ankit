#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char* name;
    int val;
    struct node* next;
};

struct node* arr[10]={NULL};

int hash (char * key)
{
    int index =0;
    while(*key)
    {
        index+= *key++;
    }
    printf("index = %d  ",index);
    return index %10;
}

void insert(char * name, int val)
{
    int index = hash(name);
    struct node* new = (struct node*)malloc(sizeof(struct node));
    new->name= strdup(name);
    new->val= val;
    struct node* temp = arr[index];
    new->next = temp;
    arr[index]= new;
}

void display()
{
    for(int i=0; i< 10; i++)
    {
        struct node* temp = arr[i];
        while(temp!= NULL)
            {
                printf("(%s->%d), ",temp->name, temp->val);
                temp = temp->next;

            }
            printf("\n");
    }
}


int main()
{
    char  str[100]="Ankit 1, Abhishek 2, Veeresh 3, Karthik 4, rahul 5";
    char * token;
    token = strtok(str, ",");
    while (token != NULL) {
        char name[20];
         int val;
        
        sscanf(token, " %s %d",name, &val);
        insert(name, val);
        token = strtok(NULL, ",");
    }
    display();

}