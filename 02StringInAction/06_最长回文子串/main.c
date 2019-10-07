/*
	����������
	�����ַ���str�����Ӵ�s�ǻ��Ĵ�����sΪstr�Ļ����Ӵ�������㷨������str��������Ӵ�

	�㷨��Manacher


*/
#include<stdio.h>

void Manacher(char * s, int * p)
{
	int size = strlen(s);
	p[0] = 1;   // ���ַ����ĳ���Ĭ��Ϊ1
	int id = 0; // ��¼��������ĵ�
	int mx = 1; // ��¼����ĳ���
	for (int i = 1; i < size; i++) // �����ַ�
	{
		// mx > i ˵��mx�ܹ�����i�� \
		   ����������ǿ������Ż��ģ���i�Ļ��ĳ�����id��ԳƵ��Ǹ�Ԫ��p[2 * id - i]�Ļ��ĳ�������ȵ�(��mx��Χ��)
		if (mx > i)
		{
			p[i] = p[2 * id - i] < mx - i ? p[2 * id - i] : mx - i; // һ����mx-i��Χ�ڵĲŸұ�֤
		}
		else
		{
			p[i] = 1;
		}

		// ̽����һ��Ԫ���Ƿ��ܳ�Ϊ�����±߽�
		for (; s[i + p[i]] == s[i - p[i]]; p[i]++); // ������һ��Ԫ���Ƿ��ǻ��ģ��Ǿ�++

		// ��¼��ʱ��֪����Ļ���
		if (mx < i+p[i]) // ����mx��ʹ����0~i��Χ��mx������Ǹ����ĵ��±꣬��id���˻��ĵ����ĵ�
		{
			mx = i + p[i];
			id = i;
		}
	}
}



int main()
{
	// Ԥ�������ַ���
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