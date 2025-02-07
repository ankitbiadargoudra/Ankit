#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum Complexity {
    ONE,
    LOG_N,
    N,
    N_LOG_N,
    N_POW_2,
    TWO_POW_N,
    FACTORIAL_N
}Complexity;


typedef struct Node{
    Complexity tc;
    Complexity sc;
    struct Node* next;
}Node;

void assign(Complexity *val, char *str1)
{
    if (strcmp(str1, "O(1)") == 0) *val = ONE;
    else if (strcmp(str1, "O(logn)") == 0) *val = LOG_N;
    else if (strcmp(str1, "O(n)") == 0) *val = N;
    else if (strcmp(str1, "O(nlogn)") == 0) *val = N_LOG_N;
    else if (strcmp(str1, "O(n^2)") == 0) *val = N_POW_2;
    else if (strcmp(str1, "O(2^n)") == 0) *val = TWO_POW_N;
    else if (strcmp(str1, "O(n!)") == 0) *val = FACTORIAL_N;
    else *val = ONE; // Default case
}




void takeinput(Node** head)
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n ; i++)
    {
        char str1[50],str2[50];
        scanf("%s %s",str1,str2);
   
    Node* newnode =(Node*) malloc(sizeof(Node));
    newnode->next= NULL;

    assign(&(newnode->tc),str1);
    assign(&(newnode->sc),str2);
    if(*head==NULL)
    {
        *head= newnode;
    }
    else{
    Node* temp = *head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next=newnode;
    }
    }
}


int compare(Complexity a, Complexity b, Complexity c, Complexity d)
{
    if(a<b)
    {
        return 0;
    }
    else if(a>b)
    {
        return 2;
    }
    else{
        if(c<d)
        {
            return 0;
        }
        else{
            return 2;
        }
    }
}
void swap(Node* one, Node* two)
{
    if (one == NULL || two == NULL) return;
    Complexity temp = one->tc;
    one->tc = two->tc;
    two->tc = temp;

    temp = one->sc;
    one->sc= two->sc;
    two->sc= temp;
}
void sort ( Node** head)
{
    if(*head==NULL || (*head)->next==NULL) return ;

    struct Node*temp1 = *head;
    while(temp1!=NULL && temp1->next!=NULL)
    {
        struct Node*temp2= temp1->next;
        struct Node*min = temp1;
        while(temp2 !=NULL)
        {
            int status= compare(min->tc,temp2->tc, min->sc, temp2->sc);
            if(status==2)
            {
                min=temp2;
            }
            
            temp2= temp2->next;
        }
        swap(temp1,min);
        temp1= temp1->next;

    }
}

const char * getval(Complexity val)
{
    if (val == 0) return "1";
    else if (val == 1) return "logn";
    else if (val == 2) return "n";
    else if (val == 3) return "nlogn";
    else if (val == 4) return "n^2";
    else if (val == 5) return "2^n";
    else if (val == 6) return "n!";
    return "Unknown"; // Default case

}
void printlist(Node* head)
{
    Node*temp = head;
    while(temp!=NULL)
    {
        printf("%s %s\n",getval(temp->tc),getval(temp->sc));

        temp = temp->next;
    }
}
int main()
{
    Node* head = NULL;
    takeinput(&head);
    sort(&head);
    printlist(head);
}
