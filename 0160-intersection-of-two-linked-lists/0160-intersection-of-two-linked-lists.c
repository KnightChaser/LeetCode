/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>

struct ListNode *getIntersectionNode(struct ListNode *headA,
                                     struct ListNode *headB) {
    // Base case: if either list is empty, return NULL
    if (headA == NULL || headB == NULL) {
        return NULL;
    }

    struct ListNode *pa = headA, *pb = headB;

    while (pa != pb) {
        // Move to the next node in each list,
        // or switch to the other list if we reach the end
        pa = (pa == NULL) ? headB : pa->next;
        pb = (pb == NULL) ? headA : pb->next;
    }

    // They're(pa or pb) either NULL or they meet at the intersection point
    return pa;
}
