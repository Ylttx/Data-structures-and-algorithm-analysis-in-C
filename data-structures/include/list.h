#ifndef _List_H
#define _List_H

#include "common.h"

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

struct Node
{
    ElementType Element;
    Position    Next;
};

List MakeEmptyList( List L );
int IsEmptyList( List L );
int IsLast( Position P, List L );
Position Find( ElementType, List L );
void Delete( ElementType X, List L );
Position FindPrevious( ElementType X, List L );
void Insert( ElementType X, List L, Position P );
void DeleteList( List L );
Position Header( List L );
Position First( List L );
Position Advance( Position P );
ElementType Retrieve( Position P );

#endif /* _List_H */
