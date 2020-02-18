#include "test_list.h"
#include <stdio.h>
#include <string.h>

void TestList()
{
    int i;
    List list1, list2;
    Position p1, p2; 

    list1 = MakeEmptyList(NULL);
    list2 = MakeEmptyList(NULL);
    p1 = Header(list1);
    p2 = Header(list2);

    for (i = 1; i < 6; i++)
    {
        Insert(i * 2, list1, p1);
        p1 = Advance(p1);
    }
    for (i = 0; i < 10; i++)
    {
        Insert(i * 5, list2, p2);
         p2 = Advance(p2);
    }
    
    printf("List:\n");
    PrintElement(list1);
    PrintElement(list2);

    printf("PrintLots:\n");
    PrintLots(list2, list1);

    printf("Swap:\n");
    SwapNext(Find(30, list2), list2);
    PrintElement(list2);

    printf("Intersect:\n");
    PrintElement(Intersect(list1, list2));

    printf("Merge:\n");
    PrintElement(Merge(list1, list2));

    printf("ReverseList:\n");
    ReverseList(list1);
    PrintElement(list1);

    DeleteList(list1);
    DeleteList(list2);
}


/* 3.1 print all the Element of single linked list*/
void PrintElement( const List L )
{
    Position P = Header(L);
    if (IsEmptyList(L))
        printf("Empty list!\n");
    else
    {
        do
        {
            P = Advance(P);
            printf("%d ", Retrieve(P));
        }while (!IsLast(P, L));
        printf("\n");
    }
}

/* 3.2 打印升序链表 O(n^2)*/
void PrintLots(List L, List P)
{
    int count = 1;
    Position listPrint, listIndex; 
    listPrint = First(L);
    listIndex = First(P);
    
    while (listPrint != NULL && listIndex != NULL)
    {
        if (listIndex->Element == count++)
        {
            printf("%d ", Retrieve(listPrint));
            listIndex = Advance(listIndex);
        }
        listPrint = Advance(listPrint);
    }
    printf("\n");
}

/* 3.3.a singly linked lists 交换before后面两个元素（只调整指针） */
void SwapNext(Position before, List L)
{
    if (before == NULL)
        return;

    Position now, after;
    now = Advance(before);
    if (now == NULL)
        return;

    after = Advance(now);
    if (after == NULL)
        return;

    now->Next = Advance(after);
    after->Next = now;
    before->Next = after;
}
/* 3.3.b double linked lists 交换P P后面的两个元素 */
void SwapNextDouble(Position P, List L)
{
/*
    Position pre, after; 
    pre = P->Prev;
    after = P->Next;

    P->Next = after->Next;
    pre->Next = after;
    after->Next = P;
    P->Next->prev = P;
    P->Prev = after;
    after->Prev = pre;
*/
}

/* 3.4 求交集；两个已排序的链表*/
List Intersect(List L1, List L2)
{
    List L;
    Position P, P1, P2;

    L = MakeEmptyList(NULL);
    P = Header(L);
    P1 = First(L1);
    P2 = First(L2);

    while (P1 != NULL && P2 != NULL)
    {
        if (P1->Element < P2->Element)
            P1 = Advance(P1);
        else if (P1->Element > P2->Element)
            P2 = Advance(P2);
        else
        {
            Insert(P1->Element, L, P);
            P = Advance(P);
            P1 = Advance(P1);
            P2 = Advance(P2);
        }
    }

    return L;
}

/* 3.5 求并集；两个已排序的链表*/
List Merge(List L1, List L2)
{
    List L;
    Position P, P1, P2;

    L = MakeEmptyList(NULL);
    P = Header(L);
    P1 = First(L1);
    P2 = First(L2);

    while (P1 != NULL || P2 != NULL)
    {
        if (P2 == NULL || (P1 != NULL && P1->Element < P2->Element))
        {
            Insert(P1->Element, L, P);
            P1 = Advance(P1);
        }
        else if (P1 == NULL || (P2 != NULL && P1->Element > P2->Element))
        {
            Insert(P2->Element, L, P);
            P2 = Advance(P2);
        }
        else
        {
            Insert(P1->Element, L, P);
            P1 = Advance(P1);
            P2 = Advance(P2);
        }
        P = Advance(P);
    }

    return L;
}

/* 反转链表: O(n) */
void ReverseList( List L )
{
    if (IsEmptyList(L) || L->Next->Next == NULL)
        return;

    Position P0, P, P1;
    P0 = NULL;
    P = First(L);
    P1 = P->Next;

    while (P1 != NULL)
    {
       P->Next = P0;
       P0 = P;
       P = P1;
       P1 = Advance(P1);
    }
    P->Next = P0;
    L->Next = P;
}
