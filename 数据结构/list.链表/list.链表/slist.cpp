#include "slist.h"
SLTNode* BuyListNode(SLTDateType x) {
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL) {
		exit;
	}
	newnode->date= x;
	newnode->next = NULL;
	return newnode;
}
void SListPrint(SLTNode* phead) {
	SLTNode* cur = phead;
	while (cur!= NULL) {
		cout << cur->date << "->";
		cur = cur->next;
	}
	cout << "NULL"<<endl;

}
void SListPushBack(SLTNode** pphead, SLTDateType x) {
	assert(pphead != NULL);
	SLTNode* tail = *pphead;
	SLTNode* newnode = BuyListNode(x);
	if (tail == NULL) {
		*pphead = newnode;
	}
	else {
		while (tail->next != NULL) {
			tail = tail->next;
		}
		tail->next = newnode;
	}
}
void SListPushFront(SLTNode** pphead, SLTDateType x) {
	assert(pphead != NULL);
	SLTNode* newnode = BuyListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;

}
void SListPopBack(SLTNode** pphead) {
	assert(*pphead != NULL);
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
	}
	else {
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		while (tail->next != NULL) {
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;

		/*SLTNode* tail = *pphead;
		while (tail->next->next != NULL) {
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;*/
	}
}
void SListPopFront(SLTNode** pphead) {
	assert(*pphead != NULL);
	SLTNode* cur = (*pphead)->next;
	free(*pphead);
	*pphead = cur;
}
SLTNode* SListFind(SLTNode* phead, SLTDateType x) {
	SLTNode* tail = phead;
	while (tail != NULL) {
		if (tail->date == x) {
			return tail;
		}
		tail = tail->next;
	}
	return NULL;
}
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x) {
	assert(pphead != NULL);
	SLTNode* newnode = BuyListNode(x);
	if (*pphead == pos) {
		newnode->next = pos;
		*pphead = newnode;
	}
	else {
		SLTNode* posPrev = *pphead;
		while (posPrev->next != pos) {
			posPrev = posPrev->next;
		}
		posPrev->next = newnode;
		newnode->next = pos;
	}
}
void SListErase(SLTNode** pphead, SLTNode* pos) {
	assert(pphead != NULL);
	SLTNode* cur = *pphead;
	if (*pphead== pos) {
		*pphead = pos->next;
		free(pos);
	}
	else {
		while (cur->next != pos) {
			cur = cur->next;
		}
		cur->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
void SListDestroy(SLTNode** pphead) {
	assert(pphead != NULL);
	SLTNode* cur = *pphead;
	SLTNode* prev = NULL;
	while (cur) {
		prev = cur->next;
		free(cur);
		cur = prev;
	}
	*pphead = NULL;
}