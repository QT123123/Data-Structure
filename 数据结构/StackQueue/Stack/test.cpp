#include "Stack.h"
#include "Queue.h"
void test1() {
	ST st;
	StackInit(&st);
	StackPush(&st,1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	cout << StackTop(&st) << endl;
	StackPop(&st);
	StackPush(&st, 4);
	cout << StackTop(&st) << endl;
	StackPop(&st);
	StackPush(&st, 5);
	while (!StackEmpty(&st)) {
		cout << StackTop(&st)<< endl;
		StackPop(&st);
	}
}
void test2() {
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	cout << QueueFront(&q) << ' ';
	QueuePop(&q);
	QueuePush(&q, 3);
	cout << QueueFront(&q) << ' ';
	QueuePop(&q);
	QueuePush(&q, 4);
	cout << QueueSize(&q);
	/*while (!QueueEmpty(&q)) {
		cout<<QueueFront(&q)<<' ';
		QueuePop(&q);
	}*/
	QueueDestroy(&q);


}
void test3() {
	Queue q1;
	Queue q2;
	QueueInit(&q1);
	QueueInit(&q2);
	QueuePush(&q1, 1);
	QueuePush(&q1, 1);
	QueuePush(&q2, 2);
	QueuePush(&q2, 2);
	Queue q3;
	q3 = q1;
	Queue q4;
	q4 = q2;
	QueuePush(&q3, 3);
	QueuePush(&q3, 3);
	QueuePush(&q4, 4);
	QueuePush(&q4, 4);

}
int main() {
	//test1();
	//test2();
	test3();
	return 0;
}