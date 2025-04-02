#include <stdint.h>

int64_t modExp(int64_t base, int64_t exp, int64_t mod) {
    int64_t result = 1;
    base = base % mod; // Handle base larger than mod

    while (exp > 0) {
        // Checks if the LSB(Least Significant Bit) of exp is set
        // When a bit is 1, it means that particular power of 2 contributes to
        // the final exponentiation.
        if (exp & 1) {
            result = (result * base) % mod;
        }

        exp = exp >> 1;             // Divide exp by 2 (a -> a^2 -> a^4 -> ...)
        base = (base * base) % mod; // Square the base
    }
    return result;
}
int countGoodNumbers(long long n) {
    // Return the number of good numbers with modulo 10^9 + 7
    return modExp(4 * 5, n / 2, 1000000007) * (n % 2 ? 5 : 1) % 1000000007;
}
