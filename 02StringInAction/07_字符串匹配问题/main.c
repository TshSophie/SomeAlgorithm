/*
	����������
	�����ı���text��ģʽ��pattern�����ı������ҳ�ģʽ��pattern��һ�γ��ֵ�λ�á�
	- ������Ľⷨ��
		������⣨Brute Force����ʱ�临�Ӷ�ΪO(m*n)���ռ临�Ӷ�ΪO(1)
	- KMP�㷨
		һ������ʱ�临�Ӷȵ��㷨����BF�ĸĽ��� ��ʱ�临�Ӷ�ΪO(m+n)���ռ临�Ӷ�ΪO(m) 

*/

#include<stdio.h>

int BruteForceSearch(const char * s, const char *p)
{
	int i = 0; // ԭʼ��λ��
	int j = 0; // ģʽ��λ��
	int pSize = strlen(p);

	while (s[i]) // ����ԭʼ��
	{
		if (s[i+j] == p[j]) // �Ա�ģʽ��
		{
			j++; // �Ա�ģʽ����һ���ַ�
		}
		else
		{
			i++;
			j = 0; // ģʽ��ָ��ص�ԭ��
		}

		if (j >= pSize)
		{
			return i;
		}
	}
	
	return -1;
}


//////////////////////////// KMP�㷨//////////////////////////////////////////

void GetNext(const char *p, int next[]) // ����next����
{
	int nLen = strlen(p); // ģʽ������
	next[0] = -1; // ��һ���ַ��ض�Ϊ -1
	int k = -1; 
	int j = 0;
	while (j < nLen - 1)
	{
		// ǰ׺p[j]�ͺ�׺p[k]���ʱ
		// k == -1��ʾû���ҵ�kǰ׺��k��׺���
		if (k == -1 || p[j] == p[k])
		{
			++j; // ��һ���ַ�
			++k;
			next[j] = k;
		}
		else // ƥ��ʧ�ܣ�������ݹ����ǰ׺p[next[k]]
		{
			k = next[k];  // Ϊʲô���������أ���Ϊ����ǰ���k����֤�������ǿ���ȷ��
						  // P[0~k) = P[j-k,j) ��������ǿ��Է��ĵ���[0~k)��С��ΧȥѰ����ȵ��ַ�
		}
	}
}


int KMP(const char * s, const char *p)
{
	int i = 0; // ԭʼ��λ��
	int j = 0; // ģʽ��λ��
	int pSize = strlen(p);
	int next[255] = { 0 };
	// ����next����
	GetNext(p, next);

	while (s[i]) // ����ԭʼ��
	{
		if (j == -1 || s[i] == p[j]) // �Ա�ģʽ��
		{
			i++;
			j++; // �Ա�ģʽ����һ���ַ�
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



