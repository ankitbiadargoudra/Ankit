#include <stdio.h>

// Function to compute GCD using the Euclidean Algorithm
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a, b;
    // Input two positive integers
    scanf("%d %d", &a, &b);
    
    // Output the GCD of a and b
    printf("%d\n", gcd(a, b));
    
    return 0;
}
