#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct queue{
    int data[10];
    int pri[10];
    int front, rear, size;
};
struct queue q;
void enque(int ele, int prio)
{
    if(q.front==-1)
    {
        q.data[0]=ele;
        q.pri[0]= prio;
        q.front=0;
        q.rear=0;
        return;
    }
    else if(q.rear >= q.size - 1)
    {
        printf("queue is full\n");
        return ;
    }
    else{
        int i;
        
        for( i=q.rear; i>=q.front && q.pri[i]<prio; i--)
        {
            q.data[i+1]=q.data[i];
            q.pri[i+1]= q.pri[i];
        }
        q.data[i+1]=ele;
        q.pri[i+1]= prio;
        q.rear++;

    }

}

void dequeue()
{
    if(q.front==-1)
    {
        printf("queue is empty\n");
        return;
    }
    printf("poped, ele:%d prio:%d\n",q.data[q.front],q.pri[q.front]);
    q.front++;
}

void display()
{
    for(int i=q.front; i<= q.rear; i++)
    {
        printf("ele:%d  prio:%d\n",q.data[i],q.pri[i]);
    }

}
int main()
{
 
    q.size= 10;
    q.front= q.rear=-1;
    int n;
    printf("enter size\n");
    scanf("%d",&n);
    for(int i=0; i<n ;i++)
    {
        int ele,prio;
        scanf("%d %d",&ele,&prio);
        enque(ele,prio);
    }
    display();
    dequeue();
    dequeue();
    display();




}