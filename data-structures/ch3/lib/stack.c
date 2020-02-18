#include "stack.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>

int IsEmpty( Stack S )
{
    return S->Next == NULL;
}

Stack CreateStack( void )
{
    Stack S;

    S = malloc( sizeof( struct Node ) );
    if ( S == NULL )
        return NULL;
    S->Next = NULL;
    MakeEmptyStack( S );
    return S;
}

void MakeEmptyStack( Stack S )
{
    if ( S == NULL )
        printf( "Must use CreateStack First" );
    else
    {
        while ( !IsEmpty(S) )
            Pop( S );
    }
}

void DisposeStack( Stack S )
{
    PtrToNode P, TmpCell;

    P = S->Next;
    S->Next = NULL;
    while (P)
    {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }

    free(S);
}

void Push( ElementType X, Stack S )
{
    PtrToNode TmpCell;

    TmpCell = malloc( sizeof( struct Node ));
    if ( TmpCell == NULL )
    {
        printf( "Out of space!!!" );
        return;
    }

    TmpCell->Element = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}

ElementType Top( Stack S )
{
    if ( !IsEmpty(S) )
        return S->Next->Element;

    Error( "Empty stack" );
    return 0;
}

void Pop( Stack S )
{
    if ( IsEmpty(S) )
        FatalError( "Empty stack!" );

    PtrToNode TmpCell;
    TmpCell = S->Next;
    S->Next = TmpCell->Next;
    free(TmpCell);
}
