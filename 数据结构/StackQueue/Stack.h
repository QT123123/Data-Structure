#pragma once
#include <iostream>
using namespace std;
#include <cstdlib>
#include <cassert>
typedef int STDataType;
struct ST {
	STDataType* a;
	int top;
	int capacity;
};
void StackInit(ST* ps);
void StackDestroy(ST* ps);
void StackPush(ST* ps, STDataType x);
void StackPop(ST* ps);
STDataType StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);
