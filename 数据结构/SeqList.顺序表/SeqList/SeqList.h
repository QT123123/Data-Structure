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
void SeqListCheckCapacity(SL* ps);//�������

void SeqListInit(SL* ps);//��ʼ��

void SeqListPushBack(SL* ps,SLDataType x);//β��

void SeqListDestory(SL* ps);//����

void SeqListPopBack(SL* ps);//βɾ

void SeqListPushFront(SL* ps, SLDataType x);//ͷ��

void SeqListPopFront(SL* ps);//ͷɾ

int SeqListFind(SL* ps, SLDataType x);//����
void SeqListInsert(SL* ps, int pos, SLDataType x);//ָ��λ�ò���
void SeqListErase(SL* ps, int pos);//ָ��λ��ɾ��