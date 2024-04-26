#pragma once
#include <iostream>
using namespace std;
#include <cstdlib>
#include <cassert>
struct BinaryTreeNode;
typedef BinaryTreeNode* QDataType;
struct QueueNode {
	QDataType val;
	QueueNode* next;
};
struct Queue {
	QueueNode* head;
	QueueNode* tail;
};
void QueueInit(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
void QueueDestroy(Queue* pq);
bool QueueEmpty(Queue* pq);