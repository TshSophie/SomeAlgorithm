/*
	Longest Increaseing Subsequence，LCS
	找出给定数组最长且单调递增的子序列。
	如：给定数组{5,6,7,1,2,8},则其最长的单调递增子序列为{5,6,7,8}，长度为4

	解法1：
	可以将此问题转换为LCS问题来求解,如对于
	序列 A {5,6,7,1,2,8}
	排序后的 A {1，2，5，6，7，8}
	再对上面两个序列进行求最长公共子序列即可

	解法二：动态规划

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
  p: 序列
  length: 序列长度
  pre: 保存递增序列元素位置序号
  nIndex: 传出参数，最长子序列尾元素位置序号
*/
int LIS(const int* p, int length, int * pre, int & nIndex)
{
	int * longest = new int[length]; // 保存各个元素当前最长序列长度
	int i, j;
	for ( i = 0; i < length; i++)
	{
		longest[i] = 1;
		pre[i] = -1;
	}

	int nLis = 1;
	nIndex = 0;
	for ( i = 1; i < length; i++) // 遍历序列
	{
		for (j = 0; j < i; j++) // 遍历前面的元素
		{
			if (p[j] <= p[i]) // ai >= aj
			{
				if (longest[i] < longest[j] + 1)
				{
					longest[i] = longest[j] + 1;
					pre[i] = j; // 记录前驱元素位置
				}
			}
		}
		if (nLis < longest[i])
		{
			nLis = longest[i];
			nIndex = i;
		}
	}
	delete[] longest;
	return nLis; // 返回最长递增子序列长度
}


/*
	array: 序列
	pre: 递增序列元素位置序号
	nIndex:最长子序列尾元素位置序号
	lis: 传出参数，保存最长递增子序列
*/
void GetLIS(const int* array, const int * pre, int nIndex, vector<int>& lis)
{
	while (nIndex >= 0)
	{		
		lis.push_back(array[nIndex]);
		nIndex = pre[nIndex];
	}
	reverse(lis.begin(), lis.end());
}

int main()
{
	int array[] = { 1, 4, 5, 6, 2, 3, 8, 9, 10, 11, 1 };
	int size = sizeof(array) / sizeof(int);
	int *pre = new int[size];
	int nIndex;
	int max = LIS(array, size, pre, nIndex);
	vector<int> lis;
	GetLIS(array, pre, nIndex, lis);
	delete[] pre;
	cout << max << endl;
	
	int len = (int)lis.size();
	for (int i = 0; i < len; i++)
	{
		cout << lis[i] << "\t";
	}
	cout << endl;
	system("pause");
	return 0;
}