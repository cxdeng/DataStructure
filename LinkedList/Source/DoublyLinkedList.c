#include "DoublyLinkedList.h"

/**
 * Initialize a doubly linked list with a head node
 * @return
 */
DoublyLinkedList *InitDoublyLinkedList(void)
{
    struct Node *pHead = NULL;

    pHead = (struct Node *) malloc(sizeof(struct Node));

    if (pHead)
    {
        pHead->data = 0;
        pHead->prev = NULL;
        pHead->next = NULL;
    }

    return pHead;
}


/**
 * Judge if the doubly linked pHead is empty.
 * @param pHead
 * @return If return 1: The pHead is not empty. If return 0: The pHead is empty
 */
int IsEmpty(DoublyLinkedList *pHead)
{
    // If the head node do not link any other node, the list is empty
    return pHead->next == NULL;
}


/**
 * Insert a element at the end of the doubly linked list
 * @param pHead
 * @param elem
 */
void InsertElemToEnd(DoublyLinkedList *pHead, ElemType elem)
{
    // The pointer p point to the head node
    struct Node *p = pHead;

    while (p->next != NULL)
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
    node->next = NULL;
    p->next = node;
    node->prev = p;
}


/**
 * Insert a element at the head of the doubly linked list
 * @param pHead
 * @param elem
 */
void InsertElemToHead(DoublyLinkedList *pHead, ElemType elem)
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

    if (p->next == NULL)
    {
        p->next = node;
        node->prev = p;
        node->next = NULL;
        return;
    }

    node->next = p->next;
    node->prev = p;
    p->next->prev = node;
    p->next = node;
}


/**
 * Delete a element at the end of the doubly linked list
 * @param pHead
 */
void DelElemFromEnd(DoublyLinkedList *pHead)
{
    // The pointer p point to the head node
    struct Node *p = pHead;

    while (p->next->next != NULL)
    {
        p = p->next;
    }

    struct Node *delNode = p->next;
    free(delNode);

    p->next = NULL;
}


/**
 * Delete a element at the head of the doubly singly linked list
 * @param pHead
 */
void DelElemFromHead(DoublyLinkedList *pHead)
{
    // The pointer p point to the head node
    struct Node *p = pHead;

    struct Node *delNode = p->next;

    p->next = p->next->next;
    p->next->next->prev = p;

    free(delNode);
}


/**
 * Traverse the doubly linked list
 * @param pHead
 */
void TraverseLinkedList(DoublyLinkedList *pHead)
{
    struct Node *p = pHead->next;

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}


/**
 * Reverse to traverse the doubly linked list
 * @param pHead
 */
void ReverseToTraverseLinkedList(DoublyLinkedList *pHead)
{

    struct Node *p = pHead->next;

    while (p->next != NULL)
    {
        p = p->next;
    }

    printf("Reverse: ");
    while (p != pHead)
    {
        printf("%d ", p->data);
        p = p->prev;
    }

    printf("\n");
}