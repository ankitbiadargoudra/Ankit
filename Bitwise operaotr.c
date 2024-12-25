
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.

    int max_and=0, max_or=0, max_xor=0;
    int cur_and, cur_or, cur_xor;
    for (int i=1; i<n ; i++)
    {
        for (int j =i+1;j<=n;j++)
        {

            cur_and = i&j;
            cur_or= i|j;
            cur_xor=i^j;


            if (cur_and>max_and && cur_and < k)
            {
                max_and = cur_and;

            }
            if (cur_or>max_or && cur_or < k)
            {
                max_or = cur_or;

            }
            if (cur_xor > max_xor && cur_xor < k)
            {
                max_xor = cur_xor;

            }


        }

    }
    printf("%d\n%d\n%d",max_and,max_or,max_xor);
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}
