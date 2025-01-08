#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>



int main() {
    char input[1000];
    fgets(input, sizeof(input), stdin);

    int r=0,c=0;
    int arr[10][10];
    int temp[100];
    int ind=0;
    char *ptr=input;
    while (*ptr) {
        if (isdigit(*ptr)) {
            int num;
            sscanf(ptr, "%d", &num);
            temp[ind++] = num;
            while (isdigit(*ptr)) {
                ptr++;
            }
           
        } else {
            ptr++;
        }
    }
    int spaces=0;
    for (int i=2;input[i]!=']'&&input[i]!='\0';i++) {
        if (input[i]==' ')spaces++;
    }
    c=spaces+1;
    r=ind/c;

    ind=0;
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            arr[i][j]=temp[ind++];
        }
    }
    // spiral
    
    int left=0, right=c-1;
    int top=0,bottom=r-1;
    int total=r*c;
    int count=0;
    int result[total];
    int index=0;

    while (count<total) {
        for (int i=left;count<total&&i<=right;i++) {
            result[index++]=arr[top][i];
            count++;
        }
        top++;
        
        
        for (int i=top;count<total&&i<=bottom;i++) {
            result[index++]=arr[i][right];
            count++;
        }
        right--;
        
        
        for (int i=right;count<total&&i>=left;i--) {
            result[index++]=arr[bottom][i];
            count++;
        }
        bottom--;
        
        
        for (int i=bottom;count<total&&i>=top;i--) {
            result[index++]=arr[i][left];
            count++;
        }
        left++;
        
        
    }
    printf("[");
    int flag =0;
    for (int i=0;i<total;i++) {
        if (flag)
        {
            printf(" ");
        }
        printf("%d",result[i]);
        flag  =1;
        
    }
    printf("]");

    return 0;
}