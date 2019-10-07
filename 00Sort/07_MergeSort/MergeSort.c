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
	
	int i_start = start; // ����1��ʼλ��
	int i_end = mid; // ����1ĩβλ��

	int j_start = mid + 1; // ����2��ʼλ��
	int j_end = end; // ����2ĩβλ��

	int len = 0;

	// ��ʼ�ϲ���������
	while (i_start <= i_end && j_start <= j_end)
	{
		if (arr[i_start] < arr[j_start])
		{
			temp[len] = arr[i_start]; // ��С�������뻺��������
			i_start++;
		}
		else
		{
			temp[len] = arr[j_start]; // ��С�������뻺��������
			j_start++;
		}
		len++;
	}

	// ����������в��Գ�(�ϳ����ǲ���)������β����
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

	// �����������滻��ԭ����ȥ
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