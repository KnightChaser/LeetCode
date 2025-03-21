#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int calPoints(char** operations, int operationsSize) {
    int* scoreArray = malloc(sizeof(int) * operationsSize);
    memset(scoreArray, 0, sizeof(int) * operationsSize);
    int index = 0;

    for (int i = 0; i < operationsSize; i++) {
        if (operations[i][0] == '-' || (operations[i][0] >= '0' && operations[i][0] <= '9')) {
            // Add new score
            scoreArray[index++] = atoi(operations[i]);
        } else if (operations[i][0] == 'C') {
            // Invalidate previous score; ensure index > 0 (though constraints say it always is)
            if (index > 0) {
                scoreArray[--index] = 0;
            }
        } else if (operations[i][0] == 'D') {
            // Double previous score
            if (index > 0) {
                scoreArray[index++] = scoreArray[index - 1] * 2;
            }
        } else if (operations[i][0] == '+') {
            // Sum previous two scores
            if (index >= 2) {
                scoreArray[index++] = scoreArray[index - 1] + scoreArray[index - 2];
            }
        }
    }

    int totalScore = 0;
    for (int i = 0; i < index; i++) {
        totalScore += scoreArray[i];
    }
    free(scoreArray);
    return totalScore;
}

