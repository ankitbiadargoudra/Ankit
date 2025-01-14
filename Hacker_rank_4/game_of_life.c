#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char input[100];
    fgets(input, sizeof(input),stdin);
    char *token;

    int close=0;
    for(int i=2; i<strlen(input)-1; i++ )
    {
        if(input[i]==']')
        {
            close++;
        }
    }
    int row= close;


    token = strtok(input," ,[]");
    int num,temp[100],ind=0;
    while(token!=NULL)
    {
        sscanf(token,"%d",&num);
        temp[ind++]=num;
        token = strtok(NULL," ,[]");

    }

    int col = ind / row;

    ind =0;
    int arr[row][col];
    for (int i=0; i<row; i++)
    {
        for(int j=0; j<col ; j++)
        {
            arr[i][j]=temp[ind++];
        }
    }
    int ans[row][col];
    int newr[] = {-1,0,1,0,-1,-1,1,1};
    int newc[] = {0,1,0,-1,-1,1,1,-1};
    int count=0;
    for ( int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
         
              count =0;
            if(arr[i][j]==0)
            {
                for(int k=0; k<8; k++)
                {
                    
                    int newrow= i+newr[k];
                    int newcol= j+newc[k];
                    if(0<=newrow&& newrow<row&& newcol>=0 && newcol <col)
                    {
                        if(arr[newrow][newcol]==1)
                        {
                            count++;
                        }
                    }
                }
                if (count==3)
                {
                    ans[i][j]=1;
                }
                else {
                    ans[i][j]=0;
                }
            }
            else
            {
                for(int k=0; k<8; k++)
                {
                    
                    int newrow= i+newr[k];
                    int newcol= j+newc[k];
                    if(0<=newrow&& newrow<row&& newcol>=0 && newcol <col)
                    {
                        if(arr[newrow][newcol]==1)
                        {
                            count++;
                        }
                    }
                }
                if (count<2)
                {
                    ans[i][j]=0;
                }
                else if(count==2||count==3 )
                {
                    ans[i][j]=1;
                }
                else {
                    ans[i][j]=0;
                }

            }
        }
    }

    //print answer
    printf("[");
    for(int i=0; i<row; i++)
    {
        printf("[");
        for(int j=0; j<col; j++)
        {
            if(j==col-1)
            {
                printf("%d",ans[i][j]);
            }
            else {
                printf("%d ",ans[i][j]);
            }
        }
        if(i==row-1)
        {
            printf("]");
        }
        else {
            printf("],");
        }
    }
    printf("]");

}
