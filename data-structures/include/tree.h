#ifndef _Tree_H
#define _Tree_H

#include "common.h"

struct TreeNode;
typedef struct TreeNode *TreePositon;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmptyTree( SearchTree T );
TreePositon FindTree( ElementType X, SearchTree T );
TreePositon FindMinTree( SearchTree T);
TreePositon FindMaxTree( SearchTree T);
SearchTree InsertTree( ElementType X, SearchTree T );
SearchTree DeleteTree( ElementType X, SearchTree T );
ElementType RetrieveTree( TreePositon P );

#endif /* _Tree_H */
