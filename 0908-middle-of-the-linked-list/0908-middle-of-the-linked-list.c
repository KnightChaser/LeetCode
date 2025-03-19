/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* headPtr = head;
    struct ListNode* tailPtr = head;

    while (tailPtr != NULL && tailPtr->next != NULL) {
        headPtr = headPtr->next;
        tailPtr = tailPtr->next->next;
    }

    return headPtr;
}