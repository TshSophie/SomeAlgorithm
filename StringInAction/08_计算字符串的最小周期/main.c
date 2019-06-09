/*
	问题描述：
		给定一个长度为n的字符串S，如果存在一个字符串T，重复若干次T能够得到S，那么S叫做周期串，T叫做S的一个周期。
	如：
		字符串abababab是周期串，abab、ab都是他的周期，其中ab是他的最小周期。
		设计一个算法计算S的最小周期。如果 S不存在周期返回空串。

	解决方案：
		首先计算出S的next数组，
		- 记k=next[len]，p=len-k
		- 若len%p = 0,则p为最小周期长度，前p个字符就是最小周期。

*/

#include<stdio.h>

int MinPeriod(char *p)
{
	int len = strlen(p); // 串长度
	int *next = malloc(sizeof(int)*len); // 给next数组动态分配空间
	next[0] = -1; // 第一个字符k前缀默认为-1
	// 开始计算next数组
	int j = 0; // 字符位置	
	int k = -1; // 记录当前字符k前缀
	while (j < len-1)
	{		
		if (k == -1 || p[k] == p[j])
		{
			j++; // p[j+1]字符
			k++; // 上个字符的k前缀 +1
			next[j] = k; // 求出了p[j+1]的k前缀
		}
		else
		{
			k = next[k]; 
		}
	}
	for (int i = 0; i < len; i++)
	{
		printf("next[%d] = %d\n", i, next[i]);
	}

	// 计算周期
	next[0] = 0;
	int end = len - 1;
	int period = end - next[end];
	
	// 释放next数组空间
	free(next);

	if (len % period == 0)
	{
		return period;
	}
	else
	{
		return -1;
	}
}

int main()
{
	const char *str = "abcdabcdabcdabcd";
	int ret = MinPeriod(str);

	printf("period = %d\n", ret);

	system("pause");
	return 0;
}

