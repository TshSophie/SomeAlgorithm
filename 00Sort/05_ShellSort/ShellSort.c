#include<stdio.h>

void PrintArray(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("arr[%d]:%d    ", i, arr[i]);
	}
	printf("\n");
}

void ShellSort(int *arr, int length)
{

	int increasement = length;

	do{

		increasement = increasement / 3 + 1; // 分组算法

		for (int k = 0; k < increasement; k++)
		{
			// 插入排序
			for (int i = increasement + k; i < length; i += increasement)
			{
				if (arr[i] > arr[i - increasement]) // 从无序列表找较大的元素
				{
					int temp = arr[i];
					// 在有序列表里找一个合适的位置(直到找不到比自己还大的元素)
					int j;
					for (j = i - increasement; j >= 0 && temp > arr[j]; j -= increasement) 
					{
						arr[j + increasement] = arr[j]; // 向右边挪动元素
					}
					
					arr[j + increasement] = temp; // 将元素插入有序列表
					
				}
			}
		}

	} while (increasement > 1);

}

int main()
{

	//int num[] = { 5,9,4,7,3,6 };
	int num[] = { 5,9,4,7,3,6,19,6,3,4,2,99,100,45,32,2,1,8 };

	// print before sort
	printf("before sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	// sort
	ShellSort(num, sizeof(num) / sizeof(num[0]));

	// print after sort
	printf("after sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	system("pause");
	return 0;
}
