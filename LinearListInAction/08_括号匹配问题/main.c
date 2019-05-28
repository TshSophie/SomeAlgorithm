/*
	����������
		�����ַ���������"()[]{}"�����ַ���ɡ�����㷨���жϸ��ַ����Ƿ���Ч��
		���ű�������ȷ��˳����ԣ��磺"()"��"()[]"����Ч�ģ���"([)]"��Ч
*/

#include<stdio.h>
#include"stack.h"


// �ж��Ƿ����������
int IsLeftParenthaeses(char c){
	return ( (c == '(') || (c == '[') || (c == '{') )? 1 : 0;
}
// �ж��Ƿ����ұ�����
int IsRightParenthaeses(char c){
	return ((c == ')') || (c == ']') || (c == '}')) ? 1 : 0;
}


// �жϷ����Ƿ�ƥ��
int IsMatch(char left, char c){
	if (left == '('&&c == ')')
	{
		return 1;
	}
	if (left == '['&&c == ']')
	{
		return  1;
	}
	if (left == '{'&&c == '}')
	{
		return  1;
	}
	return 0;
}


int MatchParenthaeses(char *str){
	Stack *stack = InitStack();

	// �����ַ���
	while (*str)
	{
		char cur = *str;
		// �ж��Ƿ����������
		if (IsLeftParenthaeses(cur))
		{
			// ѹջ
			PushStack(stack, cur);
		}
		else if (IsRightParenthaeses(cur))// �ұ�����
		{			
			// ջ��Ԫ��
			char top = TopStack(stack);
			if (!IsEmptyStack(stack)&&IsMatch(top, cur))
			{
				PopStack(stack);
			}
			else
			{
				return 0;
			}
		}
		// ��һ���ַ�
		str++;
	}

	int ret = IsEmptyStack(stack);
	DestroyStack(stack);
	return ret;	
}


void test(){

	Stack *stack = InitStack();

	PushStack(stack, 1);
	PushStack(stack, 2);
	PushStack(stack, 3);
	PushStack(stack, 4);

	while (!IsEmptyStack(stack))
	{
		int data = TopStack(stack);
		PopStack(stack);
		printf("%d ", data);
	}

	DestroyStack(stack);
	
}

int main(){

	char *str = "fda(fdaf){fdas}";
	if (MatchParenthaeses(str))
	{
		printf("����ƥ��\n");
	}
	else
	{
		printf("���Ų�ƥ��\n");
	}

	system("pause");
	return 0;
}