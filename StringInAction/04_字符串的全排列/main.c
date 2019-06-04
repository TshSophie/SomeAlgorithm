/*
	问题1描述：
	给定字符串S[0...N-1],设计算法，枚举S的全排列。、
	如字符串 123 的全排列有
	1 23	1 32
	2 13	2 31
	3 12	3 21

	解法一(递归算法):
					        1 2 3
			  _______________ |________________
			  |			      |			      |
		    1 _2_3_          2 _1_3_         3 _2_1_
		______|_____    ______|______     ______|_______
		|		   |	|           |     |            |
	 12_3_       13_2_  21_3_      23_1_  32_1_       31_2_

	 问题2描述：
	 对于字符串中有重复字符的全排列，如何去除重复元素，
	 如对于1223这样的字符串，如何使得输出的字符串在集合中只存在唯一一份
	 解法：
	 即保证每个字符与后面的非重复的字符进行交换，若碰到有相同的字符则跳过。
	 
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
	a: 数列
	size: 数列长度
	n: 位置
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


// 是否重复，重复返回1，不重复返回0
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
	a: 数列
	size: 数列长度
	n: 位置
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
		if (!IsDuplicate(a,n,i)) // 检查a[i]是否已经在a[n,i)有重复
		{
			continue;
		}
		swap(&a[i], &a[n]);
		PermutationNotDup(a, size, n + 1);
		swap(&a[i], &a[n]);
	}
}



// 空间换时间版
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
		if (dup[a[i]] == 1) // 检查a[i]是否已经在a[n,i)有重复
		{
			continue;
		}
		
		dup[a[i]] = 1; // 标记已经出现过的元素

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