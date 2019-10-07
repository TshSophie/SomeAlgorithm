/*
	给定一个无重复元素的数组A[0...N-1],求找到一个该数组的局部最大值。
	规定：在数组边界外的值无穷小。即：A[0]>A[-1],A[N-1]>A[N]。从而可得如下局部最大值的形式化定义
	a* = one of {a[i]|a[i] > a[i-1]且a[i] > a[i+1],0 <= i <= n-1}
	- 遍历一遍得全局最大值，它显然是局部最大值
	- 可否有更快的办法？

	解决方案：
	- 使用索引left、right分别指向数组首尾，根据定义，该数组为目标数组
	- 求中点mid=(left+right)/2
	- A[mid]>A[mid+1]，子数组A[left..mid]为目标数组
		+ 丢弃后半段：right=mid
	- A[mid+1]>A[mid]，子数组A[mid..right]为目标数组
		+ 丢弃前半段：left=mid+1
	- 递归直至left=right
*/

#include<stdio.h>

// 注意：无法找到所有的局部最大值
int localMaximum(int *A, int size)
{
	int left = 0;
	int right = size - 1;
	int mid;
	while (left < right)
	{
		mid = (left + right) / 2;
		printf("%d\n", mid);
		if ((A[mid] > A[mid+1]))
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	
	return A[left];
}

int main()
{
	int a[] = { 1, 3, 5, 4, 9, 6, 7, 9 };

	int ret = localMaximum(a, sizeof(a) / sizeof(int));

	printf("ret = %d\n", ret);

	system("pause");
	return 0;
}