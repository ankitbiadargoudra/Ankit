#include <stdio.h>
#include <string.h>
#include <stdlib.h>
enum operation
{
    add = 1,
    complete,
    pending
};
enum status{
    PENDING=1,
    COMPLETE
};
struct node {
    char *str;
    enum status status;
    struct node* next;
};

struct node* head= NULL;

void insert(struct node** head, char * token)
{
    struct node* new= (struct node*)malloc(sizeof(struct node));
    new->str= strdup(token);
    new->status= PENDING;
    new->next = NULL;
    if(*head==NULL)
    {
        *head = new;
        return;
    }
    struct node* temp = * head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = new;

}
void comp(struct node**head , char *str)
{
    struct node* temp = *head;
    while(temp!= NULL)
    {
        if(strcmp(temp->str, str)==0)
        {
            temp->status= COMPLETE;
            return;
        }
        temp = temp->next;
    }
}
void display(struct node* head)
{
    int flag=0;
    struct node* temp = head;
    while(temp!=NULL)
    {
        if(temp->status==COMPLETE)
        {
            printf("%s\n", temp->str);
            flag=1;
            
        }
        temp = temp->next;
    }
    if(flag==0)
    {
        printf("No task pending\n");
    }
}

enum operation getoperation (char *str)
{
    if (strcmp(str,"add") == 0) return add;
    else if (strcmp(str, "complete")==0) return complete;
    else return pending;
}
int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t-- > 0)
    {
        char input[100];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        char *token;
        token = strtok(input, "<>");
        enum operation choice = getoperation(token);
        switch (choice)
        {
        case 1:
            token = strtok(NULL, "<>");
            if (token == NULL) {
                printf("Invalid input format1\n");
                break;
            }
            insert(&head,token);
            break;

        case 2:
            token = strtok(NULL, "<>");
            if (token == NULL) {
                printf("Invalid input format2\n");
                break;
            }
            comp(&head,token);
            break;

        case 3:
            display(head);
            break;

        default:
            printf("Enter correctly\n");
            break;
        }
    }
}
