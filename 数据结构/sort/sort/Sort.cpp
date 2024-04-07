#include "Sort.h"
void InsertSort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		int end = i;
		int t = arr[end + 1];
		while (end >= 0) {
			if (t < arr[end]) {
				arr[end + 1] = arr[end];
				end--;
			}
			else {
				break;
			}
		}
		arr[end + 1] = t;
	}
}
void printarry(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void ShellSort(int* arr, int n) {
	int gap = n;
	while (gap>1) {
		gap = gap / 3 + 1;//当gap这样处理时，性能最佳；
		for (int i = 0; i < n - gap; i++) {
			int end = i;//多组归并到一起插入排序；
			int t = arr[end + gap];
			while (end >= 0) {
				if (t < arr[end]) {
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			arr[end + gap] = t;
		}
	}
}
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
void SelectSort(int* arr, int n) {
	int begin = 0;
	int end = n - 1;
	while (begin < end) {
		int min, max;
		min = max = begin;
		for (int i = begin + 1; i <= end; i++) {
			if (arr[i] > arr[max]) {
				max = i;
			}
			if (arr[i] < arr[min]) {
				min = i;
			}
		}
		swap(&arr[begin], &arr[min]);
		if (begin == max) {
			max = min;//当begin和max重叠时，交换min和begin会改变max的位置，所以要修正max的位置；
		}
		swap(&arr[end], &arr[max]);
		begin++;
		end--;

	}
}