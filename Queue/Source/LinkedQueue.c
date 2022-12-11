#include "LinkedQueue.h"

struct Node *front = NULL;
struct Node *rear = NULL;

/**
 * nitialize a singly linked queue with a head node
 * @return
 */
LinkedQueue *InitLinkedQueue()
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
 * Judge if the static circular queue is empty
 * @param queue
 * @return
 */
int IsEmpty(LinkedQueue *queue)
{
    if (front == NULL)
        return TRUE;
    return FALSE;
}


/**
 * Push a element to the linked queue
 * @param queue
 * @param elem
 */
void Enqueue(LinkedQueue *queue, ElemType elem)
{
    // The pointer p point to the head node
    struct Node *p = queue;

    struct Node *node = (struct Node *) malloc(sizeof(struct Node));
    if (!node)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    node->data = elem;
    node->next = NULL;

    // If the queue is empty, set the pointer 'front' and the pointer 'rear' point to the new node
    if (front == NULL && rear == NULL)
    {
        front = node;
        rear = node;
        p->next = node;
        return;
    }

    // If the queue is not empty, the last node points to the new node
    rear->next = node;
    // Then, the pointer 'rear' points to the new last node
    rear = node;
}


/**
 * Pop a element from the linked queue
 * @param queue
 */
void Dequeue(LinkedQueue *queue)
{
    // The pointer p point to the head node
    struct Node *p = queue;
    struct Node *delNode = front;

    if (front == NULL)
    {
        printf("The queue is empty.");
        return;
    }
    // The queue only has one element
    if (front == rear)
    {
        front = NULL;
        rear = NULL;
    } else
    {
        front = front->next;
    }
    free(delNode);
    p->next = front;
}


/**
 * Return the front element of the queue
 * @param queue
 * @return
 */
ElemType Front(LinkedQueue *queue)
{
    if (IsEmpty(queue))
    {
        printf("The queue is empty.");
        return -1;
    }

    return front->data;
}


/**
 * Traverse the linked queue
 * @param pHead
 */
void TraverseLinkedQueue(LinkedQueue *queue)
{
    // The pointer p point to the front node
    struct Node *p = front;

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}