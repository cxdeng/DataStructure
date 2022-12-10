#include <stdio.h>
#include <stdlib.h>

#define  TRUE 1
#define  FALSE 0
typedef int ElemType;

/**
* Define node of singly linked list
*/
typedef struct Node
{
    ElemType data;
    struct Node *next;
} SinglyLinkedList;

/**
 * Initialize a singly linked list with a head node
 * @return
 */
SinglyLinkedList *InitSinglyLinkedList(void);

/**
 * Judge if the singly linked pHead is empty.
 * @param pHead
 * @return If return 1: The pHead is not empty. If return 0: The pHead is empty
 */
int IsEmpty(SinglyLinkedList *pHead);

/**
 * Insert a element to the singly linked list at any valid position
 * @param pHead
 * @param elem
 * @param pos
 */
void InsetElemAtAny(SinglyLinkedList *pHead, ElemType elem, int pos);

/**
 * Delete a element to the singly linked list at any valid position
 * @param pHead
 * @param pos
 */
void DelElemAtAny(SinglyLinkedList *pHead, int pos);

/**
 * Insert a element at the end of the singly linked list
 * @param pHead
 * @param elem
 */
void InsertElemToEnd(SinglyLinkedList *pHead, ElemType elem);

/**
 * Insert a element at the head of the singly linked list
 * @param pHead
 * @param elem
 */
void InsertElemToHead(SinglyLinkedList *pHead, ElemType elem);

/**
 * Delete a element at the end of the singly linked list
 * @param pHead
 */
void DelElemFromEnd(SinglyLinkedList *pHead);

/**
 * Return the size of the singly linked list
 * @param pHead
 * @return
 */
int GetSizeOfList(SinglyLinkedList *pHead);

/**
 * Get an element based on a given element value
 * @param pHead: Head pointer of the singly linked list
 * @param elem: Object element
 * @return
 */
SinglyLinkedList *LocateElem(SinglyLinkedList *pHead, ElemType elem);

/**
 * Traverse the singly linked list
 * @param pHead
 */
void TraverseLinkedList(SinglyLinkedList *pHead);

/**
 * Reverse singly linked list using iteration
 * @param pHead
 */
void ReverseLinkedList(SinglyLinkedList *pHead);

/**
 * Print singly linked list using recursion
 * @param pHead
 */
void PrintUsingRecursionForward(struct Node* p);

/**
 * Print singly linked list using recursion
 * @param pHead
 */
void PrintUsingRecursionBackward(struct Node* p);