#include <stdio.h>
#include <stdlib.h>

#define  TRUE 1
#define  FALSE 0
typedef int ElemType;

/**
* Define node of binary search tree
*/
struct BstNode
{
    ElemType data;
    struct BstNode *left;
    struct BstNode *right;
};

/**
* Define node of singly linked list
*/
typedef struct QueueNode
{
    struct BstNode *data;
    struct QueueNode *next;
} BstLinkedQueue;

extern struct QueueNode *bstFront;
extern struct QueueNode *bstRear;

/**
 * Initialize a singly linked queue with a head node
 * @return
 */
BstLinkedQueue *InitBstLinkedQueue();

/**
 * Push a element to the linked queue
 * @param queue
 * @param elem
 */
void BstEnqueue(BstLinkedQueue *queue, struct BstNode *elem);

/**
 * Pop a element from the linked queue
 * @param queue
 */
void BstDequeue(BstLinkedQueue *queue);

/**
 * Pop a element from the linked queue
 * @param queue
 */
void Dequeue(BstLinkedQueue *queue);

/**
 * Judge if the static circular queue is empty
 * @param queue
 * @return
 */
int IsEmpty(BstLinkedQueue *queue);

/**
 * Return the front element of the queue
 * @param queue
 * @return
 */
struct BstNode *Front(BstLinkedQueue *queue);

/**
 * Create a new node of binary search tree
 * @param elem
 * @return
 */
struct BstNode *GetNewNode(ElemType elem);

/**
 * Insert an element to the binary search tree
 * @param root
 * @param elem
 * @return
 */
struct BstNode *InsertElem(struct BstNode *root, ElemType elem);

/**
 * Search an element from the binary search tree
 * @param root
 * @param elem
 * @return
 */
int SearchElem(struct BstNode *root, ElemType elem);

/**
 * Find the minimum element in the binary search tree using iteration
 * @param root
 * @return
 */
ElemType FindMinByIteration(struct BstNode *root);

/**
 * Find the maximum element in the binary search tree using iteration
 * @param root
 * @return
 */
ElemType FindMaxByIteration(struct BstNode *root);

/**
 * Find the minimum element in the binary search tree using recursion
 * @param root
 * @return
 */
ElemType FIndMinRecursion(struct BstNode *root);

/**
 * Find the maximum element in the binary search tree using recursion
 * @param root
 * @return
 */
ElemType FIndMaxRecursion(struct BstNode *root);

/**
 * Get the height of the binary search tree
 * @param root
 * @return
 */
int FindHeight(struct BstNode *root);

/**
 * Traverse the binary search tree using breadth first (level order)
 * @param root
 */
void BreadthFirstTraverse(struct BstNode *root, struct BstNode *pNode);