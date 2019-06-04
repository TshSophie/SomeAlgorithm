#include<stdio.h>
/*
	����������
	 Ҫ���ַ���(����Ϊn)ǰ��k���ַ��ƶ����ַ���β������"abcde"��ǰ3���ַ��ƶ���β��Ϊ"deabc"

	 �ⷨ1�������ƽ⣩��
		��ѭ�����ƶ�k�Σ�ʱ�临�Ӷȣ�O(kn) �ռ临�Ӷȣ�O(1)��
	 
	 �ⷨ2��
	 �Ƚ��ַ����ָ���������֣�Ȼ�������������ַ����ֱ�ת��������������ַ������з�ת
	 ��ʱ�临�Ӷȣ�O(n) �ռ临�Ӷȣ�O(1)��
	 �磺����"abcde"��ǰ3���ַ��ƶ���β����������ô������
	 ��1���ָ��ַ�����abc|de
	 ��2���ֱ�ת�Ӵ���cba|ed
	 ��3�����巴ת: deabc

	  �����ʵ�ֽⷨ2
*/

// ��ת�ַ���
void ReverseString(char *str, int from, int to)
{
	while (from < to)
	{
		char tmp = str[from];  // ������
		str[from++] = str[to]; // ��ĩβ�ַ��ŵ���λ��
		str[to--] = tmp;	   // ���������������ַ��ŵ�ĩβȥ
	}
}

void LeftRotateString(char *str, int n, int k)
{
	k %= n;
	// ��ת��߲����ַ���
	ReverseString(str, 0, k-1);
	// ��ת�ұ߲����ַ���
	ReverseString(str, k, n-1);
	// ����
	ReverseString(str, 0, n-1);
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
	char str[] = "ABCDEFG";

	LeftRotateString(str, strlen(str), 3);

	printf("%s\n", str);

	system("pause");
	return 0;
}

