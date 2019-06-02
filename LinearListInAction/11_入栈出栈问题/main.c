/*
	问题描述：
	给定无重复元素的连个等长数组，分别表达入栈序列和出栈序列，请问：这样的出栈序列是否可行。
	如:出栈序列为“ABCDEFG"，出栈序列为"BAEDFGC",则可行
	入栈序列"ABCD",出栈序列"BDAC",不可行
		

	【1】遍历出栈序列，将当前字符与栈顶元素进行比较，相等则弹出栈顶元素
	【2】不相等就遍历入栈序列，将与当前字符相等的那个字符前面的字符都入栈，并将入栈序列指针指向下一个字符；
		 如果遍历完了还找不到相等的字符，那么说明不匹配
	【3】重复上述操作，如果能顺利遍历完，则说明匹配

*/
#include<stdio.h>
#include"stack.h"
int checkSquence(char *strIn, char *strOut)
{
	Stack *stack = InitStack();
	// 遍历出栈序列
	while (*strOut)
	{
		char cur = *strOut;
		strOut++;
		// 判断栈顶元素否与该字符相同
		char top = TopStack(stack);
		if (GetSizeOfStack(stack) && (cur == top))
		{
			// 从栈顶弹出一个元素
			PopStack(stack);
		}
		else
		{
			// 从出栈序列中找到该字符，将其前面的所有字符入栈
			while (*strIn && (*strIn) != cur)
			{
				char tmp = *strIn;
				PushStack(stack, tmp);
				strIn++;
			}
			if (*strIn=='\0') // 字符串遍历完了还没找到,不匹配
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













