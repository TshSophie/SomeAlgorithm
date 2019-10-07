/*
	即从当前排列生成字典序刚好比它大的下一个排列如21543的下一个排列是23145
	- 一个数右边有比它大的数存在，它就能增大，那么最后一个能增大的数是多少可以知道是1
	- 如何找下一个比它大的最小的数？在1右边找最小的数即3，交换他们，此时可得到23xxx 
	- 显然，xxx 按升序排列时，数值最小，可得到23145	

	整理可的算法：
	【1】从后往前查找升序的最后一个位置i，转折点，即S[k]>S[k+1](k>i)，S[i] < S[i+1];
	【2】从i+1后面(S[i+1...N-1])去找比S[i]大的最小值S[j];
	【3】交换：SWAP(S[i],S[j])
	【4】将S[i]后面的字符进行翻转
	(这里因为在第【1】的时候我们已经判断过了i后面的字符从后往前看都是升序的，
	 而在进行交换字符的时候我们又是把一个小的数给换过去的，因此这里可以确保此时仍然是一个升序的序列，
	 只要翻转就可以得到降序了)

*/

#include<stdio.h>
void swap(int *a, int *b){ int temp = *a; *a = *b; *b = temp; }

// 反转序列
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
	// 从后往前找
	int i = size - 2;
	while ((i>=0)&&(a[i]>=a[i+1]))
	{
		i--;
	}
	if (i < 0)
	{
		return 0;
	}

	// 找比a[i]大的最小值
	int j = size - 1;
	while (a[j] <= a[i]) // 有了第一步的基础，这里可以确保，从后往i看，是升序的，因此可以这么做
	{
		j--;
	}

	// 交换值
	swap(&a[j], &a[i]);

	// 翻转
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
