#include<stdio.h>


void PrintArray(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("arr[%d]:%d    ", i, arr[i]);
	}
	printf("\n");
}


// 升序
void InsertSort(int *arr, int length)
{
	// 假定第一个元素为有序序列，而其后的元素为无序序列
	for (int i = 1; i < length; i++)
	{
		if (arr[i] < arr[i - 1]) //  从无序序列中选出一个比有序序列尾元素小的来
		{
			int temp = arr[i];
			int j;
			for (j = i - 1; j >= 0 && temp < arr[j]; j--) // 将选出的元素放入有序序列合适的位置
			{
				arr[j + 1] = arr[j]; // 向右边移动元素
			}
			// 将元素放入有序序列
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