#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Stack node, as a form of singly-linked (boilerplate)
// C language does not have a built-in stack data structure :)
//
// (Stack) stack node
typedef struct StackNode {
    int value;
    struct StackNode *next;
} StackNode;

// (Stack) push an integer to the stack
void stackPush(StackNode **top, int value) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->value = value;
    newNode->next = *top;
    *top = newNode;
}

// (Stack) pop an integer from the stack
int stackPop(StackNode **top) {
    if (*top == NULL) {
        // Stack underflow
        return -1;
    }

    StackNode *temp = *top;
    int returnValue = temp->value;
    *top = temp->next;
    free(temp);

    return returnValue;
}

// (Stack) check if the stack is empty
bool stackIsEmpty(StackNode *top) { return top == NULL; }

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    // Prepare two stacks to store the values of the linked lists
    StackNode *stack1 = NULL;
    StackNode *stack2 = NULL;
    int carry = 0;

    for (struct ListNode *node = l1; node != NULL; node = node->next) {
        stackPush(&stack1, node->val);
    }

    for (struct ListNode *node = l2; node != NULL; node = node->next) {
        stackPush(&stack2, node->val);
    }

    // Linked list for the result
    struct ListNode *result = NULL;

    // Continue adding the values from the stacks,
    // until both stacks are empty and there is no carry
    while (!stackIsEmpty(stack1) || !stackIsEmpty(stack2) || carry > 0) {
        int sum = carry;
        sum += stackIsEmpty(stack1) ? 0 : stackPop(&stack1);
        sum += stackIsEmpty(stack2) ? 0 : stackPop(&stack2);

        int sumDigit = sum % 10;
        carry = sum / 10; // 1 if sum >= 10, 0 otherwise.
                          // Can't be more than 1, because sum is at most 18.

        // Create a new node to store the current digit
        struct ListNode *newNode =
            (struct ListNode *)malloc(sizeof(struct ListNode));
        newNode->val = sumDigit;
        newNode->next = result;
        result = newNode;
    }

    // Now result is a linked list that represents the sum of l1 and l2
    return result;
}
