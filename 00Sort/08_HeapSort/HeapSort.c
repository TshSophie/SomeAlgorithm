#include <stdio.h>

void PrintArray(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("arr[%d]:%d    ", i, arr[i]);
	}
	printf("\n");
}

void MySwap(int arr[], int a, int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

// 调整堆
// arr 待调整的序列
// pos 待调整的点
// len 待调整序列的长度
void AdjustHeap(int *arr, int pos, int len){

	// 左子节点
	int left = pos * 2 + 1;
	// 右子节点
	int right = pos * 2 + 2;
	int max = pos;

	// 比较，将较大的数调整到堆顶
	if (left < len && arr[max] < arr[left])
	{
		max = left;
	}
	if (right < len && arr[max] < arr[right])
	{
		max = right;
	}

	if (max != pos) // 说明有被调整
	{
		MySwap(arr, max, pos);
		// 对应的被调整的那个点也可能需要再做下调整
		AdjustHeap(arr, max, len);
	}
}

void HeapSort(int *arr,int start,int end){

	int len = end + 1;
	// 初始化堆
	for (int i = (len / 2) - 1; i >= 0; i--)
	{
		AdjustHeap(arr, i, len);
	}

	// 交换堆顶元素和未排序序列最后一个元素
	for (int i = len - 1; i >= 0; i--)
	{
		MySwap(arr, 0, i);
		// 从堆顶开始调整
		AdjustHeap(arr, 0, i);
	}
}

int main(){

	int num[] = { 5, 9, 4, 7, 3, 6, 19, 6, 3 };

	int temp[9];

	// print before sort
	printf("before sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	// sort
	HeapSort(num, 0, (sizeof(num) / sizeof(num[0])) - 1);

	// print after sort
	printf("after sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	system("pause");
	return 0;
}