#include<stdio.h>
/*
  ����������
  Ҫ���ַ���ǰ��n���ַ��ƶ����ַ���β������"abcde"��ǰ3���ַ��ƶ���β��Ϊ"deabc"

*/

#if 0

// �ⷨ1������λ��

// ���ַ�һ��һ���ƶ�
void LeftShiptOne(char *str, int n) // �ռ临�Ӷȣ�1 ʱ�临�Ӷȣ�n
{
	// �����һ���ַ�
	char tmp = str[0]; 

	for (int i = 1; i < n; i++)
	{
		// ����
		str[i - 1] = str[i];
	}

	str[n - 1] = tmp;
}

// �ƶ�ͷm���ַ���ĩβ
void LeftRotateString(char *s, int n, int m)// �ռ临�Ӷȣ�1 ʱ�临�Ӷȣ�n*m
{
	while (m--)
	{
		LeftShiptOne(s, n);
	}
}
 
int main()
{

	char str[] = "abcdefg";

	printf("strlen(str) = %d\n", strlen(str));

	LeftRotateString(str,strlen(str),3);

	printf("str = %s\n", str);

	printf("strlen(str) = %d\n", strlen(str));

	return 0;
}

#endif


#if 0
// �ⷨ2��������ת
// �Ƚ��ַ����ָ���������֣�Ȼ�������������ַ����ֱ�ת��������������ַ������з�ת

// ��ת�ַ���
void ReverseString(char *str, int from, int to)
{
	// 1 2 3 4     4 2 3 1   4 3 2 1

	while (from < to)
	{
		char tmp = str[from];  // ������
		str[from++] = str[to]; // ��ĩβ�ַ��ŵ���λ��
		str[to--] = tmp;	   // ���������������ַ��ŵ�ĩβȥ
	}
}

/*
@param str �������ַ���
@param n �������ַ�������
@param m Ҫ������λ��
*/
void LeftRotateString(char *str, int n, int m) // ʱ�临�Ӷȣ�n �ռ临�Ӷȣ�1
{
	// �����ƶ�����nλ������%n�ǵȼ۵�(��������)
	m %= n;
	ReverseString(str, 0, m - 1);
	ReverseString(str, m, n - 1);
	ReverseString(str, 0, n - 1);
}

int main()
{
	char str[] = "abcdefg";

	printf(" 3 �� 7 = %d\n", 3 % 7);
	printf(" 11 �� 7 = %d\n", 11 % 7);


	printf("strlen(str) = %d\n", strlen(str));

	LeftRotateString(str, strlen(str), 3);

	printf("str = %s\n", str);

	printf("strlen(str) = %d\n", strlen(str));

	return 0;
}

#endif


#if 1
// ��չ��ϰ
// ��תӢ�ľ��ӵĵ���(�������ͨ�ַ�һ������)
// �磺i am a student. ===>  student. a am i
// �ҵ�˼·��
// ��ÿ�����ʵ��ַ���ת i ma a .tneduts
// ���������巴ת student. a am i

// ��ת�ַ���
void ReverseString(char *str, int from, int to)
{
	// 1 2 3 4     4 2 3 1   4 3 2 1
	while (from < to)
	{
		char tmp = str[from];  // ������
		str[from++] = str[to]; // ��ĩβ�ַ��ŵ���λ��
		str[to--] = tmp;	   // ���������������ַ��ŵ�ĩβȥ
	}
}

// ��ת����
void ReverseWord(char *str, int n) // ʱ�临�Ӷȣ�n �ռ临�Ӷȣ�1
{

	int i = 0; // ������
	int l = n;
	int start = 0;
	int space = 0;
	// ��ÿ�����ʵ��ַ���ת i am a student. ===>  i ma a .tneduts
	while (l--)
	{			
		if (str[i] == ' ')
		{
			ReverseString(str, start, space - 1);
			start = space + 1;
		}
		i++;
		space++;
	}		

	// �������һ�����ʵķ�ת
	ReverseString(str, start, n - 1);

	// ���巴ת
	ReverseString(str, 0, n - 1);
}

int main()
{
	char str[] = "i am a student.";
	
	printf("str = %s\n", str);

	ReverseWord(str, strlen(str), 3);

	printf("str = %s\n", str);

	return 0;
}

#endif