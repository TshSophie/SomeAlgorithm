/*
	问题描述：
		给定字符串，仅由"()[]{}"六个字符组成。设计算法，判断该字符串是否有效。
		括号必须以正确的顺序配对，如："()"、"()[]"是有效的，但"([)]"无效
*/

#include<stdio.h>
#include"stack.h"


// 判断是否是左边括号
int IsLeftParenthaeses(char c){
	return ( (c == '(') || (c == '[') || (c == '{') )? 1 : 0;
}
// 判断是否是右边括号
int IsRightParenthaeses(char c){
	return ((c == ')') || (c == ']') || (c == '}')) ? 1 : 0;
}


// 判断符号是否匹配
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

	// 遍历字符串
	while (*str)
	{
		char cur = *str;
		// 判断是否是左边括号
		if (IsLeftParenthaeses(cur))
		{
			// 压栈
			PushStack(stack, cur);
		}
		else if (IsRightParenthaeses(cur))// 右边括号
		{			
			// 栈顶元素
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
		// 下一个字符
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
		printf("括号匹配\n");
	}
	else
	{
		printf("括号不匹配\n");
	}

	system("pause");
	return 0;
}