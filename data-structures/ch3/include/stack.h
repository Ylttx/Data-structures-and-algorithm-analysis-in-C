#ifndef _Stack_H
#define _Stack_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef int ElementType;

int IsEmpty( Stack S );
Stack CreateStack( void );
void DisposeStack( Stack S );
void MakeEmpty( Stack S );
void Push( ElementType X, Stack S );
ElementType Top( Stack S );
void Pop( Stack S );

struct Node
{
    ElementType Element;
    PtrToNode   Next;
};

#endif /* _Stack_H */
