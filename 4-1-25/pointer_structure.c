
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char *gun;
    int gun_cost;
}Gunlist;

Gunlist *list[50];
int main() {
    int n ;
    printf("enter number");
    scanf("%d",&n);
    
    for (int i =0; i<n ; i++)
    {
        list[i] = (Gunlist*) malloc(sizeof(Gunlist));
        
        list[i]->gun = (char * )malloc(sizeof(char));
        printf("gun");
        scanf("%s",list[i]->gun);
        
        printf("price");
        scanf("%d",&list[i]->gun_cost);
        
    }
    
    printf(" guns list ");
    for (int i =0; i<n ; i++)
    {
      

        printf("%s\n",list[i]->gun);
        
        printf("%d\n",list[i]->gun_cost);
        
    }
    
}