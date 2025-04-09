/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>

void reorderList(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    // First, find the middle of the linked list
    // using the slow and fast pointer technique
    struct ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *second = slow->next;
    slow->next = NULL; // Split the list into two halves

    // Second, reverse the second half of the list
    // e.g.) 1->2->3->4->5 => 5->4->3->2->1
    struct ListNode *prev = NULL, *current = second, *next = NULL;
    while (current != NULL) {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move prev to this node
        current = next;       // Move to the next node
    }

    // Prev now points to the head of the reversed second half

    // Third, merge the two halves
    struct ListNode *l1 = head, *l2 = prev;
    while (l1 != NULL && l2 != NULL) {
        struct ListNode *temp1 = l1->next; 
        struct ListNode *temp2 = l2->next;
        l1->next = l2;
        l2->next = temp1;
        l1 = temp1; 
        l2 = temp2;
    }

    return;
}
