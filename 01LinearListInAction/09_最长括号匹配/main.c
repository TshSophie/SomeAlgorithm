/*
	����������
	 �����ַ�����������������'('��������')'�������ܲ�������ƥ��ģ�����㷨�ҳ��ƥ��������Ӵ�
	 ���ظ��Ӵ��ĳ��ȡ�
	 ��һ�����Ŵ���������Ӵ��ĳ��ȣ��� �� ) ( ( ) ( ) ������Ӵ�Ϊ�� ( ) ( ) ������Ϊ4��
	 �磺
	    ()):2
		()(): 4
		()(()):6
		(()()):6
*/

#include<stdio.h>
#include<string.h>
#include"stack.h"

int max(int a,int b)
{
	return a > b ? a : b;
}

int LongParenthaesesMatch(char *str){

	int size = strlen(str);
	Stack *stack = InitStack();
	int leng = 0; // �ƥ���ַ�����
	int start = -1; // �����ŵ�ǰһ��λ��
	for (int i = 0; i < size; i++)
	{
		if (str[i] == '('){
			PushStack(stack, i);
		}
		else
		{
			if (IsEmptyStack(stack)) // ���ջΪ�գ���ʾû��ƥ��������ţ��޸���ʼλ�ã�������Ϊ��һ��ƥ����׼��
			{
				start = i;
			}
			else // ջ��Ϊ��
			{
				PopStack(stack); // ��ջ
				if (IsEmptyStack(stack)) // �ٴ��ж�ջ�Ƿ�Ϊ��
				{
					leng = max(leng, i - start); // Ϊ��, i - startΪ��ǰ�ҵ���ƥ�䳤�ȣ���鲢����leng
				}
				else
				{					
					int top = TopStack(stack); // ���գ���ǰջ��Ԫ�����ϴ�ƥ������λ�ã���鲢����leng
					leng = max(leng, i - top);
				}
			}
		}
	}

	return leng;

}


int main(){

	/*
		()):2
		()(): 4
		()(()):6
		(()()):6
		))()()��4
	*/
	char *str = "()((())";
	
	printf("�����ƥ�䣺%d\n", LongParenthaesesMatch(str));
	

	system("pause");
	return 0;
}
