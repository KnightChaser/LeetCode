/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char** resultArray = malloc(sizeof(char*) * n);
    *returnSize = n;

    for (int num = 1; num <= n; num++) {
        if (num % 15 == 0) {
            // We have to do the null termination (+1 for NULL byte)
            resultArray[num - 1] = malloc(sizeof(char) * (strlen("FizzBuzz") + 1));
            strcpy(resultArray[num - 1], "FizzBuzz");
        } else if (num % 3 == 0) {
            resultArray[num - 1] = malloc(sizeof(char) * (strlen("Fizz") + 1));
            strcpy(resultArray[num - 1], "Fizz");
        } else if (num % 5 == 0) {
            resultArray[num - 1] = malloc(sizeof(char) * (strlen("Buzz") + 1));
            strcpy(resultArray[num - 1], "Buzz");
        } else {
            int tmp = num;
            int log10num = 0;

            // Determine the number of digits (log10)
            while (tmp != 0) {
                tmp /= 10;
                log10num++;
            }
            tmp = num;

            // Convert each digit of number into character one by one
            char* stringified = malloc(sizeof(char) * (log10num + 1));
            stringified[log10num] = '\0';
            int index = log10num - 1;
            while (tmp != 0) {
                stringified[index] = (char)(tmp % 10 + '0');
                tmp /= 10;
                index--;
            }
            
            resultArray[num - 1] = stringified;
        }
    }
    return resultArray;
}
