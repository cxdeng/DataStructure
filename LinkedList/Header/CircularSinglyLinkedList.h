#include <stdio.h>
#include <stdlib.h>

#define  TRUE 1
#define  FALSE 0
typedef int ElemType;

/**
* Define node of circular singly linked list
*/
typedef struct Node
{
    ElemType data;
    struct Node *next;
} CircularSinglyLinkedList;

/**
 * Initialize a circular singly linked list with a head node
 * @return
 */
CircularSinglyLinkedList *InitCircularSinglyLinkedList(void);

/**
 * Judge if the circular singly linked pHead is empty.
 * @param pHead
 * @return If return 1: The pHead is empty. If return 0: The pHead is not empty
 */
int IsEmpty(CircularSinglyLinkedList *pHead);

/**
 * Insert a element at the end of the circular singly linked list
 * @param pHead
 * @param elem
 */
void InsertElemToEnd(CircularSinglyLinkedList *pHead, ElemType elem);

/**
 * Insert a element at the head of the circular singly linked list
 * @param pHead
 * @param elem
 */
void InsertElemToHead(CircularSinglyLinkedList *pHead, ElemType elem);

/**
 * Delete a element at the end of the circular singly linked list
 * @param pHead
 */
void DelElemFromEnd(CircularSinglyLinkedList *pHead);

/**
 * Delete a element at the head of the circular singly linked list
 * @param pHead
 */
void DelElemFromHead(CircularSinglyLinkedList *pHead);

/**
 * Return the size of the circular singly linked list
 * @param pHead
 * @return
 */
int GetSizeOfList(CircularSinglyLinkedList *pHead);

/**
 * Traverse the circular singly linked list
 * @param pHead
 */
void TraverseLinkedList(CircularSinglyLinkedList *pHead);