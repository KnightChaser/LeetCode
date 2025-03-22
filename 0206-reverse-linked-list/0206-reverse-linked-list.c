/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdbool.h>

struct ListNode* reverseList(struct ListNode* head) {
    // If the list is empty or has only one element, return the list
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* previous = head;
    struct ListNode* current = head->next;
    struct ListNode* next = NULL;
    bool isOriginalHead = true;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
        if (isOriginalHead) {
            // For the original head, set the next to NULL
            head->next = NULL;
            isOriginalHead = false;
        }
    }

    // Now, the head is the last element of the list
    return previous;
}
