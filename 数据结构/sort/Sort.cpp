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

//排升序，建大堆
void addjustdown(int* arr, int n,int root) {
	int parent = root;
	int child = root * 2 + 1;
	while (child < n) {
		if (child + 1 < n && arr[child + 1] > arr[child]) {
			child++;
		}
		if (arr[parent] < arr[child]) {
			swap(&arr[parent], &arr[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}
void HeapSort(int* arr, int n) {
	for (int i = (n - 1 - 1) / 2; i >= 0;i--) {
		addjustdown(arr, n, i);
	}
	for (int end = n - 1; end > 0; end--) {
		swap(&arr[end], &arr[0]);
		addjustdown(arr, end, 0);
	}
}

void BubbleSort(int* arr, int n) {
	int end = n - 1;
	while (end > 0) {

		int flag = 0;
		for (int i = 0; i <= end - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(&arr[i], &arr[i + 1]);
				flag = 1;
			}
		}
		end--;
		if (flag == 0) {
			break;
		}
	}
}


//快速排序中当keyindex的值就是最大值或者最小值是，效率最差，用三数去中法
int GetMidIndex(int* arr, int left, int right) {
	int mid = (left + right) / 2;
	if (arr[left] < arr[right]) {
		if (arr[mid] > arr[right]) {
			return right;
		}
		else if (arr[left] > arr[mid]) {
			return left;
		}
		else {
			return mid;
		}
	}
	else {
		if (arr[mid] > arr[left]) {
			return left;
		}
		else if (arr[right] > arr[mid]) {
			return right;
		}
		else {
			return mid;
		}
	}

}
//双向指针法
//int PartSort(int* arr, int begin, int end) {
//	int midindex = GetMidIndex(arr, begin, end);
//	swap(&arr[midindex], &arr[end]);
//	int keyindex = end;
//	while (begin < end) {
//		while (begin < end && arr[begin] <= arr[keyindex]) {
//			begin++;
//		}				//去右边为key从左边先走，保证最后停下来的数比key大
//		while (begin < end && arr[end] >= arr[keyindex]) {
//			end--;
//		}
//		swap(&arr[begin], &arr[end]);
//	}
//	swap(&arr[begin], &arr[keyindex]);
//	return begin;
//}
//挖坑法
//int PartSort(int* arr, int begin, int end) {
//	int midindex = GetMidIndex(arr, begin, end);
//	swap(&arr[midindex], &arr[end]);
//	int key = arr[end];
//	while (begin < end) {
//		while (begin < end && arr[begin] <= key) {
//			begin++;
//		}
//		arr[end] = arr[begin];
//		while (begin < end && arr[end] >= key) {
//			end--;
//		}
//		arr[begin]=arr[end];
//	}
//	arr[begin] = key;
//	return begin;
//}

//前后指针法
int PartSort(int* arr, int begin, int end) {
	int midindex = GetMidIndex(arr, begin, end);
	swap(&arr[midindex], &arr[end]);
	int keyindex = end;
	int cur = begin;
	int prev = begin - 1;
	while (cur<end) {
		if (arr[cur] < arr[keyindex]&&++prev!=cur) {
			swap(&arr[prev], &arr[cur]);
		}
		++cur;
	}
	swap(&arr[++prev], &arr[keyindex]);
	return prev;
}

void QuickSort(int* arr, int left,int right) {
	if (left >= right) {
		return;
	}
	if (right - left + 1 > 10) {
		int div = PartSort(arr, left, right);
		QuickSort(arr, left, div - 1);
		QuickSort(arr, div + 1, right);
	}
	else {//区间长度小于等于10个数不在递归排序，减少递归次数
		InsertSort(arr + left, right - left + 1);
	}
}

void QuickSortNonR(int* arr, int left, int right) {
	ST s;
	StackInit(&s);
	StackPush(&s, right);
	StackPush(&s, left);
	while (!StackEmpty(&s)) {
		int left = StackTop(&s);
		StackPop(&s);
		int right = StackTop(&s);
		StackPop(&s);
		int div = PartSort(arr, left, right);
		if (div+1< right) {
			StackPush(&s, right);
			StackPush(&s, div+1);
		}
		if (left < div - 1) {
			StackPush(&s, div - 1);
			StackPush(&s, left);
		}
	}
	StackDestroy(&s);
}
void MergArry(int* arr, int begin1, int end1, int begin2, int end2, int* tmp) {
	int left = begin1;
	int right = end2;
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2) {
		if (arr[begin1] <= arr[begin2]) {
			tmp[index++] = arr[begin1++];
		}
		else {
			tmp[index++] = arr[begin2++];
		}
	}
	while (begin1 <= end1) {
		tmp[index++] = arr[begin1++];
	}
	while (begin2 <= end2) {
		tmp[index++] = arr[begin2++];
	}
	for (int i = left; i <= right; i++) {
		arr[i] = tmp[i];
	}

}
void _MergSort(int* arr, int left, int right, int* tmp) {
	if (left >= right) {
		return;
	}
	int mid = (left + right) / 2;
	_MergSort(arr, left, mid,tmp);
	_MergSort(arr, mid + 1, right, tmp);
	MergArry(arr, left, mid, mid + 1, right, tmp);
}

void MergSort(int* arr, int n) {
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergSort(arr, 0, n - 1, tmp);
	free(tmp);

}

void MergSortNonR(int* arr, int n) {
	int* tmp = (int*)malloc(sizeof(int) * n);
	int gap = 1;
	while (gap < n) {
		for (int i = 0; i < n; i += 2 * gap) {
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;//归并的右边的数组可能会越界
			if (begin2 >= n) {
				break;
			}
			if (end2 >= n) {
				end2 = n - 1;//修正end2
			}
			//归并两个区间【begin1,end1】【begin2,end2】;
			MergArry(arr, begin1, end1, begin2, end2, tmp);
		}
		gap *= 2;
	}
	free(tmp);
}
void CountSort(int* arr, int n) {
	int min = arr[0];
	int max = arr[0];
	for (int i = 1; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
		if (arr[i] < min) {
			min = arr[i];
		}
	}
	int range = max - min+1;
	int* countarry = (int*)malloc(sizeof(int) * range);
	memset(countarry, 0, sizeof(int) * range);
	for (int i = 0; i < n; i++) {
		countarry[arr[i] - min]++;
	}
	int index = 0;
	for (int j = 0; j < range; j++) {
		while (countarry[j]--) {
			arr[index++] = j + min;
		}
	}
	free(countarry);

}






























