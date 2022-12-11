#include "StaticCircularSeqQueue.h"

/**
 * Initialize a static circular queue
 * @return
 */
StaticCircularSeqQueue *InitCircularQueue()
{
    StaticCircularSeqQueue *queue = (StaticCircularSeqQueue *) malloc(sizeof(StaticCircularSeqQueue));

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
ElemType Front(StaticCircularSeqQueue *queue)
{
    if (queue->front == -1)
    {
        printf("The queue is empty.\n");
        return -1;
    }
    return queue->data[queue->front];
}


/**
 * Judge if the static circular queue is empty
 * @param queue
 * @return
 */
int IsEmpty(StaticCircularSeqQueue *queue)
{
    if (queue->front == -1 && queue->rear == -1)
        return TRUE;
    return FALSE;
}


/**
 * Judge if the static circular queue is full
 * @param queue
 * @return
 */
int IsFull(StaticCircularSeqQueue *queue)
{
    if ((queue->rear + 1) % MAXSIZE == queue->front)
        return TRUE;
    return FALSE;
}


/**
 * Push a element to the static circular queue
 * @param queue
 * @param elem
 */
void Enqueue(StaticCircularSeqQueue *queue, ElemType elem)
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

        queue->rear = (queue->rear + 1) % MAXSIZE;
    }
    queue->data[queue->rear] = elem;
}


/**
 * Pop a element from the static circular queue
 * @param queue
 */
void Dequeue(StaticCircularSeqQueue *queue)
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
        queue->front = (queue->front + 1) % MAXSIZE;
    }
}

