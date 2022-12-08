#include "StaticStack.h"


/**
 * Initialize a static stack
 * @return
 */
StaticStack *InitStaticStack()
{

    StaticStack *staticStack = NULL;
    staticStack = (StaticStack *) malloc(sizeof(StaticStack));

    if (staticStack)
    {
        for (int i = 0; i < MAXSIZE; ++i)
        {
            staticStack->data[i] = 0;
        }

        staticStack->top = -1;
    }

    return staticStack;
}

/**
 * Push an element to the static stack
 * @param staticStack
 * @param elem
 */
void Push(StaticStack *staticStack, ElemType elem)
{
    if (staticStack->top == MAXSIZE - 1)
    {
        printf("Static stack overflow.\n");
        return;
    }

    staticStack->top++;
    staticStack->data[staticStack->top] = elem;
}


/**
 * Pop an element from the static stack. Then return the element
 * @param staticStack
 * @return
 */
void Pop(StaticStack *staticStack, ElemType *elem)
{
    if (staticStack->top == -1)
    {
        printf("The stack is empty.\n");
        return;
    }

    if (elem)
    {
        *elem = staticStack->data[staticStack->top];
    }

    staticStack->top--;
}


/**
 * Return the value of the top element
 * @param staticStack
 * @return
 */
ElemType Top(StaticStack *staticStack)
{

    if (staticStack->top == -1)
    {
        printf("The stack is empty.\n");
    }

    return staticStack->data[staticStack->top];
}


/**
 * Traverse the static stack
 * @param list
 */
void TraverseStaticStack(StaticStack *staticStack)
{
    for (int i = 0; i <= staticStack->top; ++i)
    {
        printf("%d ", staticStack->data[i]);
    }
    printf("\n");
}