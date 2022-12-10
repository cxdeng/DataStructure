#include "LinkedStack.h"

/**
 * Initialize a singly linked stack with a head node
 * @return
 */
LinkedStack *InitLinkedStack()
{
    struct Node *pHead = (struct Node *) malloc(sizeof(struct Node));

    if (pHead)
    {
        pHead->data = 0;
        pHead->next = NULL;
    }

    return pHead;
}


/**
 * Push an element to the static stack
 * @param LinkedStack
 * @param elem
 */
void Push(LinkedStack *linkedStack, ElemType elem)
{

    // The pointer 'p' points to the head node
    struct Node *p = linkedStack;

    struct Node *node = (struct Node *) malloc(sizeof(struct Node));

    node->next = p->next;
    p->next = node;
    node->data = elem;
}


/**
 * Pop an element from the singly linked stack
 * @param staticStack
 * @param elem
 */
void Pop(LinkedStack *linkedStack, ElemType *elem)
{
    // The pointer 'p' points to the head node
    struct Node *p = linkedStack;

    if (p->next == NULL)
    {
        printf("The stack is empty.\n");
        return;
    }
    struct Node *popNode = p->next;

    if (elem)
    {
        *elem = popNode->data;
    }

    p->next = p->next->next;
    free(popNode);
}


/**
 * Return the value of the top element
 * @param staticStack
 * @return
 */
ElemType Top(LinkedStack *linkedStack)
{
    // The pointer 'p' points to the head node
    struct Node *p = linkedStack;

    if (p->next == NULL)
    {
        printf("The stack is empty.\n");
        return NULL;
    }

    ElemType top = p->next->data;

    return top;
}


/**
 * Reverse a string
 * @param ch
 * @param length
 */
void ReverseString(char *arr, unsigned int length)
{
    LinkedStack stack;

    // Loop for push
    for (int i = 0; i < length; i++)
    {
        Push(&stack, arr[i]);
    }

    // Loop for pop
    for (int i = 0; i < length; i++)
    {
        arr[i] = Top(&stack);
        Pop(&stack, NULL);
    }

}


/**
 * Traverse the static stack
 * @param list
 */
void TraverseLinkedStack(LinkedStack *linkedStack)
{
    // The pointer 'p' points to the first element node
    struct Node *p = linkedStack->next;

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}