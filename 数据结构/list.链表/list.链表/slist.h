#pragma once
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;
typedef int SLTDateType;
struct SLTNode {
	SLTDateType date;
	SLTNode* next;
};
void SListPrint(SLTNode* phead);
void SListPushBack(SLTNode** pphead, SLTDateType x);
void SListPushFront(SLTNode** pphead, SLTDateType x);
void SListPopBack(SLTNode** pphead);
void SListPopFront(SLTNode** pphead);
SLTNode* SListFind(SLTNode* phead, SLTDateType x);
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x);
void SListErase(SLTNode** pphead, SLTNode* pos);
void SListDestroy(SLTNode** pphead);