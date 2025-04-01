/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode *removeElements(struct ListNode *head, int val) {
    // If the list is empty, return NULL
    if (head == NULL) {
        return NULL;
    }

    struct ListNode *current = head;

    while (current != NULL && current->next != NULL) {
        if (current->next->val == val) {
            // If the next node's value is equal to val, remove it
            struct ListNode *temp = current->next;
            current->next = current->next->next; // Skip the node
            free(temp);                          // Free the removed node
        } else {
            // Advance to the next node
            current = current->next;
        }
    }

    // If the head node itself needs to be removed too
    if (head->val == val) {
        struct ListNode *temp = head;
        head = head->next;
        free(temp);
    }

    return head; // Return the modified list
}
