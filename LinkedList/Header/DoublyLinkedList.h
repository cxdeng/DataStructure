#include <stdio.h>
#include <stdlib.h>

#define  TRUE 1
#define  FALSE 0
typedef int ElemType;

/**
* Define node of doubly linked list
*/
typedef struct Node
{
    ElemType data;
    struct Node *prev;
    struct Node *next;
} DoublyLinkedList;


/**
 * Initialize a doubly linked list with a head node
 * @return
 */
DoublyLinkedList *InitDoublyLinkedList(void);

/**
 * Judge if the doubly linked pHead is empty.
 * @param pHead
 * @return If return 1: The pHead is not empty. If return 0: The pHead is empty
 */
int IsEmpty(DoublyLinkedList *pHead);

/**
 * Insert a element at the end of the doubly linked list
 * @param pHead
 * @param elem
 */
void InsertElemToEnd(DoublyLinkedList *pHead, ElemType elem);


/**
 * Insert a element at the head of the doubly linked list
 * @param pHead
 * @param elem
 */
void InsertElemToHead(DoublyLinkedList *pHead, ElemType elem);

/**
 * Delete a element at the end of the doubly linked list
 * @param pHead
 */
void DelElemFromEnd(DoublyLinkedList *pHead);

/**
 * Delete a element at the head of the doubly singly linked list
 * @param pHead
 */
void DelElemFromHead(DoublyLinkedList *pHead);

/**
 * Traverse the doubly linked list
 * @param pHead
 */
void TraverseLinkedList(DoublyLinkedList *pHead);

/**
 * Reverse to traverse the doubly linked list
 * @param pHead
 */
void ReverseToTraverseLinkedList(DoublyLinkedList *pHead);

