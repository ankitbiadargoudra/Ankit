
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{

    int n;
    scanf("%d", &n);
    int size = n+n -1;
  	// Complete the code to print the pattern.
     for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            // Calculate the minimum distance to the nearest edge
            int min = i < j ? i : j;
            min = min < (size - j - 1) ? min : (size - j - 1);
            min = min < (size - i - 1) ? min : (size - i - 1);

            printf("%d ", n - min);
        }
        printf("\n");
    }

}
