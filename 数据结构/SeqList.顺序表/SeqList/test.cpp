#include "SeqList.h"
void TestSeqList1() {
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListprint(&sl);
	SeqListPopBack(&sl);
	SeqListprint(&sl);
	SeqListDestory(&sl);
}
void TestSeqList2() {
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListprint(&sl);
	SeqListPushFront(&sl,6);
	SeqListPushFront(&sl, 6);
	//SeqListprint(&sl);
	SeqListPopFront(&sl);
	SeqListprint(&sl);
}
void TestSeqList3() {
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListprint(&sl);
	cout << SeqListFind(&sl, 4) << endl;
	SeqListInsert(&sl, 5, 6);
	SeqListInsert(&sl, 3, 100);
	SeqListErase(&sl, 0);
	SeqListprint(&sl);
}
int main() {
	//TestSeqList1();
	//TestSeqList2();
	TestSeqList3();
	return 0;
}