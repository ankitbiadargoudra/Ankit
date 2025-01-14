#include <string.h>
#include <stdio.h>
int main()
{ 
    char input[100];
    printf("Main string\n");
   fgets(input,sizeof(input),stdin);
   printf("Sub string:\n");
   char sub[10];
   fgets(sub,sizeof(sub),stdin);
    
    int len= strlen(input);
    int sublen=strlen(sub);
    
    int ind=-1;
    
    for (int i=0; i<len ; i++)
    {int j=0;
        for ( j=0; j<sublen;j++)
        {
            if (input[i+j]!=sub[j]){
                break;
            }
        }
        if(j==sublen-1)
        {
            ind =i;
            break;
        }
    }
    printf("%d",ind);
}
