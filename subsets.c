#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void gen(int *arr, int sz, int idx, int *cur, int curSz, int **res, int *resSz, int *resColSz) {
    res[*resSz] = (int *)malloc(curSz * sizeof(int));
    for (int i = 0; i < curSz; i++) {
        res[*resSz][i] = cur[i];
    }
    resColSz[*resSz] = curSz;
    (*resSz)++;

    for (int i = idx; i < sz; i++) {
        cur[curSz] = arr[i];
        gen(arr, sz, i + 1, cur, curSz + 1, res, resSz, resColSz);
    }
}

int main() {
    char inp[100];
    scanf("%[^\n]", inp);
    getchar();

    int arr[15];
    int sz = 0;
    char *tok = strtok(inp, ",");
    while (tok != NULL) {
        arr[sz++] = atoi(tok);
        tok = strtok(NULL, ",");
    }

    qsort(arr, sz, sizeof(int), cmp);

    int **res = (int **)malloc((1 << sz) * sizeof(int *));
    int *resColSz = (int *)malloc((1 << sz) * sizeof(int));
    int resSz = 0;
    int *cur = (int *)malloc(sz * sizeof(int));

    gen(arr, sz, 0, cur, 0, res, &resSz, resColSz);

    printf("[");
    for (int i = 0; i < resSz; i++) {
        printf("[");
        for (int j = 0; j < resColSz[i]; j++) {
            printf("%d", res[i][j]);
            if (j < resColSz[i] - 1) printf(", ");
        }
        printf("]");
        if (i < resSz - 1) printf(", ");
    }
    printf("]\n");

    for (int i = 0; i < resSz; i++) {
        free(res[i]);
    }
    free(res);
    free(resColSz);
    free(cur);

    return 0;
}
