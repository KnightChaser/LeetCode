double myPow(double x, int n) {
    long long exponent = n;
    if (exponent < 0) {
        // x^(-n) = 1 / x^n
        x = 1 / x;
        exponent = -exponent;
    }

    double result = 1.0;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            // x^n = x * (x^((n-1)/2))^2 if n is odd
            result *= x;
        }
        // x^n = (x^(n/2))^2 if n is even
        x *= x;
        exponent /= 2;
    }

    return result;
}
