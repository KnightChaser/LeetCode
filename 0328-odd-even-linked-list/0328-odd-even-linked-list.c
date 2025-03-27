/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>

struct ListNode *oddEvenList(struct ListNode *head) {
    // If there is nothing to process, return NULL.
    if (head == NULL) {
        return NULL;
    }

    struct ListNode *odd = head;
    struct ListNode *even = head->next;
    struct ListNode *evenHead = even;

    // Until even is NULL or even->next is NULL,
    // Reconnect odd and even nodes one by one.
    while (even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    // Now, odd and even nodes are all connected each other.
    // Connect odd and evenHead to make a single list.
    odd->next = evenHead;

    return head;
}
