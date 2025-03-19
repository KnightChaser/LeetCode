/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* ptr = head;
    int length = 0;
    while (ptr->next != NULL) {
        ptr = ptr->next;
        length++;
    }

    ptr = head;
    int halfIndex = (length / 2) + (length % 2);
    while (halfIndex > 0) {
        ptr = ptr->next;
        halfIndex--;
    }

    return ptr;
}