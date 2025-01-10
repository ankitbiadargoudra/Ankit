/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>

int main()
{
    int **arr;
    int r =3, c=3;
    arr =  (int**)malloc(r*sizeof(int*));
    for ( int i=0; i<r ;i++)
    {
        arr[i]= (int*)malloc(c*sizeof(int));
        
        for(int j=0; j<c;j++)
        {
        scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<r;i++)
    {
        for (int j=0; j<c ;j++)
        {
            printf("%d",arr[i][j]);
        }
        
    }
    
    
    
    
}
