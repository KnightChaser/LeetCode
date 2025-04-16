/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode* previous = NULL;
    struct ListNode* current = head;
    while (current != NULL) {
        if (previous != NULL && previous->val == current->val) {
            // Duplicate found, remove the current node
            struct ListNode* temp = current;
            current = current->next;
            previous->next = current;
            free(temp);
        } else {
            // No duplicate, move to the next node
            previous = current;
            current = current->next;
        }
    }

    return head;
}
