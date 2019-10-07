/*
	问题描述：
	对于长度为N的数组A，求连续子数组的和最接近0的值。
	如：数组A：1，-2,3,10，-4,7,2,-5
	它所有子数组中，和最接近0的是哪个?

	解决方案：
	我们可以申请一个size比A长1的空间sum[n+1]，用来存储连续子数组的和，即sum[i]为数组前i项和。
	可以推导出这样的关系：
	sum(a[i...j]) = sum(a[0...j]) - sum(a[0...i-1])
	也就是说任何一个连续子数组的和都可以用两个前j和与前i项和相差来得到。	
	显然当sum(a[0...j]) 和 sum(a[0...i-1])的值最接近时，sum(a[i...j])最接近于0
	综上算法整理如下：
	【1】求出sum[0...n]的值，即sum[]每个元素是该元素上一个元素加上下标所对应的数组a的值
	【2】对sum[]数组进行排序
	【3】从sum[]数组找出连续两个元素相差绝对值最小的，即是结果了

*/
#include<stdio.h>

void sort(int *a, int start, int end)
{
	int i = start;
	int j = end;
	int temp = a[i]; // 基准值
	if (i < j)
	{
		while (i < j)
		{
			// 从右边往左边扫描，找比temp小的值
			while (i<j && a[j] > temp)
			{
				j--;
			}
			if (i < j)
			{
				a[i] = a[j];
				i++;
			}
			// 从左边往右边扫描，找比temp大的值
			while (i<j &&  a[i] < temp)
			{
				i++;
			}
			if (i < j)
			{
				a[j] = a[i];
				j--;
			}
		}
		a[i] = temp;
		// 左半部分
		sort(a, 0, i - 1);
		// 右边部分
		sort(a, i + 1, end);
	}
}

int MinSubarray(const int * a, int size)
{
	int * sum = malloc( sizeof(int)*(size + 1));
	sum[0] = 0;
	int i;
	for (int i = 0; i < size; i++)
	{
		sum[i + 1] = sum[i] + a[i];
	}	
	
	for (int j = 0; j <= size; j++)
	{
		printf("%d ", sum[j]);
	}
	
	printf("\n","");
	
	sort(sum, 0, size);

	for (int j = 0; j <= size; j++)
	{
		printf("%d ", sum[j]);
	}
	int diff = abs(sum[1] - sum[0]);
	int res = diff;
	for (i = 0; i < size; i++)
	{
		int diff = abs(sum[i+1] - sum[i]);
		res = diff < res ? diff : res;
	}
	free(sum);

	return res;
}

int main()
{
	int a[] = { 1, -2, 3, 10, -4, 7, 2, -5 };

	int ret = MinSubarray(a, sizeof(a) / sizeof(int));
	printf("ret = %d\n", ret);

	system("pause");
	return 0;
}