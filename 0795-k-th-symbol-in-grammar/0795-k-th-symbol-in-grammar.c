int kthGrammar(int n, int k) {
    // Base case: if n is 1, the only possible value is 0
    if (n == 1) {
        return 0;
    }

    int half = 1 << (n - 2); // Calculate 2^(n-2)
    if (k <= half) {
        // If k is in the first half, 
        // the value is the same as in the previous row
        return kthGrammar(n - 1, k);
    } else {
        // If k is in the second half, 
        // the value is the opposite of the previous row
        return 1 - kthGrammar(n - 1, k - half);
    }
}
