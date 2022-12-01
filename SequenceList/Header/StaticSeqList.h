#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
#define  TRUE 1
#define  FALSE 0
typedef int ElemType;

typedef struct Node
{
    ElemType data[MAXSIZE];
    int length;
} StaticSeqList;

/**
 * Initialize a static sequence list
 * @return
 */
StaticSeqList *InitStaticSeqList(void);

/**
 * Judge if the list is empty
 * @param list
 * @return
 */
int IsEmpty(StaticSeqList *list);

/**
 * Calculating the number of elements in the sequence list
 * @param list
 * @return
 */
int GetSizeOfList(StaticSeqList *list);

/**
 * Insert element: Insert the given value at the specified position
 * @param list
 * @param elem: Element to be inserted
 * @param pos: 1 ~ length + 1
 */
void InsertElemToSeq(StaticSeqList *list, ElemType elem, int pos);

/**
 * Delete element: Delete a element at the specified position
 * @param list
 * @param pos
 */
void DelElemFromSeq(StaticSeqList *list, int pos);

/**
 * Traverse the sequence list
 * @param list
 */
void TraverseSeqList(StaticSeqList *list);