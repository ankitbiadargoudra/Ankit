// C Program to left rotate the array by d positions
// by rotating one element at a time

#include <stdio.h>

void rotateArr(int arr[], int n, int d) {
    for (int i = 0; i < d; i++) {
      
        
        int first = arr[0];
        for (int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = first;
    }
}

int main() {int n;
     printf("enter size\n");
     scanf("%d",&n);
     int arr[n];
    printf("enter elemtns\n");
    for(int i=0;i<n;i++)
    {
    scanf("%d",&arr[i]);
    }
    int d ;
    printf("enter position to shift\n");
    scanf("%d",&d);

    rotateArr(arr, n, d);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}