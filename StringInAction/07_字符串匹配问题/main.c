/*
	问题描述：
	给定文本串text和模式串pattern，从文本串中找出模式串pattern第一次出现的位置。
	- 最基本的解法：
		暴力求解（Brute Force）其时间复杂度为O(m*n)，空间复杂度为O(1)
	- KMP算法
		一种线性时间复杂度的算法，是BF的改进版 其时间复杂度为O(m+n)，空间复杂度为O(m) 

*/

#include<stdio.h>

int BruteForceSearch(const char * s, const char *p)
{
	int i = 0; // 原始串位置
	int j = 0; // 模式串位置
	int pSize = strlen(p);

	while (s[i]) // 遍历原始串
	{
		if (s[i+j] == p[j]) // 对比模式串
		{
			j++; // 对比模式串下一个字符
		}
		else
		{
			i++;
			j = 0; // 模式串指针回到原点
		}

		if (j >= pSize)
		{
			return i;
		}
	}
	
	return -1;
}


//////////////////////////// KMP算法//////////////////////////////////////////

void GetNext(const char *p, int next[]) // 计算next数组
{
	int nLen = strlen(p); // 模式串长度
	next[0] = -1; // 第一个字符必定为 -1
	int k = -1; 
	int j = 0;
	while (j < nLen - 1)
	{
		// 前缀p[j]和后缀p[k]相等时
		// k == -1表示没有找到k前缀与k后缀相等
		if (k == -1 || p[j] == p[k])
		{
			++j; // 下一个字符
			++k;
			next[j] = k;
		}
		else // 匹配失败，则继续递归计算前缀p[next[k]]
		{
			k = next[k];  // 为什么可以这样呢？因为有了前面的k做保证，我们是可以确定
						  // P[0~k) = P[j-k,j) ，因此我们可以放心的在[0~k)缩小范围去寻找相等的字符
		}
	}
}


int KMP(const char * s, const char *p)
{
	int i = 0; // 原始串位置
	int j = 0; // 模式串位置
	int pSize = strlen(p);
	int next[255] = { 0 };
	// 计算next数组
	GetNext(p, next);

	while (s[i]) // 遍历原始串
	{
		if (j == -1 || s[i] == p[j]) // 对比模式串
		{
			i++;
			j++; // 对比模式串下一个字符
		}
		else
		{
			j = next[j]; 
		}

		if (j == pSize)
		{
			return i - pSize;
		}
	}
	return -1;
}


void test1()
{
	const char *s = "abcdefg";
	const char *p = "cd";

	int ret = BruteForceSearch(s, p);

	printf("position = %d\n", ret);

}


void test2()
{
	const char *s = "abaabcaba";
	int a[20] = { 0 };

	GetNext(s,a);

	for (int i = 0; i < strlen(s); i++)
	{
		printf("%d ",a[i]);
	}
}

void test3()
{
	const char *s = "abcdefg";
	const char *p = "cd";

	int ret = KMP(s, p);

	printf("position = %d\n", ret);
}


int main()
{
	test3();
	system("pause");
	return 0;
}



