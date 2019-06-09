/*
	问题描述：
		仅由三个字符A,B,C构成字符串，且字符串任意三个相邻元素不能完全相同。如
		"ACCCAB"不合法，"ABBCBCA"合法
		求满足条件的长度为n的字符串个数
		- 假定不考虑整数溢出
		- 要求时间和空间复杂度不高于O(N)

		解决方案：
			 |---dp[n][0] = 2*dp[n-1][0] + 2*dp[n-1][1]
 状态转移方程——|
			 |---dp[n][1] = dp[n-1][0]

		分析：
		如果当前已经有了所有长度为n-1合法字符串，怎样在末尾增加一个字符，形成长度为n的字符串呢？
		可以将n-1字符串的情况进行归类：
		【1】末尾俩字符不相等，记作dp[n-1][0]				
		【2】末尾俩字符相等, 记作dp[n-1][1]

		再来分析dp[n][0]结尾不相等/dp[n][1]结尾相等
		【0】dp[n-1]: xx...x ab/- xx...x aa
		【1】 dp[n][0] = 2*dp[n-1][0] + 2*dp[n-1][1]
			- xx...x ab a  - xx...x ab c
			- xx...x aa b  - xx...x aa c
		【2】dp[n][1] = dp[n-1][0]
			- xx...x ab b

		初始条件：
		dp[1][0] = 3 (a,b,c)
		dp[1][1] = 0							
*/

#include<stdio.h>

int CacCount(int n)
{
	int nNonRepeat = 3;
	int nRepeat = 0;
	int t;
	for (int i = 2; i <= n; i++)
	{
		t = nNonRepeat;
		nNonRepeat = 2 * (nNonRepeat + nRepeat);
		nRepeat = t;
	}

	return nRepeat + nNonRepeat;
}

int main()
{

	system("pause");
	return 0;
}
