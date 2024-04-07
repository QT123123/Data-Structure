#include "SeqList.h"

void SeqListInit(SL*ps) {
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}
void SeqListprint(SL* ps) {
	int i = 0;
	for (i = 0; i < ps->size; i++) {
		cout << ps->a[i] << ' ';
	}
	cout << endl;
}
void SeqListDestory(SL* ps) {
	free(ps->a);
	ps->a = NULL;
}
void SeqListCheckCapacity(SL* ps) {
	if (ps->capacity == ps->size) {
		//À©ÈÝ
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* temp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
		if (temp == NULL) {
			exit(-1);
		}
		ps->a = temp;
		ps->capacity = newcapacity;
	}
}
void SeqListPushBack(SL* ps, SLDataType x) {
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void SeqListPopBack(SL* ps) {
	assert(ps->size > 0);
	ps->size--;
}
void SeqListPushFront(SL* ps, SLDataType x) {
	SeqListCheckCapacity(ps);
	int i = 0;
	for (i = ps->size; i > 0; i--) {
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}
void SeqListPopFront(SL* ps) {
	int i = 0;
	assert(ps->size > 0);
	for (i = 0; i < ps->size-1; i++) {
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

int SeqListFind(SL* ps, SLDataType x) {
	int i = 0;
	for (i = 0; i < ps->size; i++) {
		if (x == ps->a[i])
			return i;
	}
	return -1;
}
void SeqListInsert(SL* ps, int pos, SLDataType x) {
	assert(pos <= ps->size && pos >= 0);
	SeqListCheckCapacity(ps);
	int i = 0;
	for (i = ps->size; i > pos; i--) {
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;

}
void SeqListErase(SL* ps, int pos) {
	assert(pos < ps->size && pos >= 0);
	int i = 0;
	for (i = pos; i < ps->size-1; i++) {
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}