#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Compare functions for two points' x coordinate values
int compare(const void *p1, const void *p2) {
    int *p1x = *(int **)p1;
    int *p2x = *(int **)p2;
    if (p1x[0] > p2x[0]) {
        return 1;
    } else {
        return -1;
    }
}

bool checkStraightLine(int **coordinates, int coordinatesSize,
                       int *coordinatesColSize) {
    // Sort the coordinates by x
    qsort(coordinates, coordinatesSize, sizeof(int *), compare);

    // Debug: print coordinates array
    // for (int i = 0; i < coordinatesSize; i++) {
    //     printf("%d %d\n", coordinates[i][0], coordinates[i][1]);
    // }

    // Edge case: if all points are on the same horizontal line
    bool isHorizontal = true;
    for (int i = 1; i < coordinatesSize; i++) {
        if (coordinates[i][1] != coordinates[i - 1][1]) {
            isHorizontal = false;
            break;
        }
    }
    if (isHorizontal) {
        return true;
    }

    // Edge case: if all points are on the same vertical line
    bool isVertical = true;
    for (int i = 1; i < coordinatesSize; i++) {
        if (coordinates[i][0] != coordinates[i - 1][0]) {
            isVertical = false;
            break;
        }
    }
    if (isVertical) {
        return true;
    }

    // If all points are on the same line, the slope between the first point
    // and the second point should be the same as the slope between the seconud
    double expectedSlope = (double)(coordinates[1][1] - coordinates[0][1]) /
                           (coordinates[1][0] - coordinates[0][0]);
    bool onOneLine = true;

    for (int i = 2; i < coordinatesSize; i++) {
        double slope = (double)(coordinates[i][1] - coordinates[i - 1][1]) /
                       (coordinates[i][0] - coordinates[i - 1][0]);
        if (slope != expectedSlope) {
            onOneLine = false;
            break;
        }
    }

    return onOneLine;
}
