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
} LinkedQueue;

extern struct Node* front;
extern struct Node* rear;


/**
 * nitialize a singly linked queue with a head node
 * @return
 */
LinkedQueue *InitLinkedQueue();

/**
 * Judge if the static circular queue is empty
 * @param queue
 * @return
 */
int IsEmpty(LinkedQueue *queue);

/**
 * Push a element to the linked queue
 * @param queue
 * @param elem
 */
void Enqueue(LinkedQueue *queue, ElemType elem);

/**
 * Pop a element from the linked queue
 * @param queue
 */
void Dequeue(LinkedQueue *queue);

/**
 * Return the front element of the queue
 * @param queue
 * @return
 */
ElemType Front(LinkedQueue *queue);

/**
 * Traverse the linked queue
 * @param pHead
 */
void TraverseLinkedQueue(LinkedQueue *queue);