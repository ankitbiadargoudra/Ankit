
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
void twoPointerSum(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    
    while (low < high) {
        int sum = arr[low] + arr[high];
        
        if (sum == target) {
            printf("Pair found: %d and %d\n", arr[low], arr[high]);
            return;
        }
        else if (sum < target)
            low++;
        else
            high--;
    }
    
    printf("No pair found\n");
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
    int key ;
    printf("\n Enter element\n");
    scanf("%d",&key);
   
   // two pointers sum  
 twoPointerSum(arr, index, key);
  
  
  
  
  
}
