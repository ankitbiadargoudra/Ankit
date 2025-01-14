#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int main()
{
    char input[100];
    fgets(input,sizeof(input),stdin);
    
    char *token;
    char lon[100],temp[100];
    int max= INT_MIN;
    token = strtok(input," \" ");
    while(token != NULL)
    {
        sscanf(token,"%s",temp);
        int len = strlen(temp);
        if (len>max){
            max=len ;
            strcpy(lon,temp);
        }
        token = strtok(NULL," \" ");
        
    }
    printf("%s",lon);
    

}