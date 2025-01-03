#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int isPrime(int n, int i) {
    if (i == 1)
        return 1;
    if (n % i == 0)
        return 0;
    return isPrime(n, i - 1);
}

void printPrimeFibonacci(int n) {
    if (n <= 0)
        return;
    int fib = fibonacci(n);
    if (fib > 1 && isPrime(fib, fib / 2))
        printf("%d ", fib);
    printPrimeFibonacci(n - 1);
}

int main() {
    int n ;
    scanf("%d",&n) ;
    printPrimeFibonacci(n);
    return 0;
}
