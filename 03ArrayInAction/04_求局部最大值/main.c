/*
	����һ�����ظ�Ԫ�ص�����A[0...N-1],���ҵ�һ��������ľֲ����ֵ��
	�涨��������߽����ֵ����С������A[0]>A[-1],A[N-1]>A[N]���Ӷ��ɵ����¾ֲ����ֵ����ʽ������
	a* = one of {a[i]|a[i] > a[i-1]��a[i] > a[i+1],0 <= i <= n-1}
	- ����һ���ȫ�����ֵ������Ȼ�Ǿֲ����ֵ
	- �ɷ��и���İ취��

	���������
	- ʹ������left��right�ֱ�ָ��������β�����ݶ��壬������ΪĿ������
	- ���е�mid=(left+right)/2
	- A[mid]>A[mid+1]��������A[left..mid]ΪĿ������
		+ �������Σ�right=mid
	- A[mid+1]>A[mid]��������A[mid..right]ΪĿ������
		+ ����ǰ��Σ�left=mid+1
	- �ݹ�ֱ��left=right
*/

#include<stdio.h>

// ע�⣺�޷��ҵ����еľֲ����ֵ
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