#include <stdio.h>

int main() {
    long base, exp, mod;
    
 
    printf("Enter the base B: ");
    scanf("%ld", &base);
    
    
    printf("Enter the exponent N: ");
    scanf("%ld", &exp);
    
    printf("Enter the modulus M: ");
    scanf("%ld", &mod);
    
    long result = 0;  
    while (exp > 0) {  
        if (exp % 2 == 1) {  
            result = (result * base) % mod; 
        exp = exp / 2;  
        base = (base * base) % mod;  
    }
    
    // Output the result
    printf("Result: %ld\n", result);

    return 0;
}}
