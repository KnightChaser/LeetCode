/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>

struct ListNode *swapPairs(struct ListNode *head) {
    // A dummy node so we never lose the real head
    struct ListNode dummy;
    dummy.next = head;

    // Pointer to the last node in the previous pair
    struct ListNode *prev = &dummy;

    struct ListNode *first, *second, *nextPair;

    // As long as there are two nodes ahead...
    while (prev->next != NULL && prev->next->next != NULL) {
        // e.g. 1->2->3->4

        first = prev->next;      // e.g. 1
        second = first->next;    // e.g. 2
        nextPair = second->next; // e.g. 3

        prev->next = second;    // dummy -> 2
        second->next = first;   // 2 -> 1
        first->next = nextPair; // 1 -> 3
        // List now looks like: dummy -> 2 -> 1 -> 3 -> 4
        // The pair (first, second) is swapped

        prev = first; // Advance prev to the end of the swapped pair
    }

    return dummy.next;
}
