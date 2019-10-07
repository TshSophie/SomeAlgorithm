/*
	����������
	�������ظ�Ԫ�ص������ȳ����飬�ֱ�����ջ���кͳ�ջ���У����ʣ������ĳ�ջ�����Ƿ���С�
	��:��ջ����Ϊ��ABCDEFG"����ջ����Ϊ"BAEDFGC",�����
	��ջ����"ABCD",��ջ����"BDAC",������
		

	��1��������ջ���У�����ǰ�ַ���ջ��Ԫ�ؽ��бȽϣ�����򵯳�ջ��Ԫ��
	��2������Ⱦͱ�����ջ���У����뵱ǰ�ַ���ȵ��Ǹ��ַ�ǰ����ַ�����ջ��������ջ����ָ��ָ����һ���ַ���
		 ����������˻��Ҳ�����ȵ��ַ�����ô˵����ƥ��
	��3���ظ����������������˳�������꣬��˵��ƥ��

*/
#include<stdio.h>
#include"stack.h"
int checkSquence(char *strIn, char *strOut)
{
	Stack *stack = InitStack();
	// ������ջ����
	while (*strOut)
	{
		char cur = *strOut;
		strOut++;
		// �ж�ջ��Ԫ�ط�����ַ���ͬ
		char top = TopStack(stack);
		if (GetSizeOfStack(stack) && (cur == top))
		{
			// ��ջ������һ��Ԫ��
			PopStack(stack);
		}
		else
		{
			// �ӳ�ջ�������ҵ����ַ�������ǰ��������ַ���ջ
			while (*strIn && (*strIn) != cur)
			{
				char tmp = *strIn;
				PushStack(stack, tmp);
				strIn++;
			}
			if (*strIn=='\0') // �ַ����������˻�û�ҵ�,��ƥ��
			{
				return 0;
			}
		    strIn++;
		}
	}

	return 1;
}

int main()
{

	char *strIn = "ABCD";// "ABCDEFG";
	char *strOut = "BDAC";// "BAEDFGC";

	int ret = checkSquence(strIn, strOut);

	printf("%d\n", ret);

	system("pause");
	return 0;
}













