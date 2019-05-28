#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
/*
 ���⣺
 ����һ���ַ���a��һ���ַ���b����������жϳ�����ַ���b�����е��ַ��Ƿ��ڳ��ַ���a�У�
 �磺�ַ���a��ABCD,�ַ���b��BAD������true
 �磺�ַ���a��ABCD,�ַ���b��BDE������false
 �磺�ַ���a��ABCD,�ַ���b��AA������true
 ���д����bool StringContain(string &a,string &b)

*/

#if 0
// �ⷨһ��������ѯ \
	��ѯ���ַ���b�е�ÿһ���ַ�������볤�ַ���a�е�ÿ���ַ����бȽϣ����Ƿ����ַ���a��
int StringContain(char *strA, int lenA,char *strB,int lenB)  // �ռ临�Ӷȣ�1 ʱ�临�Ӷȣ�mn
{
	int i = 0;
	int j = 0;
	for (i = 0; i < lenB; i++)
	{
		for (j = 0; j < lenA; j++)
		{
			if (strB[i] == strA[j])
			{
				break;
			}
		}
		if (j >= lenA)
		{
			return 0;
		}
	}

	return 1;
}

int main()
{

	char strA[] = "ABCD";
	char strB[] = "AA";

	int a = StringContain(strA, strlen(strA), strB, strlen(strB));

	printf("a = %d\n", a);

	return 0;
}


#endif


#if 0

// �ⷨ2���������ѯ\
   �ȶ��������ַ����е���ĸ��������Ȼ���ڶ������ַ���������ѯ\
   ��������£������ַ�����������Ҫmlogm + nlogn������֮�������ɨ����Ҫm+n�β���

bool StringContain(string &a, string &b)// �ռ临�Ӷȣ�1 ʱ�临�Ӷȣ�mn
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int j = 0;
	for (int i = 0; i < b.length(); i++)
	{
		for (j = 0; j < a.length(); j++)
		{
			if (b[i] == a[j])
			{
				break;
			}
		}
		if (j >= a.length())
		{
			return false;
		}
	}

	return true;
}

int main()
{
	string strA = "ABCD";
	string strB = "AR";

	bool a = StringContain(strA,  strB);

	printf("a = %d\n", a);

	return 0;
}

#endif

#if 0
// �ⷨ�����������\
   1 ���մ�С�����˳����26�������ֱ���泤�ַ���a�е�������ĸ��\
   2 �������ַ���a�����a�е�������ĸ��Ӧ�������ĳ˻�\
   3 �������ַ���b���ж���һ���õ��ĳ˻��ܷ�b�е���ĸ��Ӧ����������\
   4 ������

bool StringContain(string &a, string &b)// �ռ临�Ӷȣ�1 ʱ�临�Ӷȣ�m+n
{

	const int p[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 31, 37, 41, 43, 47, 
						53, 59, 61, 71, 73, 79, 83, 89, 97, 101 };
	int f = 1;
	for (int i = 0; i < a.length(); i++)
	{
		int x = p[a[i] - 'A'];
		if (f % x)  // �ų��ظ�����
		{
			f *= x;
		}
	}
	for (int i = 0; i < b.length(); ++i)
	{
		int x = p[b[i] - 'A'];
		if (f % x) // �ж��ܷ�����
		{
			return false;
		}
	}
	return true;
}


int main()
{
	string strA = "ABACD";
	string strB = "AA";

	bool a = StringContain(strA, strB);

	printf("a = %d\n", a);

	return 0;
}

#endif

#if 0

// λ���㷨
// ��λ����(26λ������ʾ)Ϊ���ַ���a�����һ����ǩ����������һ�����ַ���b�е��ַ��ŵ�a�н��в���

bool StringContain(string &a, string &b) // �ռ临�Ӷȣ�1 ʱ�临�Ӷȣ�m+n
{
	int hash = 0;
	for (int i = 0; i < a.length(); ++i)
	{
		hash |= (1 << (a[i] - 'A'));  // 3 = 0010  --�� 0100 | 0000 = 0100  �� \
											ͨ����λȡ�����㣬��¼�ַ����ҿ��Թ��˵���ͬ���ַ���ֻ����һ��
	}

	for (int i = 0; i < b.length(); ++i)
	{
		if ((hash & (1 << (b[i] - 'A'))) == 0) // ͨ��������������b���ַ��Ƿ���a��
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string strA = "ABACD";
	string strB = "AA";

	bool a = StringContain(strA, strB);

	printf("a = %d\n", a);

	return 0;
}


#endif


#if 1
/*
 ��չ�⣺
	 ��������ַ����е��ַ�һ�������ִ���Ҳһ����ֻ�ǳ���˳��һ����
	 ����Ϊ�������ַ������ֵ��ַ��������硰bad���͡�adb����Ϊ�ֵ��ַ�����
	 �����ṩһ���ַ���������������ֵ���Ѹ���ҵ������ֵ��ַ���

*/

bool checkString(string &str1, string &str2)
{
	// �����жϳ����Ƿ����
	if (str1.length() != str2.length())
	{
		return false;
	}

	int hash1 = 0;
	for (int i = 0; i < str1.length(); ++i)
	{
		hash1 |= (1 << (str1[i] - 'A'));  
	}

	int hash2 = 0;
	for (int i = 0; i < str2.length(); ++i)
	{
		hash2 |= (1 << (str2[i] - 'A'));
	}

	return hash1 == hash2;
}


int main()
{
	string str1 = "aabc";
	string str2 = "abc";

	bool a = checkString(str1, str2);

	printf("a = %d\n", a);

}

#endif 