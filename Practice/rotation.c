#include <string.h>
#include <stdio.h>
int main()
{ 
    char input[100];
    printf("Main string\n");
   scanf("%s",input);
   printf("Second string:\n");
   char sub[100];
   scanf("%s",sub);
    
    int len= strlen(input);
    printf("string len:%d\n",len);
    int ind =0;
    
    for (int i=0; i<len;i++)
    {   int j=0;
        int count=0;
        ind =i;
         for (j=0; j<len ; j++)
        {
            
            if (sub[ind]==input[j])
            {
               
                count++;
                
                ind = (ind+1)%len;
                
            }
            else{
                break;
            }
        }
        if (j>=len-1)
        {
            printf("true");
            return 0;
        }
    }
    printf("false");
    
}
