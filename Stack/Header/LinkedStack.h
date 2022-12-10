#include <stdio.h>
#include <stdlib.h>

#define  TRUE 1
#define  FALSE 0
typedef char ElemType;

/**
* Define node of linked stack
*/
typedef struct Node
{
    ElemType data;
    struct Node *next;
} LinkedStack;


/**
 * Initialize a singly linked stack with a head node
 * @return
 */
LinkedStack *InitLinkedStack();

/**
 * Push an element to the singly linked stack
 * @param LinkedStack
 * @param elem
 */
void Push(LinkedStack *linkedStack, ElemType elem);

/**
 * Pop an element from the singly linked stack
 * @param staticStack
 * @param elem
 */
void Pop(LinkedStack *linkedStack, ElemType *elem);

/**
 * Return the value of the top element
 * @param staticStack
 * @return
 */
ElemType Top(LinkedStack *linkedStack);

/**
 * Reverse a string
 * @param ch
 * @param length
 */
void ReverseString(char *arr, unsigned int length);

/**
 * Traverse the static stack
 * @param list
 */
void TraverseLinkedStack(LinkedStack *linkedStack);