#include <stdbool.h>

int recursiveElimination(int n, bool isLeft) {
    // Base case: if there's only one number left, return it
    if (n == 1) {
        return 1;
    }

    // When eliminating from the left
    if (isLeft == true) {
        return 2 * recursiveElimination(n / 2, false);
    }

    // When eliminating from the right
    else {
        if (n % 2 == 0) {
            return 2 * recursiveElimination(n / 2, true) - 1;
        } else {
            return 2 * recursiveElimination(n / 2, true);
        }
    }
}

int lastRemaining(int n) { return recursiveElimination(n, true); }
