#include <stdio.h>
int main()
{
    int rowSize, columnSize, stringLength = 100;
    printf("enter size of string: ");
    scanf("%d%d", &rowSize, &columnSize);
    char stringMatrix[rowSize][columnSize][stringLength];
    printf("Enter %d strings: ",rowSize*columnSize);
    getchar();
    for(int row = 0; row < rowSize; row++)
    {
        for(int column = 0; column < columnSize; column++)
        {
            // add input reading logic. 
            scanf("%[^,\n]%*c",stringMatrix[row][column]);
        }
    }
    for(int row = 0; row < rowSize; row++)
    {
        for(int column = 0; column < columnSize; column++)
        {
            printf("name[%d][%d]: %s\n", row, column, stringMatrix[row][column]);
        }
    }
}