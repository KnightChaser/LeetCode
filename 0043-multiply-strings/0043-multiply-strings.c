#include <stdlib.h>
#include <string.h>

char *multiply(char *num1, char *num2) {
    // If either of the input strings is empty, return "0"
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    // If either number is "0", return "0"
    if ((len1 == 1 && num1[0] == '0') || (len2 == 1 && num2[0] == '0')) {
        char *result = (char *)malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    // Maximum length of the product is len1 + len2
    int *product = (int *)malloc((len1 + len2) * sizeof(int));
    memset(product, 0, (len1 + len2) * sizeof(int));

    // Multiply each digit from num1 with each digit from num2
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            // We multiply the digits and add the result to the product array
            int n1 = num1[i] - '0';
            int n2 = num2[j] - '0';
            int sum = product[i + j + 1] + n1 * n2;

            // The carry is added to the digit at i + j
            product[i + j + 1] = sum % 10;
            product[i + j] += sum / 10;
        }
    }

    // Skip any leading zeros
    int index = 0;
    while (index < len1 + len2 && product[index] == 0) {
        index++;
    }

    // Prepare the result string
    int resultLen = len1 + len2 - index;
    char *result = (char *)malloc((resultLen + 1) * sizeof(char));
    memset(result, 0, (resultLen + 1) * sizeof(char));
    for (int i = 0; i < resultLen; i++) {
        result[i] = product[index + i] + '0';
    }
    result[resultLen] = '\0'; // NULL-terminate the string

    free(product);
    return result;
}
