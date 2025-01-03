#include <stdio.h>
#include <string.h>
/*Still working on this*/
int main() {
    char str[] = "Hi,I,am,Ankit,@,Intimetec";
    char *token;
    char key[]="" ;
    scanf("%s",key);

    token = strtok(str, ",");
    while (token != NULL) {
        printf("%s\n", token);
        
        if (strcmp(key,token)==0)
        {
            printf("Found the @\n");
        }
        
        if(key==token)
        {
            printf("FOund again");
        }
        
        token = strtok(NULL, ",");
    }
    
    return 0;
}
