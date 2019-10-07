/*
	问题描述：
	 给定字符串，仅包括左括号'('和右括号')'，它可能不是括号匹配的，设计算法找出最长匹配的括号子串
	 返回该子串的长度。
	 求一个括号串的最长括号子串的长度，如 “ ) ( ( ) ( ) ”的最长子串为“ ( ) ( ) ”长度为4。
	 如：
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
	int leng = 0; // 最长匹配字符长度
	int start = -1; // 左括号的前一个位置
	for (int i = 0; i < size; i++)
	{
		if (str[i] == '('){
			PushStack(stack, i);
		}
		else
		{
			if (IsEmptyStack(stack)) // 如果栈为空，表示没有匹配的左括号，修改起始位置，跳过，为下一次匹配做准备
			{
				start = i;
			}
			else // 栈不为空
			{
				PopStack(stack); // 出栈
				if (IsEmptyStack(stack)) // 再次判断栈是否为空
				{
					leng = max(leng, i - start); // 为空, i - start为当前找到的匹配长度，检查并更新leng
				}
				else
				{					
					int top = TopStack(stack); // 不空，当前栈顶元素是上次匹配的最后位置，检查并更新leng
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
		))()()：4
	*/
	char *str = "()((())";
	
	printf("最长括号匹配：%d\n", LongParenthaesesMatch(str));
	

	system("pause");
	return 0;
}
