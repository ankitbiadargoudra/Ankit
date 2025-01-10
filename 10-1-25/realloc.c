#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int *)malloc(4 * sizeof(int)); // Allocates memory for 4 integers
    for (int i = 0; i < 4; i++) {
        printf("Value at ptr[%d]: %d\n", i, ptr[i]); // Prints garbage values
    }
     int *ptr1 = (int *)calloc(4, sizeof(int)); // Allocates and initializes memory to 0
    for (int i = 0; i < 4; i++) {
        printf("Value at ptr[%d]: %d\n", i, ptr1[i]); // Prints 0 for all elements
    }
    free(ptr);
    return 0;
}
