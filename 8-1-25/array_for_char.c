#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    char **arr;
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    arr = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++) {
        arr[i] = (char *)malloc(100 * sizeof(char));
        printf("Enter string %d: ", i + 1);
        scanf("%s", arr[i]);
    }
    printf("Strings are:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
        free(arr[i]);
    }
    free(arr);
    return 0;
}
