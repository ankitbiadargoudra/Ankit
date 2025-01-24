#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    
    int n ;
    scanf("%d",&n);
    int cur =1;
    printf("%d",cur);
    n = n-1;
    for(int i=1; i<=n;i++)
    {
        cur  = cur *(n-i+1)/i;
        
        printf(",%d",cur);
    }
    
    return 0;
}
