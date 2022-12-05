#include "SinglyLinkedList.h"

/**
 * Initialize a singly linked list with a head node
 * @return
 */
SinglyLinkedList *InitSinglyLinkedList(void)
{
    struct Node *pHead = NULL;
    pHead = (struct Node *) malloc(sizeof(struct Node));
    if (pHead)
    {
        pHead->data = 0;
        pHead->next = NULL;
    }

    return pHead;
}


/**
 * Judge if the singly linked pHead is empty.
 * @param pHead
 * @return If return 1: The pHead is empty. If return 0: The pHead is not empty
 */
int IsEmpty(SinglyLinkedList *pHead)
{
    return pHead->next == NULL;
}


/**
 * Insert a element to the singly linked list at any valid position
 * @param pHead
 * @param elem
 * @param pos
 */
void InsetElemAtAny(SinglyLinkedList *pHead, ElemType elem, int pos)
{

    int length = GetSizeOfList(pHead);
    if (pos < 1 || pos > length + 1)
    {
        printf("Wrong position.\n");
        return;
    }

    // The pointer p point to the head node
    struct Node *p = pHead;

    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    if (!node)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    node->data = elem;
    node->next = NULL;

    for (int i = 1; i <= pos - 1; i++)
    {
        p = p->next;
    }


    node->next = p->next;
    p->next = node;
}


/**
 * Delete a element to the singly linked list at any valid position
 * @param pHead
 * @param pos
 */
void DelElemAtAny(SinglyLinkedList *pHead, int pos)
{

    int length = GetSizeOfList(pHead);
    if (pos < 1 || pos > length)
    {
        printf("Wrong position.\n");
        return;
    }

    // The pointer p point to the head node
    struct Node *p = pHead;

    int i = 1;
    while (p != NULL && i <= pos - 1)
    {
        p = p->next;
        i++;
    }

    struct Node *node = p->next;
    p->next = p->next->next;

    free(node);
}


/**
 * Insert a element at the end of the singly linked list
 * @param pHead
 * @param elem
 */
void InsertElemToEnd(SinglyLinkedList *pHead, ElemType elem)
{
    // The pointer p point to the head node
    struct Node *p = pHead;

    // The pointer p finally point to the last node of the singly linked list
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
}


/**
 * Insert a element at the head of the singly linked list
 * @param pHead
 * @param elem
 */
void InsertElemToHead(SinglyLinkedList *pHead, ElemType elem)
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
 * Delete a element at the head of the singly linked list
 * @param pHead
 */
void DelElemFromEnd(SinglyLinkedList *pHead)
{
    // The pointer p point to the head node
    struct Node *p = pHead;

    while (p->next->next != NULL)
    {
        p = p->next;
    }

    struct Node *node = p->next;
    free(node);

    p->next = NULL;
}


int GetSizeOfList(SinglyLinkedList *pHead)
{

    struct Node *p = pHead->next;

    int total = 0;
    while (p != NULL)
    {
        total++;
        p = p->next;
    }

    return total;
}


/**
 * Get an element based on a given element value
 * @param pHead: Head pointer of the singly linked list
 * @param elem: Object element
 * @return
 */
SinglyLinkedList *LocateElem(SinglyLinkedList *pHead, ElemType elem)
{
    // Point to the node of the first element of the singly linked list
    struct Node *p = pHead->next;

    while (p != NULL && p->data != elem)
    {
        p = p->next;
    }

    return p;
}


/**
 * Traverse the singly linked list
 * @param pHead
 */
void TraverseLinkedList(SinglyLinkedList *pHead)
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
 * Reverse singly linked list using iteration
 * @param pHead
 */
void ReverseLinkedList(SinglyLinkedList *pHead)
{

    struct Node *current = NULL;
    struct Node *prev = NULL;
    struct Node *next = NULL;

    // The pointer 'current' point to the first element node
    current = pHead->next;

    while (current != NULL)
    {
        // Save the address of the next node
        next = current->next;
        // Reverse the link
        current->next = prev;
        // Save the address of the current node as the address of the previous node
        prev = current;
        // Move to the next the node
        current = next;
    }

    // End of the while loop, The pointer 'prev' store the address of the last node. And the pointer 'pHead' will store the address of the last node
    pHead->next = prev;

}