/*
	����������
	�沨�����ʽ(Reverse Polish Notatiion)������׺���ʽ��
	ϰ���ϣ���Ԫ���������������֮��ص������������֮�䣬����׺��﷨��
	�����߼�ѧ��J.Lukasiewicz��1929�������������������������֮��ı�ʾ�������ʳ�Ϊ��׺���ʽ��
	�磺
		��׺���ʽ��a+(b-c)*d
		��׺���ʽ��abc-d*+

*/
#include<stdio.h>
#include"stack.h"

// �ж��Ƿ��������
int IsOperator(char *ch)
{	
	return ch == "+" || ch == "-" || ch == "*" || ch == "/" ? 1 : 0;
}

// ����ֵ
int calc(char* operator, int num1, int num2)
{
	if (operator=="+")
	{
		return num1 + num2;
	}
	if (operator=="-")
	{
		return num1 - num2;
	}
	if (operator=="*")
	{
		return num1 * num2;
	}
	if (operator=="/")
	{
		return num1 / num2;
	}
	return 0;
}

// �����沨�����ʽ��ֵ
int calcRPN(const char *str[],int len)
{
	Stack *stack = InitStack();
	int i = 0;
	// �������ʽ
	while (i<len)
	{				
		char * cur = str[i];
		i++;
		// �������ֵ��ջ
		if (!IsOperator(cur))
		{
			int tmp = atoi(cur);
			PushStack(stack, tmp);
		}
		else
		{
			// ��������������ջ�е�������Ԫ��
			if (GetSizeOfStack(stack)<2)
			{
				// ջԪ�ظ�������2��˵�����ʽ����
				return 0;
			}
			else
			{
				int num1 ,num2;
				num1 = TopStack(stack); PopStack(stack);
				num2 = TopStack(stack); PopStack(stack);
				int ret = calc(cur, num1, num2);
				// �ѽ����ջ
				PushStack(stack, ret);
			}
		}
	}

	return TopStack(stack);
}

int main()
{
	
	const char * str[] = {"10","20","+","3","*"};

	int ret = calcRPN(str, sizeof(str) / sizeof(str[0]));

	printf("%d\n", ret);

	system("pause");
	return 0;
}








