#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    ElementType Element;
    SearchTree  Left;
    SearchTree  Right;
};

SearchTree MakeEmptyTree( SearchTree T )
{
    if (T != NULL)
    {
        MakeEmptyTree(T->Left);
        MakeEmptyTree(T->Right);
        free(T);
    }
    return NULL;
}

TreePositon FindTree( ElementType X, SearchTree T )
{
    if (T == NULL)
        return NULL;

    if (X < T->Element)
        return FindTree(X, T->Left);
    else if(X > T->Element)
        return FindTree(X, T->Right);
    else
        return T;
}

TreePositon FindMinTree( SearchTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->Left == NULL)
        return T;
    else
        return FindMinTree(T->Left);
}

TreePositon FindMaxTree( SearchTree T)
{
    if (T != NULL)
        while (T->Right != NULL)
            T = T->Right;

    return T;
}

SearchTree InsertTree( ElementType X, SearchTree T )
{
    if (T == NULL)
    {
        T = malloc(sizeof(struct TreeNode));
        if (T == NULL)
            Error("Out of space!!!");
        else
        {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else if (X < T->Element)
        T->Left = InsertTree(X, T->Left);
    else if (X > T->Element)
        T->Right = InsertTree(X, T->Right);

    return T;
}

SearchTree DeleteTree( ElementType X, SearchTree T )
{
    TreePositon TmpCell;

    if (T == NULL)
        Error("Element Not Found");
    else if (X < T->Element)
        T->Left = DeleteTree(X, T->Left);
    else if (X > T->Element)
        T->Right = DeleteTree(X, T->Right);
    else if (T->Left && T->Right)
    {
        TmpCell = FindMinTree(T->Right);
        T->Element = TmpCell->Element;
        T->Right = DeleteTree(T->Element, T->Right);
    }
    else
    {
        TmpCell = T;
        if (T->Left == NULL)
            T = T->Right;
        else if (T->Right == NULL)
            T = T->Left;
        free(TmpCell);
    }

    return T;
}

ElementType RetrieveTree( TreePositon P )
{
    if (P == NULL)
        return 0;

    return P->Element; 
}
