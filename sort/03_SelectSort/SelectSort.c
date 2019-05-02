#include <stdio.h>
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void PrintArray(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("arr[%d]:%d    ", i, arr[i]);
	}
	printf("\n");
}

void SelectSort(int *arr, int length)
{
	int min = 0;

	for (int i = 0; i < length; i++)
	{
		min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}

		if (min != i) // 如果有更小的值出现则交换它们
		{
			Swap(&arr[min], &arr[i]); // 交换
		}
	}
}


int main()
{
	int num[] = {3,5,1,6 };

	// print before sort
	printf("before sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	// sort
	SelectSort(num, sizeof(num) / sizeof(num[0]));

	// print after sort
	printf("after sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	system("pause");
	return 0;

}