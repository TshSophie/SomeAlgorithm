/*
	����������
		����һ������Ϊn���ַ���S���������һ���ַ���T���ظ����ɴ�T�ܹ��õ�S����ôS�������ڴ���T����S��һ�����ڡ�
	�磺
		�ַ���abababab�����ڴ���abab��ab�����������ڣ�����ab��������С���ڡ�
		���һ���㷨����S����С���ڡ���� S���������ڷ��ؿմ���

	���������
		���ȼ����S��next���飬
		- ��k=next[len]��p=len-k
		- ��len%p = 0,��pΪ��С���ڳ��ȣ�ǰp���ַ�������С���ڡ�

*/

#include<stdio.h>

int MinPeriod(char *p)
{
	int len = strlen(p); // ������
	int *next = malloc(sizeof(int)*len); // ��next���鶯̬����ռ�
	next[0] = -1; // ��һ���ַ�kǰ׺Ĭ��Ϊ-1
	// ��ʼ����next����
	int j = 0; // �ַ�λ��	
	int k = -1; // ��¼��ǰ�ַ�kǰ׺
	while (j < len-1)
	{		
		if (k == -1 || p[k] == p[j])
		{
			j++; // p[j+1]�ַ�
			k++; // �ϸ��ַ���kǰ׺ +1
			next[j] = k; // �����p[j+1]��kǰ׺
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

	// ��������
	next[0] = 0;
	int end = len - 1;
	int period = end - next[end];
	
	// �ͷ�next����ռ�
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

