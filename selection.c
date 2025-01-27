
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
void swap(int *a, int * b)
{
    int  temp = *a;
    *a= *b;
    *b = temp;
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
   
   // selection sort
   
   for(int i=0; i<index-1; i++)
   {    int  min =i;
       for(int j=i+1; j<index;j++)
       {
           if(arr[min]>arr[j])
           {
               min = j;
               
           }
       }
      
      swap(&arr[i],&arr[min]);
   }
   
   //display
   for(int i=0; i< index; i++)
   {
       printf("%d ",arr[i]);
   }
}
