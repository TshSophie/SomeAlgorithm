/*
	问题描述：
	给定字符串str，若子串s是回文串，称s为str的回文子串。设计算法，计算str的最长回文子串

	算法：Manacher


*/
#include<stdio.h>

void Manacher(char * s, int * p)
{
	int size = strlen(s);
	p[0] = 1;   // 首字符回文长度默认为1
	int id = 0; // 记录最长回文中心点
	int mx = 1; // 记录最长回文长度
	for (int i = 1; i < size; i++) // 遍历字符
	{
		// mx > i 说明mx能够包含i， \
		   这种情况下是可以做优化的，即i的回文长度与id相对称的那个元素p[2 * id - i]的回文长度是相等的(在mx范围内)
		if (mx > i)
		{
			p[i] = p[2 * id - i] < mx - i ? p[2 * id - i] : mx - i; // 一定是mx-i范围内的才敢保证
		}
		else
		{
			p[i] = 1;
		}

		// 探索下一个元素是否能成为回文新边界
		for (; s[i + p[i]] == s[i - p[i]]; p[i]++); // 考察下一个元素是否是回文，是就++

		// 记录此时已知的最长的回文
		if (mx < i+p[i]) // 更新mx，使得在0~i范围内mx是最长的那个回文的下标，而id即此回文的中心点
		{
			mx = i + p[i];
			id = i;
		}
	}
}



int main()
{
	// 预处理后的字符串
	char * str = "$#1#2#2#1#2#3#2#1#";	

	int size = strlen(str);
	int p[30] = { 0 };

	Manacher(str, p);

	for (int i = 0; i < size; i++)
	{
		printf("str[%d] = %c; p[%d] = %d\n",i,str[i], i, p[i]);
	}

	system("pause");
	return 0;
}