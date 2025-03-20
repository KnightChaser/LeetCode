#include <limits.h>

int reverse(int x){
    int tmp = x;
    int reversedNum = 0;

    while (tmp != 0) {
        int digit = tmp % 10;
        tmp /= 10;

        if (reversedNum > (INT_MAX / 10) || (reversedNum == (INT_MAX / 10) && digit > 7)) {
            // We can't store the number larger than 2,147,483,647 in int32
            return 0;
        }
        if (reversedNum < (INT_MIN / 10) || (reversedNum == (INT_MIN / 10) && digit < -8)) {
            // We can't store the number smaller than -2,147,483,648 in int32
            return 0;
        }

        reversedNum = reversedNum * 10 + digit;
    }
    return reversedNum;
}