#pragma once
#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;
typedef int LTDateType;
struct LTNode {
	LTDateType date;
	LTNode* next;
	LTNode* prev;
};

LTNode* ListInit();
void ListPushBack(LTNode* phead, LTDateType x);
void ListPrint(LTNode* phead);
void ListPopBack(LTNode* phead);
void ListPushFront(LTNode* phead, LTDateType x);
void ListPopFront(LTNode* phead);
LTNode* ListFind(LTNode* phead, LTDateType x);
void ListInsert(LTNode* phead, LTNode* pos, LTDateType x);
void ListErase(LTNode* phead, LTNode* pos);