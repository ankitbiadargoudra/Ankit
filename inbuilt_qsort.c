
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
void swap(int *a, int * b)
{
    int  temp = *a;
    *a= *b;
    *b = temp;
}
int  compare(const void *a,const void *b)
{
    return (*(int*)a- *(int *)b);
}
int main()
{
    
    int index=0,arr[100], flag=0;
    char input[100];
    fgets(input,sizeof(input),stdin);
    char * token;
    token= strtok(input," ");
    while(token!=NULL)
    {
        arr[index++]= atoi(token);
        token= strtok(NULL," ");
    }
   
   // mwrge sort
  
   qsort(arr,index,sizeof(int),compare);

   //display
   for(int i=0; i< index; i++)
   {
       printf("%d ",arr[i]);
   }
}
