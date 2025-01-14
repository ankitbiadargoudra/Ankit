#include <string.h>
#include <stdio.h>
int main()
{ 
    char input[100];
   fgets(input,sizeof(input),stdin);
   char *token;
   int count=0;
   token = strtok(input," ");
   while(token!=NULL)
   {
       count++;
       token= strtok(NULL," ");
   }
   printf("%d",count);
}
