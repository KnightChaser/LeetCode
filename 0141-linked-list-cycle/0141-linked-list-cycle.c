/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false; // An empty list cannot have a cycle
    }

    // The given linked list has a maximum of 10^4 nodes.
    // So, if we reach 10^4 itrations of traverse, and the next node is not NULL,
    // we can safely assume that the list does have a cycle.
    int traverseCount = 0;
    while (head->next != NULL) {
        if (traverseCount > 10000) {
            // There is a cycle in the list
            return true;
        }
        head = head->next;
        traverseCount++;
    }

    // No cycle detected
    return false; 
}
