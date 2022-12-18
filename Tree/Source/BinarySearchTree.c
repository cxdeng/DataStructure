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
    } else if (root->data == elem)
    {
        return TRUE;
    } else if (elem <= root->data)
    {
        return SearchElem(root->left, elem);
    } else
    {
        return SearchElem(root->right, elem);
    }
}


/**
 * Find the minimum element in the binary search tree using iteration
 * @param root
 * @return
 */
ElemType FindMinByIteration(struct BstNode *root)
{
    if (root == NULL)
    {
        printf("The binary search tree is empty.\n");
        return -1;
    }

    // The pointer 'p' is temporary pointer which points to the root node of the binary search tree
    struct BstNode *p = root;
    while (p->left != NULL)
    {
        p = p->left;
    }

    return p->data;
}


/**
 * Find the maximum element in the binary search tree using iteration
 * @param root
 * @return
 */
ElemType FindMaxByIteration(struct BstNode *root)
{
    if (root == NULL)
    {
        printf("The binary search tree is empty.\n");
        return -1;
    }

    // The pointer 'p' is temporary pointer which points to the root node of the binary search tree
    struct BstNode *p = root;
    while (p->right != NULL)
    {
        p = p->right;
    }

    return p->data;
}


/**
 * Find the maximum element in the binary search tree using recursion
 * @param root
 * @return
 */
ElemType FIndMinRecursion(struct BstNode *root)
{
    // The pointer 'p' is temporary pointer which points to the root node of the binary search tree
    struct BstNode *p = root;

    if (root == NULL)
    {
        printf("The binary search tree is empty.\n");
        return -1;
    } else if (p->left == NULL)
    {
        return p->data;
    }

    // Search in left subtree
    return FIndMinRecursion(p->left);
}


/**
 * Find the maximum element in the binary search tree using recursion
 * @param root
 * @return
 */
ElemType FIndMaxRecursion(struct BstNode *root)
{
    // The pointer 'p' is temporary pointer which points to the root node of the binary search tree
    struct BstNode *p = root;

    if (root == NULL)
    {
        printf("The binary search tree is empty.\n");
        return -1;
    } else if (p->right == NULL)
    {
        return p->data;
    }

    // Search in left subtree
    return FIndMaxRecursion(p->right);
}


/**
 * Get the height of the binary search tree
 * @param root
 * @return
 */
int FindHeight(struct BstNode *root)
{
    if (root == NULL)
    {
        return -1;
    }

    int heightOfLeftTree = FindHeight(root->left);
    int heightOfRightTree = FindHeight(root->right);

    if (heightOfLeftTree >= heightOfRightTree)
    {
        return heightOfLeftTree + 1;
    } else
    {
        return heightOfRightTree + 1;
    }
}