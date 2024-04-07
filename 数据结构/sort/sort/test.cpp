#include "Sort.h"

int main() {
	int arr[10] = { 9,1,2,5,7,4,8,6,3,5 };
	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	//ShellSort(arr, 10);
	SelectSort(arr, 10);
	printarry(arr,10);
	
	return 0;
}