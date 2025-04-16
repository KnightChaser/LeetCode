#include <stdlib.h>

static int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int minMovesToSeat(int *seats, int seatsSize, int *students, int studentsSize) {
    // Sort both arrays
    qsort(seats, seatsSize, sizeof(int), compare);
    qsort(students, studentsSize, sizeof(int), compare);

    // Calculate how many moves are needed (students[i] want to sit in seats[i])
    int moves = 0;
    for (size_t i = 0; i < seatsSize; i++) {
        moves += abs(seats[i] - students[i]);
    }

    return moves;
}
