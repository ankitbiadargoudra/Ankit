#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char str1[100], str2[100];
    scanf( "\"%[^\"]\", \"%[^\"]\"",str1,str2);
   
int len = strlen(str1);

int flag =0;
for (int i=0;i<len; i++)
{
    flag =0;
for (int j=0;j<len; j++)
{
 if (str1[i]==str2[j])
 {
     flag =1;
 }

}
 if (flag==0)
 {
     printf("false\n");
     return 0;
 }
}
printf("true\n");
return 0;

}