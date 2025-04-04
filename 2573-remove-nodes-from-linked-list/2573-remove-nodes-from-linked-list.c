/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <limits.h>

struct ListNode* removeNodesRecursive(struct ListNode* head, int *maxVal) {
    // Base case: if the list is empty, return NULL
    // so that any real node's value can be larger
    if (head == NULL) {
        *maxVal = INT_MIN;
        return NULL;
    }

    // Recursively process the next nodes
    head->next = removeNodesRecursive(head->next, maxVal);

    // If the current node's value is less than the max value,
    // skip(remoove) this node by returning head->next.
    if (head->val < *maxVal) {
        return head->next;
    } else {
        // Otherwise(meaning this node is larger than the max value),
        // update the max value and return the current node
        // to keep it in the list.
        *maxVal = head->val;
        return head;
    }
}

struct ListNode* removeNodes(struct ListNode* head) {
    int maxVal = INT_MIN;
    return removeNodesRecursive(head, &maxVal);
}
