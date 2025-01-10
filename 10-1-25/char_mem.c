#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char arr[4][10]={
            "ankit",
            "Naresh",
            "Aditya",
            "Rohit" 
    };
for(int i =0;i<4;i++)
{
  printf("%s\n",arr[i]);
}
for(int i =0;i<4;i++)
{
  printf(" %c\n",arr[i][0]);
}

}