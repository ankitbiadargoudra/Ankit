#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void solve(char* str)
{
    int hour, min;
    char ampm[3];
    sscanf(str,"%d:%d %s",&hour,&min,ampm);
    if(strcmp(ampm,"am")==0)
    {
        if(hour==12)
        {
            hour =0;
        }
    }
    else{
        if(hour==12)
        {

        }
        else{
            hour = hour+12;
        }

    }

    printf("%s->%02d:%02d\n",str,hour,min);

}


int main()
{
    char str[100];
    char input[100][100];
    scanf("%[^\n]",str);
    int index=0;
    char* token = strtok(str, ",\"\n");
    while(token!=NULL)
    {
        strcpy(input[index],token);
        index++;
        token = strtok(NULL, ",\"\n");
    }
    printf("\n");
    

    for(int i=0; i<index; i++)
    {
        solve(input[i]);
    }



}