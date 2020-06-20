#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

#define MinQueueSize ( 5 )

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

int IsEmptyQueue( Queue Q )
{
    return Q->Size == 0;
}

int IsFullQueue( Queue Q )
{
    return Q->Size == Q->Capacity;
}

Queue CreateQueue( int MaxElements )
{
    Queue Q;

    if (MaxElements < MinQueueSize)
        Error("Queue size is too small");

    Q = malloc(sizeof(struct QueueRecord));
    if (Q == NULL)
        return NULL;

    Q->Array = malloc(sizeof(ElementType) * MaxElements);
    if (Q->Array == NULL)
        return NULL;
    Q->Capacity = MaxElements;
    MakeEmptyQueue(Q);

    return Q;
}

void DisposeQueue( Queue Q )
{
    if (Q != NULL)
    {
        free(Q->Array);
        free(Q);
    }
}

void MakeEmptyQueue( Queue Q )
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

static int Succ(int Value, Queue Q)
{
    if (++Value == Q->Capacity)
        Value = 0;
    return Value;
}

void Enqueue( ElementType X, Queue Q )
{
    if (IsFullQueue(Q))
        Error("Full queue");
    else
    {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

ElementType Front( Queue Q )
{
    if (!IsEmptyQueue(Q))
        return Q->Array[Q->Front];

    Error("Empty Queue");
    return 0;
}

void Dequeue( Queue Q )
{
    if (IsEmptyQueue(Q))
        Error("Empty Queue");
    else
        Q->Front++;
}

ElementType FrontAndDequeue( Queue Q )
{
    if (!IsEmptyQueue(Q))
        return Q->Array[Q->Front++];

    Error("Empty Queue");
    return 0;
}
