/*
	Longest Increaseing Subsequence��LCS
	�ҳ�����������ҵ��������������С�
	�磺��������{5,6,7,1,2,8},������ĵ�������������Ϊ{5,6,7,8}������Ϊ4

	�ⷨ1��
	���Խ�������ת��ΪLCS���������,�����
	���� A {5,6,7,1,2,8}
	������ A {1��2��5��6��7��8}
	�ٶ������������н���������������м���

	�ⷨ������̬�滮

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
  p: ����
  length: ���г���
  pre: �����������Ԫ��λ�����
  nIndex: �����������������βԪ��λ�����
*/
int LIS(const int* p, int length, int * pre, int & nIndex)
{
	int * longest = new int[length]; // �������Ԫ�ص�ǰ����г���
	int i, j;
	for ( i = 0; i < length; i++)
	{
		longest[i] = 1;
		pre[i] = -1;
	}

	int nLis = 1;
	nIndex = 0;
	for ( i = 1; i < length; i++) // ��������
	{
		for (j = 0; j < i; j++) // ����ǰ���Ԫ��
		{
			if (p[j] <= p[i]) // ai >= aj
			{
				if (longest[i] < longest[j] + 1)
				{
					longest[i] = longest[j] + 1;
					pre[i] = j; // ��¼ǰ��Ԫ��λ��
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
	return nLis; // ��������������г���
}


/*
	array: ����
	pre: ��������Ԫ��λ�����
	nIndex:�������βԪ��λ�����
	lis: �������������������������
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