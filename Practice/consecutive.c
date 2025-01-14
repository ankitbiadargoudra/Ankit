
#include <stdio.h>
# include<string.h>

int main()
{
    char  str[100];
    scanf(" \"%[^\"] \"",str);
    char temp[100] ="";
    
    char countstr[10];
    int n = strlen(str);
    for (int i=0; i<n ; i++)
    {
        int count=1;
        while(str[i]==str[i+1] && i<n-1)
        {
            count++;
            i++;
        }
        strncat(temp,&str[i],1);
        sprintf(countstr,"%d",count);
        strcat(temp,countstr);
        
    }
    if (strlen(temp)<strlen(str))
    {
            printf("%s",temp);
    }
    else{
        printf("\"%s\" ",str);
    }
    

    return 0;
}