
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

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
    int key ;
    printf("\n Enter element\n");
    scanf("%d",&key);
   
   // binary  search
  int low =0, high = index-1, mid = (low+high)/2;
  
  while(low<high)
  {
       mid = (low+high)/2;
      if(arr[mid]==key)
      {
          printf("Key found");
          return 0;
      }
      else if(arr[mid]<key)
      {
          low = mid+1;
      }
      else{
          high = mid -1;
      }
  }
  printf("not found!");
  return 0;
  
  
  
  
  
}
