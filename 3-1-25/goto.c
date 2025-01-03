#include <stdio.h>

int main() {
    int i, j;
    
    printf(" continue\n");
    for (i = 1; i <= 5; i++) {
        if (i == 3)
            continue;
        printf("%d ", i);
    }
    
    printf(" \ngoto:\n");
    i = 1;
    /* goto can be modiifed into using as loop and returning 0 is the exit*/
start:
    if (i > 5)
        return 0;
    if (i == 3) {
        i++;
        goto start;
    }
    printf("%d ", i);
    i++;
    goto start;
}
