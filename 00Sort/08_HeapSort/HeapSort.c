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

// ������
// arr ������������
// pos �������ĵ�
// len ���������еĳ���
void AdjustHeap(int *arr, int pos, int len){

	// ���ӽڵ�
	int left = pos * 2 + 1;
	// ���ӽڵ�
	int right = pos * 2 + 2;
	int max = pos;

	// �Ƚϣ����ϴ�����������Ѷ�
	if (left < len && arr[max] < arr[left])
	{
		max = left;
	}
	if (right < len && arr[max] < arr[right])
	{
		max = right;
	}

	if (max != pos) // ˵���б�����
	{
		MySwap(arr, max, pos);
		// ��Ӧ�ı��������Ǹ���Ҳ������Ҫ�����µ���
		AdjustHeap(arr, max, len);
	}
}

void HeapSort(int *arr,int start,int end){

	int len = end + 1;
	// ��ʼ����
	for (int i = (len / 2) - 1; i >= 0; i--)
	{
		AdjustHeap(arr, i, len);
	}

	// �����Ѷ�Ԫ�غ�δ�����������һ��Ԫ��
	for (int i = len - 1; i >= 0; i--)
	{
		MySwap(arr, 0, i);
		// �ӶѶ���ʼ����
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