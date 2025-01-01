#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n;
    scanf("%d",&n);
    int hotel[n];
    for (int i=0; i<n ; i++)
    {
        scanf("%d",&hotel[i]);
    }
    
    int *zeros =    hotel;
    int *ones = hotel;
    int *twos = hotel+n-1;
    
    while(ones<=twos)
    {
        if(*ones==0)
        {
            int temp = *zeros;
            *zeros = *ones;
            *ones = temp;
            
            zeros++;
            ones++;
        }
        else if(*ones ==1)
        {
            ones++;
        }
        else
        {
            int temp = *twos;
            *twos = *ones;
            *ones = temp;
            
            twos--;
            
        }
        
    }
   for (int i=0; i<n ; i++)
    {
        printf("%d\n",hotel[i]);
    }
    
    
    return 0;
}
