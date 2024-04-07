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
		gap = gap / 3 + 1;//��gap��������ʱ��������ѣ�
		for (int i = 0; i < n - gap; i++) {
			int end = i;//����鲢��һ���������
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
			max = min;//��begin��max�ص�ʱ������min��begin��ı�max��λ�ã�����Ҫ����max��λ�ã�
		}
		swap(&arr[end], &arr[max]);
		begin++;
		end--;

	}
}