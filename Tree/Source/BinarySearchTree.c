#include "BinarySearchTree.h"


/**
 * Create a new node of binary search tree
 * @param elem
 * @return
 */
struct BstNode *GetNewNode(ElemType elem)
{
    struct BstNode *bstNode = (struct BstNode *) malloc(sizeof(struct BstNode));

    bstNode->data = elem;
    bstNode->left = NULL;
    bstNode->right = NULL;

    return bstNode;
}


/**
 * Insert an element to the binary search tree
 * @param root
 * @param elem
 * @return
 */
struct BstNode *InsertElem(struct BstNode *root, ElemType elem)
{
    if (root == NULL)
    {
        root = GetNewNode(elem);
    } else if (elem <= root->data)
    {
        root->left = InsertElem(root->left, elem);
    } else
    {
        root->right = InsertElem(root->right, elem);
    }

    return root;
}


/**
 * Search an element from the binary search tree
 * @param root
 * @param elem
 * @return
 */
int SearchElem(struct BstNode *root, ElemType elem)
{
    if (root == NULL)
    {
        return FALSE;
    }
    else if (root->data == elem)
    {
        return TRUE;
    }
    else if (elem <= root->data)
    {
        return SearchElem(root->left, elem);
    } else
    {
        return SearchElem(root->right, elem);
    }
}