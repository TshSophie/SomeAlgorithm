/*
	����������
	���ڳ���ΪN������A��������������ĺ���ӽ�0��ֵ��
	�磺����A��1��-2,3,10��-4,7,2,-5
	�������������У�����ӽ�0�����ĸ�?

	���������
	���ǿ�������һ��size��A��1�Ŀռ�sum[n+1]�������洢����������ĺͣ���sum[i]Ϊ����ǰi��͡�
	�����Ƶ��������Ĺ�ϵ��
	sum(a[i...j]) = sum(a[0...j]) - sum(a[0...i-1])
	Ҳ����˵�κ�һ������������ĺͶ�����������ǰj����ǰi���������õ���	
	��Ȼ��sum(a[0...j]) �� sum(a[0...i-1])��ֵ��ӽ�ʱ��sum(a[i...j])��ӽ���0
	�����㷨�������£�
	��1�����sum[0...n]��ֵ����sum[]ÿ��Ԫ���Ǹ�Ԫ����һ��Ԫ�ؼ����±�����Ӧ������a��ֵ
	��2����sum[]�����������
	��3����sum[]�����ҳ���������Ԫ��������ֵ��С�ģ����ǽ����

*/
#include<stdio.h>

void sort(int *a, int start, int end)
{
	int i = start;
	int j = end;
	int temp = a[i]; // ��׼ֵ
	if (i < j)
	{
		while (i < j)
		{
			// ���ұ������ɨ�裬�ұ�tempС��ֵ
			while (i<j && a[j] > temp)
			{
				j--;
			}
			if (i < j)
			{
				a[i] = a[j];
				i++;
			}
			// ��������ұ�ɨ�裬�ұ�temp���ֵ
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
		// ��벿��
		sort(a, 0, i - 1);
		// �ұ߲���
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