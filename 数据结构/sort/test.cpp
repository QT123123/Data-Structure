#include "Sort.h"

int main() {
	int arr[9] = { 9,1,2,5,7,4,8,6,78};
	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	//ShellSort(arr, 10);
	//SelectSort(arr, 10);
	//HeapSort(arr, 10);
	//BubbleSort(arr, 10);
	//QuickSort(arr, 0, 9);
	//QuickSortNonR(arr, 0, 9);
	//MergSort(arr, 9);
	//MergSortNonR(arr, 9);
	CountSort(arr, 9);
	printarry(arr,9);
	
	return 0;
}