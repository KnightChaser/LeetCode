#include <stdbool.h>

bool lemonadeChange(int *bills, int billsSize) {
    int five = 0;
    int ten = 0;
    bool ok = true;

    for (int i = 0; i < billsSize; i++) {
        if (bills[i] == 5) {
            five++;
        } else if (bills[i] == 10) {
            if (five == 0) {
                ok = false;
                break;
            }
            five--;
            ten++;
        } else if (bills[i] == 20) {
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            } else if (five >= 3) {
                five -= 3;
            } else {
                ok = false;
                break;
            }
        }
    }

    return ok;
}
