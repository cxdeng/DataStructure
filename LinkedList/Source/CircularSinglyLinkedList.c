#include "CircularSinglyLinkedList.h"

/**
 * Initialize a circular singly linked list with a head node
 * @return
 */
CircularSinglyLinkedList *InitCircularSinglyLinkedList(void)
{

    struct Node *pHead = NULL;

    pHead = (struct Node *) malloc(sizeof(struct Node));
    if (pHead)
    {
        pHead->data = 0;
        pHead->next = pHead;
    }

    return pHead;
}


/**
 * Judge if the circular singly linked pHead is empty.
 * @param pHead
 * @return If return 1: The pHead is empty. If return 0: The pHead is not empty
 */
int IsEmpty(CircularSinglyLinkedList *pHead)
{
    return pHead->next == pHead;
}


/**
 * Insert a element at the end of the circular singly linked list
 * @param pHead
 * @param elem
 */
void InsertElemToEnd(CircularSinglyLinkedList *pHead, ElemType elem)
{
    // The pointer p point to the head node
    struct Node *p = pHead;

    while (p->next != pHead)
    {
        p = p->next;
    }

    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    if (!node)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    node->data = elem;
    p->next = node;
    node->next = pHead;
}


/**
 * Insert a element at the head of the circular singly linked list
 * @param pHead
 * @param elem
 */
void InsertElemToHead(CircularSinglyLinkedList *pHead, ElemType elem)
{
    // The pointer p point to the head node
    struct Node *p = pHead;

    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    if (!node)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    node->data = elem;
    node->next = p->next;
    p->next = node;
}


/**
 * Delete a element at the head of the circular singly linked list
 * @param pHead
 */
void DelElemFromEnd(CircularSinglyLinkedList *pHead)
{
    // The pointer p point to the head node
    struct Node *p = pHead;

    while (p->next->next != pHead)
    {
        p = p->next;
    }

    struct Node *delNode = p->next;
    free(delNode);
    p->next = pHead;
}


/**
 * Delete a element at the head of the circular singly linked list
 * @param pHead
 */
void DelElemFromHead(CircularSinglyLinkedList *pHead)
{
    // The pointer p point to the head node
    struct Node *p = pHead;

    // The pointer 'delNode' points to the first element node.
    struct Node *delNode = p->next;

    p->next = p->next->next;
    free(delNode);
}


/**
 * Return the size of the circular singly linked list
 * @param pHead
 * @return
 */
int GetSizeOfList(CircularSinglyLinkedList *pHead)
{
    struct Node *p = pHead->next;

    int total = 0;
    while (p != pHead)
    {
        total++;
        p = p->next;
    }

    return total;
}


/**
 * Traverse the circular singly linked list
 * @param pHead
 */
void TraverseLinkedList(CircularSinglyLinkedList *pHead)
{
    struct Node *p = pHead->next;

    while (p != pHead)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}