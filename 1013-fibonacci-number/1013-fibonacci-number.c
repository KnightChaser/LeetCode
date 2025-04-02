#include <stdint.h>
#include <stdlib.h>

int fib(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return n;
    }

    int64_t *fibonacciTable = (int64_t *)calloc((n + 1), sizeof(int64_t));
    if (fibonacciTable == NULL) {
        return -1;
    }

    // Base case
    fibonacciTable[0] = 0;
    fibonacciTable[1] = 1;

    // Calculate Fibonacci numbers iteratively
    // instead of using recursion
    for (int i = 2; i <= n; i++) {
        fibonacciTable[i] = fibonacciTable[i - 1] + fibonacciTable[i - 2];
    }

    return fibonacciTable[n];
}
