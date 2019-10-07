#include <stdio.h>

void PrintArray(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("arr[%d]:%d    ", i, arr[i]);
	}
	printf("\n");
}

void Merge(int *arr, int start, int end, int mid, int *temp){
	
	int i_start = start; // 序列1开始位置
	int i_end = mid; // 序列1末尾位置

	int j_start = mid + 1; // 序列2开始位置
	int j_end = end; // 序列2末尾位置

	int len = 0;

	// 开始合并两个序列
	while (i_start <= i_end && j_start <= j_end)
	{
		if (arr[i_start] < arr[j_start])
		{
			temp[len] = arr[i_start]; // 将小的数放入缓存数组中
			i_start++;
		}
		else
		{
			temp[len] = arr[j_start]; // 将小的数放入缓存数组中
			j_start++;
		}
		len++;
	}

	// 针对两个序列不对称(较长的那部分)进行收尾处理
	while (i_start <= i_end)
	{
		temp[len] = arr[i_start]; 
		i_start++;
		len++;
	}

	while (i_start <= i_end)
	{
		temp[len] = arr[j_start]; 
		j_start++;
		len++;
	}

	// 将缓存数组替换到原数组去
	for (int i = 0; i < len; i++)
	{
		arr[start + i] = temp[i];
	}
}

void MergeSort(int *arr, int start, int end, int *temp){

	if (start >= end){
		return;
	}

	int mid = (start + end) / 2;

	MergeSort(arr, start, mid, temp);

	MergeSort(arr, mid + 1, end, temp);

	Merge(arr, start, end, mid, temp);
}

int main(){

	int num[] = { 5, 9, 4, 7, 3, 6, 19, 6, 3 };

	int temp[9];

	// print before sort
	printf("before sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	// sort
	MergeSort(num, 0, (sizeof(num) / sizeof(num[0])) - 1,temp);

	// print after sort
	printf("after sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	system("pause");
	return 0;

}