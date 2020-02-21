#ifndef _Stack_H
#define _Stack_H

#define StackArray 1

typedef int ElementType;
#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )

struct StackNode;
typedef struct StackNode *PtrToStackNode;
typedef PtrToStackNode Stack;

struct StackNode
{
#if StackArray
    int Capacity;
    int TopOfStack;
    ElementType *Array;
#else
    ElementType Element;
    PtrToStackNode   Next;
#endif
};

int IsEmptyStack( Stack S );
int IsFullStack( Stack S );
Stack CreateStack( int MaxElements );
void DisposeStack( Stack S );
void MakeEmptyStack( Stack S );
void Push( ElementType X, Stack S );
ElementType Top( Stack S );
void Pop( Stack S );
ElementType TopAndPop( Stack S );

#endif /* _Stack_H */
