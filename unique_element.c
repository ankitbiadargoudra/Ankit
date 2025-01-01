#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char sen[200], *first = NULL;
    
    
    fgets(sen, 200, stdin);
    sen[strcspn(sen,"\n")]='\0';

    char *token = strtok(sen, " ");
    char *words[200];
    int w = 0;

   
    while (token != NULL) {
        words[w++] = token;
        token = strtok(NULL, " ");
    }

    int flag;
    for (int i = 0; i < w; i++) {
        flag = 1; 
        for (int j = 0; j < w; j++) {
            if (i != j && strcmp(words[i], words[j]) == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) 
        { 
            first = words[i];
            break;
        }
    }

    // Print the result
    if (first != NULL) {
        printf("%s", first);
    } else {
        printf(" ");
    }

    return 0;
}
