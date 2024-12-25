
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char ch, s[20],sen[100];
    scanf("%c",&ch);
    scanf("%s",s);
    getchar();
    scanf("%[^\n]",sen);
    printf("%c \n%s \n%s",ch,s,sen);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
