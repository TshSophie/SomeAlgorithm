#include<stdio.h>
void PrintArray(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("arr[%d]:%d    ", i, arr[i]);
	}
	printf("\n");
}
void QuickSort(int *arr,int start,int end)
{
	// ��ʼλ��
	int i = start;
	int j = end;

	int temp = arr[i]; //���׼��Ϊ��һ��Ԫ��
	if (i < j)
	{
		while (i < j)
		{
			// ����������С�ڻ�׼����
			while (i < j && arr[j] > temp)
			{
				j--;
			}
			// �ҵ��˾ͷ���iλ��
			if (i < j)
			{
				arr[i] = arr[j];
				i++;
			}

			// ���������Ҵ��ڻ�׼����
			while (i < j && arr[j] < temp)
			{
				i++;
			}
			// �ҵ��˾ͷ���jλ��
			if (i < j)
			{
				arr[j] = arr[i];
				j--;
			}
		}

		arr[i] = temp;

		// ����벿�ֽ�������
		QuickSort(arr, start, i - 1);
		// ���Ұ벿�ֽ�������
		QuickSort(arr, i + 1, end);


	}
}

int main()
{

	//int num[] = { 5,9,4,7,3,6 };
	int num[] = { 5, 9, 4, 7, 3, 6, 19, 6, 3, 4, 2, 99, 100, 45, 32, 2, 1, 8 };

	// print before sort
	printf("before sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	// sort
	QuickSort(num, 0, (sizeof(num) / sizeof(num[0]))-1);

	// print after sort
	printf("after sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	system("pause");
	return 0;
}
