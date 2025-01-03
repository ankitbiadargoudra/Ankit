#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hi,I,am,Ankit,@,Intimetec";
    char *token;

    token = strtok(str, ",");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }
    
    return 0;
}
