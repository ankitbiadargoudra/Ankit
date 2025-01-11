#include <stdio.h>
#include <stdlib.h>


int* leaders(int arr[], int n, int* resSize) {
    int* result = (int*)malloc(n * sizeof(int));
    int count = 0;

    for (int i = 0; i < n; i++) {
        int j;
      
      
        for (j = i + 1; j < n; j++) {
          
          
            if (arr[i] < arr[j])
                break;
        }

     
        if (j == n) 
            result[count++] = arr[i];
    }

    *resSize = count;
    return result;
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
    int resSize;
    
    int* result = leaders(arr, n, &resSize);
    for (int i = 0; i < resSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    free(result);
    return 0;
}