int fib(int n) {
    // Base case
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 1;
    }

    // Calculate Fibonacci numbers iteratively
    // Note that F(n) = F(n-1) + F(n-2)
    int result = 0;
    int i = 2;
    int n1 = 1, n2 = 1; // F(1) = 1, F(2) = 1
    while (i < n) {
        result = n1 + n2; // F(i) = F(i-1) + F(i-2)
        n1 = n2;          // Update F(i-1)
        n2 = result;      // Update F(i)
        i++;
    }

    return result;
}
