/*
	���ӵ�ǰ���������ֵ���պñ��������һ��������21543����һ��������23145
	- һ�����ұ��б�����������ڣ�������������ô���һ������������Ƕ��ٿ���֪����1
	- �������һ�����������С��������1�ұ�����С������3���������ǣ���ʱ�ɵõ�23xxx 
	- ��Ȼ��xxx ����������ʱ����ֵ��С���ɵõ�23145	

	����ɵ��㷨��
	��1���Ӻ���ǰ������������һ��λ��i��ת�۵㣬��S[k]>S[k+1](k>i)��S[i] < S[i+1];
	��2����i+1����(S[i+1...N-1])ȥ�ұ�S[i]�����СֵS[j];
	��3��������SWAP(S[i],S[j])
	��4����S[i]������ַ����з�ת
	(������Ϊ�ڵڡ�1����ʱ�������Ѿ��жϹ���i������ַ��Ӻ���ǰ����������ģ�
	 ���ڽ��н����ַ���ʱ���������ǰ�һ��С����������ȥ�ģ�����������ȷ����ʱ��Ȼ��һ����������У�
	 ֻҪ��ת�Ϳ��Եõ�������)

*/

#include<stdio.h>
void swap(int *a, int *b){ int temp = *a; *a = *b; *b = temp; }

// ��ת����
void Reverse(int *from, int* to)
{
	int t;
	while (from < to)
	{
		t = *from;
		*from = *to;
		*to = t;
		from++;
		to--;
	}
}


void PrintList(int *list, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
}

int GetNextPermutation(int *a, int size)
{
	// �Ӻ���ǰ��
	int i = size - 2;
	while ((i>=0)&&(a[i]>=a[i+1]))
	{
		i--;
	}
	if (i < 0)
	{
		return 0;
	}

	// �ұ�a[i]�����Сֵ
	int j = size - 1;
	while (a[j] <= a[i]) // ���˵�һ���Ļ������������ȷ�����Ӻ���i����������ģ���˿�����ô��
	{
		j--;
	}

	// ����ֵ
	swap(&a[j], &a[i]);

	// ��ת
	Reverse(a+i + 1, a + size - 1);

	return 1;
}

int main()
{
	int a[] = { 1, 2, 3, 3 };
	int size = sizeof(a) / sizeof(int);
	
	PrintList(a, size);
	while (GetNextPermutation(a,size))
	{
		PrintList(a, size);
	}

	system("pause");
	return 0;
}
