#include "BinarySearchTree.h"

extern struct QueueNode *bstFront = NULL;
extern struct QueueNode *bstRear = NULL;

/**
 * Initialize a singly linked queue with a head node
 * @return
 */
BstLinkedQueue *InitBstLinkedQueue()
{
    struct QueueNode *pHead = NULL;
    pHead = (struct QueueNode *) malloc(sizeof(struct QueueNode));

    if (pHead)
    {
        pHead->data = 0;
        pHead->next = NULL;
    }

    return pHead;
}


/**
 * Push a element to the linked queue
 * @param queue
 * @param elem
 */
void BstEnqueue(BstLinkedQueue *queue, struct BstNode *elem)
{
    // The pointer p point to the head node
    struct QueueNode *p = queue;

    struct QueueNode *node = (struct QueueNode *) malloc(sizeof(struct QueueNode));
    if (!node)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    node->data = elem;
    node->next = NULL;

    // If the queue is empty, set the pointer 'front' and the pointer 'rear' point to the new node
    if (bstFront == NULL && bstRear == NULL)
    {
        bstFront = node;
        bstRear = node;
        p->next = node;
        return;
    }

    // If the queue is not empty, the last node points to the new node
    bstRear->next = node;
    // Then, the pointer 'rear' points to the new last node
    bstRear = node;
}


/**
 * Pop a element from the linked queue
 * @param queue
 */
void BstDequeue(BstLinkedQueue *queue)
{
    // The pointer p point to the head node
    struct QueueNode *p = queue;
    struct QueueNode *delNode = bstFront;

    if (bstFront == NULL)
    {
        printf("The queue is empty.");
        return;
    }
    // The queue only has one element
    if (bstFront == bstRear)
    {
        bstFront = NULL;
        bstRear = NULL;
    } else
    {
        bstFront = bstFront->next;
    }
    free(delNode);
    p->next = bstFront;
}


/**
 * Judge if the static circular queue is empty
 * @param queue
 * @return
 */
int IsEmpty(BstLinkedQueue *queue)
{
    if (bstRear == NULL)
        return TRUE;
    return FALSE;
}


/**
 * Return the front element of the queue
 * @param queue
 * @return
 */
struct BstNode *Front(BstLinkedQueue *queue)
{
    if (IsEmpty(queue))
    {
        printf("The queue is empty.");
        return NULL;
    }

    return bstFront->data;
}


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


/**
 * Traverse the binary search tree using breadth first (level order)
 * @param root
 */
void BreadthFirstTraverse(struct BstNode *root, struct BstNode *pNode)
{
    if (root == NULL)
    {
        return;
    }

    BstLinkedQueue *queue = InitBstLinkedQueue();
    BstEnqueue(queue, root);

    while (!IsEmpty(queue))
    {
        struct BstNode *p = Front(queue);
        printf("%d ", p->data);
        if (p->left != NULL)
        {
            BstEnqueue(queue, p->left);
        }
        if(p->right != NULL){
            BstEnqueue(queue, p->right);
        }
        BstDequeue(queue);
    }
}