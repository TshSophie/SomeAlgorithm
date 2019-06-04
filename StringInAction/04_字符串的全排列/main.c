/*
	����1������
	�����ַ���S[0...N-1],����㷨��ö��S��ȫ���С���
	���ַ��� 123 ��ȫ������
	1 23	1 32
	2 13	2 31
	3 12	3 21

	�ⷨһ(�ݹ��㷨):
					        1 2 3
			  _______________ |________________
			  |			      |			      |
		    1 _2_3_          2 _1_3_         3 _2_1_
		______|_____    ______|______     ______|_______
		|		   |	|           |     |            |
	 12_3_       13_2_  21_3_      23_1_  32_1_       31_2_

	 ����2������
	 �����ַ��������ظ��ַ���ȫ���У����ȥ���ظ�Ԫ�أ�
	 �����1223�������ַ��������ʹ��������ַ����ڼ�����ֻ����Ψһһ��
	 �ⷨ��
	 ����֤ÿ���ַ������ķ��ظ����ַ����н���������������ͬ���ַ���������
	 
*/
#include<stdio.h>

void swap(int *a, int *b){ int temp = *a; *a = *b; *b = temp; }

void PrintList(int *list, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ",list[i]);
	}
	printf("\n");
}

/*
	a: ����
	size: ���г���
	n: λ��
*/
void Permutation(int *a, int size, int n)
{
	if (n == size-1)
	{
		PrintList(a, size);
		return;
	}
	for (int i = n; i < size; i++)
	{
		swap(&a[i], &a[n]);
		Permutation(a, size, n + 1);
		swap(&a[i], &a[n]);
	}
}


// �Ƿ��ظ����ظ�����1�����ظ�����0
int IsDuplicate(int *a, int start, int cur)
{
	while (start < cur)
	{
		if (a[start] == a[cur])
		{
			return 0;
		}
		start++;
	}
	return 1;
}

/*
	a: ����
	size: ���г���
	n: λ��
*/
void PermutationNotDup(int *a, int size, int n)
{
	if (n == size - 1)
	{
		PrintList(a, size);
		return;
	}
	for (int i = n; i < size; i++)
	{
		if (!IsDuplicate(a,n,i)) // ���a[i]�Ƿ��Ѿ���a[n,i)���ظ�
		{
			continue;
		}
		swap(&a[i], &a[n]);
		PermutationNotDup(a, size, n + 1);
		swap(&a[i], &a[n]);
	}
}



// �ռ任ʱ���
void PermutationReduceTime(int *a, int size, int n)
{
	if (n == size - 1)
	{
		PrintList(a, size);
		return;
	}
	int dup[256] = { 0 };
	for (int i = n; i < size; i++)
	{
		if (dup[a[i]] == 1) // ���a[i]�Ƿ��Ѿ���a[n,i)���ظ�
		{
			continue;
		}
		
		dup[a[i]] = 1; // ����Ѿ����ֹ���Ԫ��

		swap(&a[i], &a[n]);
		PermutationReduceTime(a, size, n + 1);
		swap(&a[i], &a[n]);
	}
}


int main()
{
	int num[] = { 1, 2, 3,3};

	PermutationReduceTime(num, sizeof(num) / sizeof(int), 0);

	system("pause");
	return 0;
}