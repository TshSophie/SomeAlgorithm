#include<stdio.h>
/*
	问题描述：
	 要求将字符串(长度为n)前面k个字符移动到字符串尾部，如"abcde"的前3个字符移动到尾部为"deabc"

	 解法1（暴力破解）：
		即循环左移动k次（时间复杂度：O(kn) 空间复杂度：O(1)）
	 
	 解法2：
	 先将字符串分割成两个部分，然后将这两个部分字符串分别反转，最后再最整个字符串进行反转
	 （时间复杂度：O(n) 空间复杂度：O(1)）
	 如：对于"abcde"的前3个字符移动到尾部，可以这么来做：
	 【1】分割字符串：abc|de
	 【2】分别反转子串：cba|ed
	 【3】整体反转: deabc

	  这里仅实现解法2
*/

// 反转字符串
void ReverseString(char *str, int from, int to)
{
	while (from < to)
	{
		char tmp = str[from];  // 缓存首
		str[from++] = str[to]; // 将末尾字符放到首位来
		str[to--] = tmp;	   // 将缓存起来的首字符放到末尾去
	}
}

void LeftRotateString(char *str, int n, int k)
{
	k %= n;
	// 反转左边部分字符串
	ReverseString(str, 0, k-1);
	// 反转右边部分字符串
	ReverseString(str, k, n-1);
	// 整体
	ReverseString(str, 0, n-1);
}



// 反转单词
void ReverseWord(char *str, int n) // 时间复杂度：n 空间复杂度：1
{

	int i = 0; // 迭代器
	int l = n;
	int start = 0;
	int space = 0;
	// 将每个单词的字符反转 i am a student. ===>  i ma a .tneduts
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

	// 处理最后一个单词的反转
	ReverseString(str, start, n - 1);

	// 整体反转
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

