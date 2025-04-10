#include <math.h>
#include <stdbool.h>

bool isPowerOfFour(int n) {
    if (n <= 0) {
        return false;
    }

    double epsilon = 1e-10;
    double x = log10(n) / log10(4);
    return fabs(x - round(x)) < epsilon;
}
