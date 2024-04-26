#include "Queue.h"
void QueueInit(Queue* pq) {
	assert(pq);
	pq->head = pq->tail = nullptr;
}
void QueuePush(Queue* pq, QDataType x) {
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->val = x;
	newnode->next = nullptr;
	if (pq->head == nullptr) {
		pq->head = pq->tail = newnode;
	}
	else {
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}
void QueuePop(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	QueueNode*cur=pq->head->next;
	free(pq->head);
	pq->head = cur;
	if (pq->head == nullptr) {
		pq->tail = nullptr;
	}
	
}
QDataType QueueFront(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->val;
}
QDataType QueueBack(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->val;
}
int QueueSize(Queue* pq) {
	assert(pq);
	int cnt = 0;
	QueueNode* cur = pq->head;
	while (cur) {
		cnt++;
		cur = cur->next;
	}
	return cnt;
}
void QueueDestroy(Queue* pq) {
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur) {
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = nullptr;
}
bool QueueEmpty(Queue* pq){
	return pq->head == nullptr;
}