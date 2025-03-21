#include <math.h>

int countOdds(int low, int high){
    // Edge case: low and high are the same
    if (low == high) {
        if (low % 2 == 1) {
            return 1;
        } else {
            return 0;
        }
    }

    if (low % 2 == 1) {
        // If low number is odd -> number = floor((high - low) / 2) + 1
        return (high - low) / 2 + 1;
    } else {
        // If low number is even -> Subtract 1 from low to make it odd
        // Add 1 to the result to account for the odd number
        return (high - low - 1) / 2 + 1;
    }
}
