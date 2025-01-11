// C Program to find the maximum subarray sum using nested loops

#include <stdio.h>


int maxSubarraySum(int arr[], int size) {
    int maxSum = arr[0];
  
   
    for (int i = 0; i < size; i++) {
        int currSum = 0;
      
        
        for (int j = i; j < size; j++) {
            currSum = currSum + arr[j];
          
            
            if (currSum > maxSum) {
                maxSum = currSum;
            }
        }
    }
    return maxSum;
}

int main() {
    int n;
     printf("enter size\n");
     scanf("%d",&n);
     int arr[n];
    printf("enter elemtns\n");
    for(int i=0;i<n;i++)
    {
    scanf("%d",&arr[i]);
    }
    printf("%d", maxSubarraySum(arr, n));
    return 0;
}