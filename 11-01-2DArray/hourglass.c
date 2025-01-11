#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int arr[6][6];
    for (int i=0; i<6;i++)
    {
        for (int j=0; j<6 ; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int temp[6][6]={0};
    int max=-2147483648;
     for (int i=1; i<5;i++)
    {
        for (int j=1; j<5 ; j++)
        {
            temp[i][j]= (arr[i][j]+arr[i-1][j]+arr[i+1][j]+arr[i-1][j-1]+arr[i-1][j+1]+arr[i+1][j-1]+arr[i+1][j+1]);
            if(max<temp[i][j]){
                max = temp[i][j];
                
            }
        }
    }
    printf("%d",max);
}
