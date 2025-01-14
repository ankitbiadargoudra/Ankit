#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<limits.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char input[100000];
    fgets(input,sizeof(input),stdin);
    char *token; 
   int max=INT_MIN;
    token= strtok(input,"[ ]");
    
      int arr[10000],num,ind=0;
    while(token!=NULL)
    {   
        sscanf(token,"%d",&num);
        arr[ind++]=num;
        
        token= strtok(NULL,"[ ]");
    }
    
    if (ind == 0) { 
        printf("0\n");
        return 0;
    }
    int cursum=0;
    for(int i=0;i<ind;i++)
    {
       if((cursum+arr[i])>arr[i])
       {
           cursum= cursum+ arr[i];
       }
       else{
           cursum = arr[i];
       }
       max = (max > cursum) ? max : cursum;
       
    }
    printf("%d",max);
    return 0;
}
