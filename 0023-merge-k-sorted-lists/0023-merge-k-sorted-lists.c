/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>

// From problem 21
struct ListNode *mergeTwoLists(struct ListNode *list1, struct ListNode *list2) {
    struct ListNode dummy;
    struct ListNode *p = &dummy;
    dummy.next = NULL;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            p->next = list1;
            list1 = list1->next;
        } else {
            p->next = list2;
            list2 = list2->next;
        }
        p = p->next;
    }

    // There might be some nodes left in list1 or list2
    if (list1) {
        p->next = list1;
    } else {
        p->next = list2;
    }

    return dummy.next;
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    if (listsSize == 0) {
        return NULL;
    }

    int remaining = listsSize;

    // Divide-and-conquer
    // Continue merging pairs of lists until there is only one list left
    while (remaining > 1) {
        int index = 0;
        for (int i = 0; i < remaining; i += 2) {
            if (i + 1 < remaining) {
                // Meaning there are at least two lists left
                lists[index] = mergeTwoLists(lists[i], lists[i + 1]);
            } else {
                // Only one list left
                lists[index] = lists[i];
            }
            index++;
        }

        // The number of lists left is halved
        remaining = index;
    }

    return lists[0];
}
