/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdbool.h>
#include <stdlib.h>

bool isPalindrome(struct ListNode *head) {
    if (!head || !head->next) {
        return true; // Empty list or single node is a palindrome
    }

    // Slow and fast pointer to find the middle of the linked list
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    int halfLength = 0;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        halfLength++;
    }

    // Reverse the second half of the linked list
    struct ListNode *prev = NULL;
    while (slow) {
        struct ListNode *next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    // Now, *Prev is the head of the reversed second half of the linked list
    // we can now determine if the linked list is a palindrome
    struct ListNode *firstHalf = head;
    while (prev) {
        if (firstHalf->val != prev->val) {
            return false; // Not a palindrome
        }
        firstHalf = firstHalf->next;
        prev = prev->next;
    }

    return true; // Is a palindrome
}
