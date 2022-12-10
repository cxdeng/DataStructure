#include "StaticSeqQueue.h"


/**
 * Initialize a static queue
 * @return
 */
StaticSeqQueue *InitStaticArrQueue()
{
    StaticSeqQueue *queue = (StaticSeqQueue *) malloc(sizeof(StaticSeqQueue));

    if (queue)
    {
        for (int i = 0; i < MAXSIZE; ++i)
        {
            queue->data[i] = 0;
        }
        queue->front = -1;
        queue->rear = -1;
    }

    return queue;
}


/**
 * Return the front element of the queue
 * @param queue
 * @return
 */
ElemType Front(StaticSeqQueue *queue)
{
    return queue->data[queue->front];
}


/**
 * Judge if the static queue is empty
 * @param queue
 * @return
 */
int IsEmpty(StaticSeqQueue *queue)
{
    if (queue->front == -1 && queue->rear == -1)
        return TRUE;
    return FALSE;
}


/**
 * Judge if the static queue is full
 * @param queue
 * @return
 */
int IsFull(StaticSeqQueue *queue)
{
    if (queue->rear == MAXSIZE - 1)
        return TRUE;
    return FALSE;
}


/**
 * Push a element to the queue
 * @param queue
 * @param elem
 */
void Enqueue(StaticSeqQueue *queue, ElemType elem)
{
    if (IsFull(queue))
    {
        printf("The queue is full.\n");
        return;
    } else if (IsEmpty(queue))
    {
        queue->front = 0;
        queue->rear = 0;
    } else
    {
        queue->rear += 1;
    }
    queue->data[queue->rear] = elem;
}


/**
 * Pop a element from the queue
 * @param queue
 */
void Dequeue(StaticSeqQueue *queue)
{
    if (IsEmpty(queue))
    {
        printf("The queue is empty.\n");
        return;
    } else if (queue->front == queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    } else
    {
        queue->front += 1;
    }
}