#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int size;
    scanf("%d", &size);

    int matrix[size][size];

    for (int row = 0; row < size; row++) 
    {
        for (int coloum = 0; coloum < size; coloum++) 
        {
            scanf("%d", &matrix[row][coloum]);
        }
    }
    
      for (int row = 0; row < size; row++) 
    {
        for (int coloum = row+1; coloum < size; coloum++) 
        {
            int temp = matrix[row][coloum];
            matrix[row][coloum] = matrix[coloum][row];
            matrix[coloum][row] = temp;
        }
    }
    for (int row = 0; row < size; row++) 
    {
        for (int coloum = 0; coloum < size; coloum++) 
        {
            printf("%d", matrix[row][coloum]);
            if (coloum < size - 1) 
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}
