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
} StaticSeqQueue;

/**
 * Initialize a static queue
 * @return
 */
StaticSeqQueue *InitStaticArrQueue();

/**
 * Return the front element of the queue
 * @param queue
 * @return
 */
ElemType Front(StaticSeqQueue *queue);

/**
 * Judge if the static queue is empty
 * @param queue
 * @return
 */
int IsEmpty(StaticSeqQueue *queue);

/**
 * Judge if the static queue is full
 * @param queue
 * @return
 */
int IsFull(StaticSeqQueue *queue);

/**
 * Push a element to the queue
 * @param queue
 * @param elem
 */
void Enqueue(StaticSeqQueue *queue, ElemType elem);

/**
 * Pop a element from the queue
 * @param queue
 */
void Dequeue(StaticSeqQueue *queue);