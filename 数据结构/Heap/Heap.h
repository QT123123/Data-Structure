#pragma once
#include <iostream>
using namespace std;
typedef int HPDataType;
#include <cstdlib>
#include <cstring>
#include <cassert>
struct Heap {
	HPDataType* a;
	int size;
	int capacity;
};
void HeapInit(Heap* php, HPDataType* a, int n);
void HeapDestory(Heap* php);
void HeapPush(Heap* php, HPDataType x);
void HeapPop(Heap* php);
HPDataType HeapTop(Heap* php);
void HeapSort(HPDataType* a, int n);
