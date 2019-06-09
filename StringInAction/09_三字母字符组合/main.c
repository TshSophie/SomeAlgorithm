/*
	����������
		���������ַ�A,B,C�����ַ��������ַ���������������Ԫ�ز�����ȫ��ͬ����
		"ACCCAB"���Ϸ���"ABBCBCA"�Ϸ�
		�����������ĳ���Ϊn���ַ�������
		- �ٶ��������������
		- Ҫ��ʱ��Ϳռ临�ӶȲ�����O(N)

		���������
			 |---dp[n][0] = 2*dp[n-1][0] + 2*dp[n-1][1]
 ״̬ת�Ʒ��̡���|
			 |---dp[n][1] = dp[n-1][0]

		������
		�����ǰ�Ѿ��������г���Ϊn-1�Ϸ��ַ�����������ĩβ����һ���ַ����γɳ���Ϊn���ַ����أ�
		���Խ�n-1�ַ�����������й��ࣺ
		��1��ĩβ���ַ�����ȣ�����dp[n-1][0]				
		��2��ĩβ���ַ����, ����dp[n-1][1]

		��������dp[n][0]��β�����/dp[n][1]��β���
		��0��dp[n-1]: xx...x ab/- xx...x aa
		��1�� dp[n][0] = 2*dp[n-1][0] + 2*dp[n-1][1]
			- xx...x ab a  - xx...x ab c
			- xx...x aa b  - xx...x aa c
		��2��dp[n][1] = dp[n-1][0]
			- xx...x ab b

		��ʼ������
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
