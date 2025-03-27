/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>

int pairSum(struct ListNode *head) {
    struct ListNode *p = head;
    int sumArray[100000] = {
        0,
    };
    int sumArrayIndex = 0;

    // First, move all the values to an array
    while (p != NULL) {
        sumArray[sumArrayIndex] = p->val;
        sumArrayIndex++;
        p = p->next;
    }

    // Second, calculate the pair sum and obtain the maximum summation
    int maxSum = 0;
    for (int i = 0; i < sumArrayIndex / 2; i++) {
        int sum = sumArray[i] + sumArray[sumArrayIndex - i - 1];
        if (sum > maxSum) {
            maxSum = sum;
        }
    }

    return maxSum;
}
