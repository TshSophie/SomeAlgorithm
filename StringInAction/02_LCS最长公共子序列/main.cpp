/*
	����������У���Longest Common Subsequence,LCS
	һ������S����ɾ�����ɸ��ַ��õ�������T����T����S�������У�
	��������X��Y�Ĺ����������У���������Ǹ�������ΪX��Y������������С�
	- �ַ���13��455����2��455��76�������������Ϊ455
	- �ַ���acdfg�͡�adf��c�������������Ϊadf


	��̬�滮�㷨��
	 
					  |---LCS(Xi-1 , Yj-1)+1 , ��Xi = Yj
	LCS(Xi , Yj) = ---|
					  |---MAX{LCS(Xi-1 , Yj),LCS(Xi,Yj-1)} , ��Xi != Yj


*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


// ע����㷨�õ���ֻ������һ�����
void LCS(const char * str1, const char *str2, string& str)
{
	int size1 = (int)strlen(str1);
	int size2 = (int)strlen(str2);
	const char* s1 = str1 - 1;
	const char* s2 = str2 - 1; // ǰһ��λ��
	vector<vector<int>> chess(size1 + 1, vector<int>(size2 + 1)); // ��̬��ά����
	// 0��0������
	int i, j;
	for ( i = 0; i <= size1; i++)chess[i][0] = 0;				
	for (j = 0; j <= size2; j++)chess[0][j] = 0;
	
	// �����ַ�
	for ( i = 1; i <= size1; i++) // ����ɨ��
	{
		for (j = 1; j <= size2; j++) // ����ɨ��
		{
			if (s1[i] == s2[j])  // ������ַ����
			{
				chess[i][j] = chess[i - 1][j - 1] + 1;	// ���Ͻǵ���ֵ��1����LCS(Xi , Yj) = LCS(Xi-1 , Yj-1)+1
			}
			else // ����ȵĻ�
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

	reverse(str.begin(), str.end()); // ��ת
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