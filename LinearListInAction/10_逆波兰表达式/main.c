/*
	问题描述：
	逆波兰表达式(Reverse Polish Notatiion)，即后缀表达式。
	习惯上，二元运算符总是置于与之相关的两个运算对象之间，即中缀表达法。
	波兰逻辑学家J.Lukasiewicz于1929年提出了运算符都置于运算对象之后的表示方法，故称为后缀表达式。
	如：
		中缀表达式：a+(b-c)*d
		后缀表达式：abc-d*+

*/
#include<stdio.h>
#include"stack.h"

// 判断是否是运算符
int IsOperator(char *ch)
{	
	return ch == "+" || ch == "-" || ch == "*" || ch == "/" ? 1 : 0;
}

// 计算值
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

// 计算逆波兰表达式的值
int calcRPN(const char *str[],int len)
{
	Stack *stack = InitStack();
	int i = 0;
	// 遍历表达式
	while (i<len)
	{				
		char * cur = str[i];
		i++;
		// 如果是数值入栈
		if (!IsOperator(cur))
		{
			int tmp = atoi(cur);
			PushStack(stack, tmp);
		}
		else
		{
			// 如果是运算符，从栈中弹出两个元素
			if (GetSizeOfStack(stack)<2)
			{
				// 栈元素个数少于2个说明表达式错误
				return 0;
			}
			else
			{
				int num1 ,num2;
				num1 = TopStack(stack); PopStack(stack);
				num2 = TopStack(stack); PopStack(stack);
				int ret = calc(cur, num1, num2);
				// 把结果入栈
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








