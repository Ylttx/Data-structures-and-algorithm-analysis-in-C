#ifndef _TestList_H
#define _TestList_H
#include "list.h"

void TestList( void );

void PrintElement( const List L ); // 3.1
void PrintLots(List L, List P);  // 3.2
void SwapNext(Position before, List L); // 3.3.a
void SwapNextDouble(Position P, List L); // 3.3.b
List Intersect(List L1, List L2); // 3.4
List Merge(List L1, List L2); // 3.5

void ReverseList( List L ); // 反转链表

#endif
