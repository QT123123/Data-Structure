#include "Heap.h"

void swap(HPDataType& a, HPDataType& b) {
	HPDataType tmp = a;
	a = b;
	b = tmp;
}
void AdjustDown(HPDataType* a, int n, int root) {
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n) {
		if (child + 1 < n && a[child] < a[child + 1]) {
			child++;
		}
		if (a[parent] < a[child]) {   
			swap(a[parent], a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}
void HeapSort(HPDataType* a, int n) {
	for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end>0) {
		swap(a[0], a[end]);
		AdjustDown(a, end, 0);//时间复杂度O（N*logN）;
		end--;
	}
}
void HeapInit(Heap* php, HPDataType* a, int n) {
	assert(php->a!=NULL);
	php->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	php->size = php->capacity = n;
	memcpy(php->a, a, sizeof(HPDataType) * n);//建大堆 时间复杂度O(N)；
	for (int i = (n - 1 - 1) / 2; i >= 0; i--) {
		AdjustDown(php->a,php->size, i);
	}
}
void HeapDestory(Heap* php) {
	free(php->a);
	php->size = php->capacity = 0;
	php->a = NULL;
}
void HeapPush(Heap* php, HPDataType x) {
	if (php->capacity == php->size) {
		php->capacity *= 2;
		HPDataType*t= (HPDataType*)realloc(php->a,sizeof(HPDataType) * php->capacity);
		if (t != NULL) {
			php->a = t;
		}
	}
	int child = php->size;
	php->a[php->size++] = x;
	int parent = (child - 1) / 2;
	while (child>0) {
		if (php->a[child] > php->a[parent]) {
			swap(php->a[child],php-> a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
	
}
void HeapPop(Heap* php) {
	assert(php->size > 0);
	assert(php->a);
	swap(php->a[0], php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}
HPDataType HeapTop(Heap* php) {
	return php->a[0];
}