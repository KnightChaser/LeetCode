#include <stdbool.h>

bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n) {
    int possiblePlant = 0;

    // Edge case: flowerbed is empty
    if (flowerbedSize == 1) {
        if (flowerbed[0] == 0 && n == 1) {
            return true;
        } else if (flowerbed[0] == 1 && n == 0) {
            return true;
        } else if (flowerbed[0] == 0 && n == 0) {
            return true;
        } else {
            return false;
        }
    }

    for (int i = 0; i < flowerbedSize; i++) {
        // Greedy approach: plant a flower if possible
        if (flowerbed[i] == 0) {
            // Edge case: first element
            if (i == 0) {
                // It may be possible to plant a flower
                if (flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    possiblePlant++;
                }
                continue;
            }

            // Edge case: last element
            if (i == flowerbedSize - 1) {
                // It may be possible to plant a flower
                if (flowerbed[i - 1] == 0) {
                    flowerbed[i] = 1;
                    possiblePlant++;
                }
                continue;
            }

            // It may be possible to plant a flower
            if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                possiblePlant++;
            }
        }
    }

    // If possblePlant(number of flowers can be planted) is greater than or
    // equal to n, we can plant n flowers at the given flowerbed
    return possiblePlant >= n;
}
