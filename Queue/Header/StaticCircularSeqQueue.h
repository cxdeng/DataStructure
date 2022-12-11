#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
#define  TRUE 1
#define  FALSE 0
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
} StaticCircularSeqQueue;

/**
 * Initialize a static circular queue
 * @return
 */
StaticCircularSeqQueue *InitCircularQueue();

/**
 * Return the front element of the queue
 * @param queue
 * @return
 */
ElemType Front(StaticCircularSeqQueue *queue);

/**
 * Judge if the static circular queue is empty
 * @param queue
 * @return
 */
int IsEmpty(StaticCircularSeqQueue *queue);

/**
 * Judge if the static circular queue is full
 * @param queue
 * @return
 */
int IsFull(StaticCircularSeqQueue *queue);

/**
 * Push a element to the static circular queue
 * @param queue
 * @param elem
 */
void Enqueue(StaticCircularSeqQueue *queue, ElemType elem);

/**
 * Pop a element from the static circular queue
 * @param queue
 */
void Dequeue(StaticCircularSeqQueue *queue);