#include <stdio.h>
#include<string.h>
int main()
{
    int r,c;
    printf("Enter nuber of rows\n:");
    scanf ("%d",&r);
    printf("Enter NUmber of columns\n");
    scanf("%d",&c);
    char arr[r][c][50];
    printf("ENter the names:");
    for (int i=0; i<r;i++)
    {
        for  (int j=0;j<c;j++)
    {
        printf("Name at (%d,%d)",i,j);
        scanf("%s",arr[i][j]);
    }
    
    }
    
    int count =0,max=0,a,b;
    for (int i=0; i<r;i++)
    {
        for  (int j=0;j<c;j++)
    {
        printf("%s  ",arr[i][j]);
        if (arr[i][j][0]=='a'||arr[i][j][0]=='e'||arr[i][j][0]=='i'||arr[i][j][0]=='o'||arr[i][j][0]=='u')
        {
            count++;
        }
        if (max<strlen(arr[i][j]))
        {
            max = strlen(arr[i][j]);
            a=i;
            b=j;
        }
        
    }
    printf("\n");
    }
    
    printf("Number of string staring with vowel:%d\n",count);
    
    printf("The longest name %s\n",arr[a][b]);
        
    return 0;
}
