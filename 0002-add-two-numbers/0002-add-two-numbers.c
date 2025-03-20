/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* ptrl1 = l1;
    struct ListNode* ptrl2 = l2;

    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* ptr = head;
    int carry = 0;
    while (ptrl1 != NULL || ptrl2 != NULL) {
        // Get the value of the current nodes from the linked list
        int valuel1 = (ptrl1 != NULL) ? ptrl1->val : 0;
        int valuel2 = (ptrl2 != NULL) ? ptrl2->val : 0;
        int sum = valuel1 + valuel2 + carry;
        carry = sum / 10;
        // printf("valuel1: %d, valuel2: %d, carry: %d, sum: %d\n", valuel1, valuel2, carry, sum);
        if (ptrl1 != NULL) {
            ptrl1 = ptrl1->next;
        }
        if (ptrl2 != NULL) {
            ptrl2 = ptrl2->next;
        }

        // Create a new node with the sum of the two values
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;
        ptr->next = newNode;        // Connect the new node to the linked list
        ptr = ptr->next;
    }

    // If still there's a carry (remaining one), append it to the last
    if (carry != 0) {
        struct ListNode* lastNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        lastNode->val = carry;
        lastNode->next = NULL;
        ptr->next = lastNode;   // Connect it!
        ptr = ptr->next;
    }

    return head->next;
}