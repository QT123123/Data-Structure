#include "Stack.h"
void StackInit(ST* ps) {
	ps->a = nullptr;
	ps->top = ps->capacity = 0;
}
void StackDestroy(ST* ps) {
	assert(ps);
	free(ps->a);
	ps->a = nullptr;
}
void StackPush(ST* ps, STDataType x) {
	assert(ps);
	if (ps->top == ps->capacity) {
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType*tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newcapacity);
		if (tmp == nullptr) {
			exit(-1);
		}
		else {
			ps->a = tmp;
		}
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;

}
void StackPop(ST* ps) {
	assert(ps);
	assert(!StackEmpty(ps));
	ps->top--;
}
STDataType StackTop(ST* ps) {
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[ps->top - 1];
}
int StackSize(ST* ps) {
	assert(ps);
	return ps->top;
}
bool StackEmpty(ST* ps) {
	assert(ps);
	return ps->top == 0;
}