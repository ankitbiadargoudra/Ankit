#include <stdio.h>
#include <string.h>

int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);

    char *token;
    token = strtok(input, "[ ]");
    int arr[1000], ind = 0, num;
    while (token != NULL) {
        sscanf(token, "%d", &num);
        arr[ind++] = num;
        token = strtok(NULL, "[] ");
    }

    int n = ind;

    // Sort the array
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    int indexes[1000][3], s = 0;
    for (int i = 0; i < n; i++) {
        // Skip duplicates for arr[i]
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }

        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            if (arr[i] + arr[j] + arr[k] == 0) {
                indexes[s][0] = i;
                indexes[s][1] = j;
                indexes[s][2] = k;
                s++;

                j++;
                k--;

                // Skip duplicates for arr[j]
                while (j < k && arr[j] == arr[j - 1]) {
                    j++;
                }

                // Skip duplicates for arr[k]
                while (j < k && arr[k] == arr[k + 1]) {
                    k--;
                }
            } else if (arr[i] + arr[j] + arr[k] < 0) {
                j++;
            } else {
                k--;
            }
        }
    }

    // Print the results
    printf("[");
    for (int i = 0; i < s; i++) {
        if (i != 0) {
            printf(",");
        }
        printf("[");
        for (int j = 0; j < 3; j++) {
            if (j != 0) {
                printf(" ");
            }
            printf("%d", arr[indexes[i][j]]);
        }
        printf("]");
    }
    printf("]");
    return 0;
}
