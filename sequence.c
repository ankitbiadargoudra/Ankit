#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void generate(int n, int k, int start, int *cc, int find) {
    if (find == k) {
        for (int i = 0; i < k; i++) {
            printf("%d", cc[i]);
            if (i < k - 1) printf(" ");
        }
        printf("\n");
        return;
    }

    for (int i = start; i <= n; i++) {
        cc[find] = i;
        generate(n, k, i + 1, cc, find + 1);
    }
}

int main() {
    int k, n;
    scanf("%d %d", &k, &n);

    int cc[k];
    generate(n, k, 1, cc, 0);

    return 0;
}
