#include "List.h"
LTNode* BuyListNode(LTDateType x) {
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL) {
		exit;
	}
	newnode->date = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}
LTNode* ListInit() {
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void ListPushBack(LTNode* phead, LTDateType x) {
	assert(phead);
	LTNode* newnode = BuyListNode(x);
	LTNode* tail = phead->prev;
	newnode->date = x;
	newnode->prev = tail;
	tail->next = newnode;
	newnode->next = phead;
	phead->prev = newnode;
}
void ListPrint(LTNode* phead) {
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead) {
		cout << cur->date << " ";
		cur = cur->next;
	}
	cout << endl;
}
void ListPopBack(LTNode* phead) {
	assert(phead);
	assert(phead->next != phead);
	LTNode* tail = phead->prev;
	tail->prev->next = phead;
	phead->prev = tail->prev;
	free(tail);
	tail = NULL;
}
void ListPushFront(LTNode* phead, LTDateType x) {
	assert(phead);
	LTNode* newnode = BuyListNode(x);
	LTNode* next = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = next;
	next->prev = newnode;
}
void ListPopFront(LTNode* phead) {
	assert(phead);
	assert(phead->next != phead);
	LTNode* next = phead->next->next;
	free(phead->next);
	phead->next = next;
	next->prev = phead;
}
LTNode* ListFind(LTNode* phead, LTDateType x) {
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead) {
		if (cur->date == x) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void ListInsert(LTNode* phead, LTNode* pos, LTDateType x) {
	assert(phead);
	assert(pos);
	LTNode* newnode = BuyListNode(x);
	LTNode* posprev = pos->prev;
	posprev->next = newnode;
	newnode->prev = posprev;
	newnode->next = pos;
	pos->prev = newnode;
}
void ListErase(LTNode* phead, LTNode* pos) {
	assert(phead);
	assert(phead->next != phead);
	assert(pos);
	LTNode* posprev = pos->prev;
	LTNode* next = pos->next;
	free(pos);
	posprev->next = next;
	next->prev = posprev;

}