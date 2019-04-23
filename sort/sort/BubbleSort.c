#include<stdio.h>

void Swap(int *a,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(int *arr, int len)
{
	for (int j = len - 1; j > 0; j--)
	{
		for (int i = 0; i < j; i++)
		{
			if (arr[i] < arr[i+1])
			{
				Swap(&arr[i], &arr[i + 1]);
			}
		}

	}
}

void PrintArray(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("arr[%d]:%d    ", i, arr[i]);
	}
	printf("\n");
}

int main()
{
	int num[] = { 5, 8, 4, 7};

	// print before sort
	printf("before sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	// sort
	BubbleSort(num, sizeof(num) / sizeof(num[0]));

	// print after sort
	printf("after sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	system("pause");
	return 0;
}