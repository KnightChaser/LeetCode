/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>

struct ListNode *deleteMiddle(struct ListNode *head) {
    // If the list is empty or has only one node, return NULL
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    // First, find the middle node
    struct ListNode *slowPrevious = NULL;
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slowPrevious = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Second, delete the middle node
    slowPrevious->next = slow->next;
    free(slow);

    return head;
}
