#define MOD 1000000007 // 10^9 + 7

// Fast Modular Exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod; // Handle the case when base is greater than mod

    while (exp > 0) {
        // If exp is odd, multiply base with result
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }

        // exp must be even now
        exp = exp >> 1;             // Divide exp by 2
        base = (base * base) % mod; // Square the base
    }

    return result;
}

int monkeyMove(int n) {
    // First, calculate 2^n % MOD
    long long exp = modExp(2, n, MOD);

    // Then, subtract 2 from the result.
    // Note that we need to handle the case when exp is less than 2
    long long answer = (exp - 2 + MOD) % MOD;

    return (int)answer;
}
