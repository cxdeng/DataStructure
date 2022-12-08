#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
#define  TRUE 1
#define  FALSE 0
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int top;
} StaticStack;


/**
 * Initialize a static stack
 * @return
 */
StaticStack *InitStaticStack();

/**
 * Push an element to the static stack
 * @param staticStack
 * @param elem
 */
void Push(StaticStack *staticStack, ElemType elem);

/**
 * Pop an element from the static stack
 * @param staticStack
 * @param elem
 */
void Pop(StaticStack *staticStack, ElemType *elem);

/**
 * Return the value of the top element
 * @param staticStack
 * @return
 */
ElemType Top(StaticStack *staticStack);

/**
 * Traverse the static stack
 * @param list
 */
void TraverseStaticStack(StaticStack *staticStack);
