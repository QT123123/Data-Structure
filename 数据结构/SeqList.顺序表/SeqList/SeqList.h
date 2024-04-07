#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cassert>
using namespace std;
#define N 100
typedef int SLDataType;
typedef  struct SeqList {
	SLDataType* a;
	int size;
	int capacity;
}SL;

void SeqListprint(SL* ps);
void SeqListCheckCapacity(SL* ps);//检查容量

void SeqListInit(SL* ps);//初始化

void SeqListPushBack(SL* ps,SLDataType x);//尾插

void SeqListDestory(SL* ps);//销毁

void SeqListPopBack(SL* ps);//尾删

void SeqListPushFront(SL* ps, SLDataType x);//头插

void SeqListPopFront(SL* ps);//头删

int SeqListFind(SL* ps, SLDataType x);//查找
void SeqListInsert(SL* ps, int pos, SLDataType x);//指定位置插入
void SeqListErase(SL* ps, int pos);//指定位置删除