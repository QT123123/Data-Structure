#include "slist.h"
void test1() {
	SLTNode* phead=NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPrint(phead);
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPrint(phead);
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPrint(phead);
	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPrint(phead);

	
}
void test2() {
	SLTNode* phead = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 4);

	SListPrint(phead);
	SLTNode* pos = SListFind(phead,4);
	//SListInsert(&phead, pos, 30);
	//pos = SListFind(phead, 3);
	//SListInsert(&phead, pos, 30);
	SListErase(&phead, pos);

	SListPrint(phead);
	SListDestroy(& phead);

}
#include "List.h" 
void test3() {
	LTNode* plist = ListInit();
	ListPushBack(plist,1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	//ListPrint(plist);
	//ListPopBack(plist);
	//ListPopBack(plist);
	//ListPrint(plist);
	//ListPushFront(plist, 4);
	//ListPushFront(plist, 3);
	//ListPushFront(plist, 2);
	//ListPushFront(plist, 1);
	//ListPrint(plist);
	//ListPopFront(plist);
	//ListPopFront(plist);
	ListPrint(plist);
	ListInsert(plist, ListFind(plist, 3), 30);
	ListPrint(plist);
	ListErase(plist, ListFind(plist, 3));
	ListPrint(plist);
}

int main() {

	//test1();
	//test2();
	test3();


	return 0;
}