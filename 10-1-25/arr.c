#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int arr[4][10]={
            {1, 2,3 ,4},
              {1, 2,3 ,4  },
                {1, 2,3 ,4  },
                  {1, 2,3 ,4  }
                   
    };
for(int i =0;i<4;i++)
{
  printf("%d\n",*arr[i]);
}

}