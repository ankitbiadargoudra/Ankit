#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    char sen[100];
    fgets(sen, 100, stdin);
    
    char *words[100]; 
    int word_count = 0;
    
    char *token = strtok(sen, " ");
    while (token != NULL) {
        words[word_count++] = token; 
        token = strtok(NULL, " ");
    }
     for (int i = word_count - 1; i >= 0; i--) {
        printf("%s", words[i]);
        if (i > 0) {
            printf(" ");
    }}
    
}
