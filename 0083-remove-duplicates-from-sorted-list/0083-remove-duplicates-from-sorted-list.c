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

    struct ListNode **pp = &head;

    while (*pp) {
        struct ListNode *current = *pp;
        if (current->next && current->val == current->next->val) {
            // If the current node's value is equal to the next node's value,
            // Remove the next node to avoid duplicates
            struct ListNode *toDelete = current->next;
            current->next = toDelete->next;
            free(toDelete);
        } else {
            // Just traverse to the next node
            pp = &current->next;
        }
    }

    return head;
}
