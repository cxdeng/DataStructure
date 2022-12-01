#include "StaticSeqList.h"

/**
 * Initialize a static sequence list
 * @return
 */
StaticSeqList *InitStaticSeqList(void)
{

    StaticSeqList *list = NULL;
    list = (struct Node *) malloc(sizeof(struct Node));

    if (list)
    {
        for (int i = 0; i < MAXSIZE; ++i)
        {
            list->data[i] = 0;
        }

        list->length = 0;
    }

    return list;
}


/**
 * Judge if the list is empty
 * @param list
 * @return
 */
int IsEmpty(StaticSeqList *list)
{
    return list->length == 0;
}


/**
 * Calculating the number of elements in the sequence list
 * @param list
 * @return
 */
int GetSizeOfList(StaticSeqList *list)
{
    return list->length;
}


/**
 * Insert element: Insert the given value at the specified position
 * @param list
 * @param elem: Element to be inserted
 * @param pos: 1 ~ length + 1
 * @return
 */
void InsertElemToSeq(StaticSeqList *list, ElemType elem, int pos)
{
    // Judge if the list is full
    if (list->length >= MAXSIZE)
    {
        printf("The list is full.\n");
        return;
    }

    // Judge if the position is right
    if (pos < 1 || pos > list->length + 1)
    {
        printf("Wrong position.\n");
        return;
    }

    for (int i = list->length - 1; i >= pos - 1; i--)
    {
        list->data[i + 1] = list->data[i];
    }

    list->data[pos - 1] = elem;
    list->length++;
}


/**
 * Delete element: Delete a element at the specified position
 * @param list
 * @param pos
 */
void DelElemFromSeq(StaticSeqList *list, int pos)
{
    // Judge if the list is empty
    if (IsEmpty(list))
    {
        printf("The list is empty\n");
        return;
    }

    // Judge if the position is right
    if (pos < 1 || pos > list->length)
    {
        printf("Wrong position\n");
        return;
    }

    for (int i = pos - 1; i < list->length - 1; ++i)
    {
        list->data[i] = list->data[i + 1];
    }

    list->length--;
}


/**
 * Traverse the sequence list
 * @param list
 */
void TraverseSeqList(StaticSeqList *list)
{
    for (int i = 0; i < list->length; i++)
    {
        printf("%d ", list->data[i]);
    }

    printf("\n");
}