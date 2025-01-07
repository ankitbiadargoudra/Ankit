#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);  
    int len = strlen(input);
    
        
    int rows = 0, cols = 0;
    int matrix[100][100];  
    
   int tot_num=0;
     for (int i =2; i< len-2;i++ )
     {
         if (input[i]==']')
         {
             rows++;
         }
         if (isdigit(input[i]) )
         {
             tot_num++;
         }
     }
      cols = tot_num /rows;
   
   int r=0,c=0;
     for (int i =0; i< len-1;i++ )
     {
         if(isdigit(input[i]) )
         {
             matrix[r][c] = atoi(&input[i]);
             
             if (c==cols-1)
             {
                 r++;
                 c=0;
             }
             else{
                 c++;
             }
         }
     }
     
     int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;
    
    printf("[%d",matrix[top][left]);
    while (top <= bottom && left <= right)
    {
        
        for (int i = left; i <= right; i++) {
            if (left ==0 && top==0 && i==0)
            {
                continue;
            }
            printf(" %d", matrix[top][i]);
        }
        top++;
        
    
        for (int i = top; i <= bottom; i++) {
                printf(" %d", matrix[i][right]);
            }
            right--;
        
        if (top <= bottom) {
                
                for (int i = right; i >= left; i--) {
                    printf(" %d", matrix[bottom][i]);
                }
                bottom--;
                 }
        if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    printf(" %d", matrix[i][left]);
                }
                left++;
        }
    }
    printf("]");
 
}
