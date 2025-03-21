#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

double average(int* salary, int salarySize) {
    // Sort the salary array
    qsort(salary, salarySize, sizeof(int), cmp);

    // Sum all the salary except the first and last
    int salarySum = 0;
    for (int i = 1; i < salarySize - 1; i++) {
        salarySum += salary[i];
    }

    // Divide the sum by the number of salary except the first and last
    return (double)salarySum / (salarySize - 2);
}
