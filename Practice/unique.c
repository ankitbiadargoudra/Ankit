#include <string.h>
#include <stdio.h>
int main()
{
    char arr[100];
    scanf("%s",arr);
    
   int  len = strlen(arr);
    int count[20]={0};
for(int i=0; i<len;i++)
{
    for (int j=i+1;j<len;j++)
    {
        if (arr[i]==arr[j])
        {
            count[j]=1;
        }
    }
}

for (int i=0;i<len;i++)
{
    if (count[i]==0)
    {
        printf("%c ",arr[i]);
    }
    
}
}
