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

    bool hasCycle = false;

    // Use the two-pointer technique to detect a cycle
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // If there is a cycle, the fast pointer will meet the slow pointer in the future.
    while (slow != NULL && fast != NULL && fast->next != NULL) {
        slow = slow->next; 
        fast = fast->next->next; 

        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }

    // If the fast pointer reaches the end of the list,
    // without touching the slow pointer, there is no cycle.
    return hasCycle;
}
