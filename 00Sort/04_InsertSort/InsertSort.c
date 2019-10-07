#include<stdio.h>


void PrintArray(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("arr[%d]:%d    ", i, arr[i]);
	}
	printf("\n");
}


// ����
void InsertSort(int *arr, int length)
{
	// �ٶ���һ��Ԫ��Ϊ�������У�������Ԫ��Ϊ��������
	for (int i = 1; i < length; i++)
	{
		if (arr[i] < arr[i - 1]) //  ������������ѡ��һ������������βԪ��С����
		{
			int temp = arr[i];
			int j;
			for (j = i - 1; j >= 0 && temp < arr[j]; j--) // ��ѡ����Ԫ�ط����������к��ʵ�λ��
			{
				arr[j + 1] = arr[j]; // ���ұ��ƶ�Ԫ��
			}
			// ��Ԫ�ط�����������
			arr[j + 1] = temp;
		}
	}
}

int main()
{
	int num[] = { 5,3,6,7,2 };

	// print before sort
	printf("before sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	// sort
	InsertSort(num, sizeof(num) / sizeof(num[0]));

	// print after sort
	printf("after sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	system("pause");
	return 0;

}