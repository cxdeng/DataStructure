#include <stdio.h>
#include <stdlib.h>

#define  TRUE 1
#define  FALSE 0
typedef int ElemType;

/**
* Define node of singly list
*/
typedef struct Node
{
    ElemType data;
    struct Node *next;
} SinglyLinkedList;