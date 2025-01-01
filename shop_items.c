#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct item_t
{
    char *item_name;
    int item_cost;
} item;


item *cart[100];

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,tot=0, count[100]={0};
    scanf("%d",&n);
    for (int i=0; i<n ; i++)
    {
        cart[i] = (item *)malloc(sizeof(item));
        cart[i]->item_name = (char *)malloc(100 * sizeof(char)); 
          scanf("%[^,],%d", cart[i]->item_name, &cart[i]->item_cost); 
    }
    printf("item list");
      for (int i=0; i<n ; i++)
    {
       printf("%s,%d", cart[i]->item_name, cart[i]->item_cost);
         tot = tot +cart[i]->item_cost;
        
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (strcmp(cart[i]->item_name, cart[j]->item_name) == 0) {
                count[i]++;
                if (i != j) {
                    count[j] = -1; 
                }
            }
        }
    }
    
    printf("\nTotal cost %d",tot);
   printf("\nitem quantities");
      for (int i = 0; i < n; i++) {
        if (count[i] >0) {
            printf("%s - %d", cart[i]->item_name, count[i]);
        }
    }
    return 0;
}