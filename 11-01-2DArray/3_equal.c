// C program to find if the array can be divided into
// three segments by finding all possible partitions

#include <stdio.h>
#include<stdlib.h>

int findSum(int *arr, int start, int end) {
    int sum = 0;
    for(int i = start; i <= end; i++) 
        sum += arr[i];
    return sum;
}

int* findSplit(int *arr, int n) {
    int *res = (int *)malloc(2 * sizeof(int));
    res[0] = -1;
    res[1] = -1;
    

    for(int i = 0; i < n - 2; i++) {
        
       
        for(int j = i + 1; j < n - 1; j++) {
            
            
            int sum1 = findSum(arr, 0, i);
            int sum2 = findSum(arr, i + 1, j);
            int sum3 = findSum(arr, j + 1, n - 1);
          
            if(sum1 == sum2 && sum2 == sum3) {
                res[0] = i;
                res[1] = j;
                return res;
            }
        }
    }

   
    return res;
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
    int *res = findSplit(arr, n);
    
    printf("%d %d", res[0], res[1]);

    return 0;
}