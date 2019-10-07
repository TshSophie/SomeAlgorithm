/*
	最长公共子序列，即Longest Common Subsequence,LCS
	一个序列S任意删除若干个字符得到新序列T，则T叫做S的子序列；
	两个序列X和Y的公共子序列中，长度最长的那个，定义为X和Y的最长公共子序列。
	- 字符串13【455】和2【455】76的最长公共子序列为455
	- 字符串acdfg和【adf】c的最长公共子序列为adf


	动态规划算法：
	 
					  |---LCS(Xi-1 , Yj-1)+1 , 当Xi = Yj
	LCS(Xi , Yj) = ---|
					  |---MAX{LCS(Xi-1 , Yj),LCS(Xi,Yj-1)} , 当Xi != Yj


*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


// 注意该算法得到的只是其中一个结果
void LCS(const char * str1, const char *str2, string& str)
{
	int size1 = (int)strlen(str1);
	int size2 = (int)strlen(str2);
	const char* s1 = str1 - 1;
	const char* s2 = str2 - 1; // 前一个位置
	vector<vector<int>> chess(size1 + 1, vector<int>(size2 + 1)); // 动态二维数组
	// 0行0列清零
	int i, j;
	for ( i = 0; i <= size1; i++)chess[i][0] = 0;				
	for (j = 0; j <= size2; j++)chess[0][j] = 0;
	
	// 遍历字符
	for ( i = 1; i <= size1; i++) // 纵向扫描
	{
		for (j = 1; j <= size2; j++) // 横向扫描
		{
			if (s1[i] == s2[j])  // 如果俩字符相等
			{
				chess[i][j] = chess[i - 1][j - 1] + 1;	// 左上角的数值加1，即LCS(Xi , Yj) = LCS(Xi-1 , Yj-1)+1
			}
			else // 不相等的话
			{
				chess[i][j] = max(chess[i][j-1],chess[i-1][j]); // LCS(Xi , Yj) = MAX{LCS(Xi-1 , Yj),LCS(Xi,Yj-1)}
			}
		}
	}

	i = size1;
	j = size2;
	while ((i !=0) && (j != 0))
	{
		if (s1[i] == s2[j])
		{
			str.push_back(s1[i]);
			i--;
			j--;
		}
		else
		{
			if (chess[i][j-1] < chess[i-1][j])			
				i--;			
			else			
				j--;			
		}
	}

	reverse(str.begin(), str.end()); // 反转
}

int main()
{
	const char *str1 = "ABCBDAB";
	const char *str2 = "BDCABA";
	string str;
	LCS(str1, str2,str);

	cout << "str1= " << str1 << endl;
	cout << "str2= " << str2 << endl;
	cout << "str= " << str<< endl;

	system("pause");
	return 0;
}