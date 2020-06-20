#include "stack.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>

int IsEmptyStack( Stack S )
{
#if StackArray
    return S->TopOfStack == EmptyTOS;
#else
    return S->Next == NULL;
#endif
}

Stack CreateStack( int MaxElements )
{
    Stack S;
    S = malloc( sizeof( struct StackNode ));
    if ( S == NULL )
        return NULL;
#if StackArray
    if (MaxElements < MinStackSize)
        Error("Stack size is too small");

    S->Array = malloc(sizeof(ElementType) * MaxElements);
    if (S->Array == NULL)
        return NULL;
    S->Capacity = MaxElements;
#else
    S->Next = NULL;
#endif
    MakeEmptyStack( S );
    return S;
}

void MakeEmptyStack( Stack S )
{
#if StackArray
    S->TopOfStack = EmptyTOS;
#else
    if ( S == NULL )
        printf( "Must use CreateStack First" );
    else
    {
        while ( !IsEmptyStack(S) )
            Pop( S );
    }
#endif
}

void DisposeStack( Stack S )
{
#if StackArray
    if (S != NULL)
    {
        free(S->Array);
        free(S);
    }
#else
    PtrToStackNode P, TmpCell;

    P = S->Next;
    S->Next = NULL;
    while (P)
    {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }

    free(S);
#endif
}

void Push( ElementType X, Stack S )
{
#if StackArray
    if (IsFullStack(S))
        printf("Full Stack");
    else
        S->Array[++S->TopOfStack] = X;
#else
    PtrToStackNode TmpCell;

    TmpCell = malloc( sizeof( struct StackNode ));
    if ( TmpCell == NULL )
    {
        printf( "Out of space!!!" );
        return;
    }

    TmpCell->Element = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
#endif
}

ElementType Top( Stack S )
{
    if ( !IsEmptyStack(S) )
    {
#if StackArray
        return S->Array[S->TopOfStack];
#else
        return S->Next->Element;
#endif
    }

    Error( "Empty stack" );
    return 0;
}

void Pop( Stack S )
{
    if ( IsEmptyStack(S) )
        FatalError( "Empty stack!" );
#if StackArray
    S->TopOfStack--;
#else
    PtrToStackNode TmpCell;
    TmpCell = S->Next;
    S->Next = TmpCell->Next;
    free(TmpCell);
#endif
}

#if StackArray
int IsFullStack( Stack S )
{
    return S->Capacity == (S->TopOfStack + 1);
}

ElementType TopAndPop( Stack S )
{
    if(!IsEmptyStack(S))
        return S->Array[S->TopOfStack--];

    Error("Empty Stack");
    return 0;
}
#endif
