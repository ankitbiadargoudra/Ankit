#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "HelloWorld";
    memmove(str + 2, str, 5); // Safely move "Hello" to overlap
    printf("%s\n", str);      // Output: "HeHelloWorld"
   
   
   char src[] = "Hello";
    char dest[10];
    memcpy(dest, src, 5); // Copies "Hello" to dest
    
    printf("%s\n", dest); // Output: "Hello"
    return 0;
}
