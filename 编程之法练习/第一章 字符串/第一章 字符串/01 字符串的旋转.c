#include<stdio.h>
/*
  问题描述：
  要求将字符串前面n个字符移动到字符串尾部，如"abcde"的前3个字符移动到尾部为"deabc"

*/

#if 0

// 解法1：蛮力位移

// 将字符一个一个移动
void LeftShiptOne(char *str, int n) // 空间复杂度：1 时间复杂度：n
{
	// 保存第一个字符
	char tmp = str[0]; 

	for (int i = 1; i < n; i++)
	{
		// 左移
		str[i - 1] = str[i];
	}

	str[n - 1] = tmp;
}

// 移动头m个字符到末尾
void LeftRotateString(char *s, int n, int m)// 空间复杂度：1 时间复杂度：n*m
{
	while (m--)
	{
		LeftShiptOne(s, n);
	}
}
 
int main()
{

	char str[] = "abcdefg";

	printf("strlen(str) = %d\n", strlen(str));

	LeftRotateString(str,strlen(str),3);

	printf("str = %s\n", str);

	printf("strlen(str) = %d\n", strlen(str));

	return 0;
}

#endif


#if 0
// 解法2：三步反转
// 先将字符串分割成两个部分，然后将这两个部分字符串分别反转，最后再最整个字符串进行反转

// 反转字符串
void ReverseString(char *str, int from, int to)
{
	// 1 2 3 4     4 2 3 1   4 3 2 1

	while (from < to)
	{
		char tmp = str[from];  // 缓存首
		str[from++] = str[to]; // 将末尾字符放到首位来
		str[to--] = tmp;	   // 将缓存起来的首字符放到末尾去
	}
}

/*
@param str 待处理字符串
@param n 待处理字符串长度
@param m 要交换的位数
*/
void LeftRotateString(char *str, int n, int m) // 时间复杂度：n 空间复杂度：1
{
	// 若左移动大于n位，则与%n是等价的(保护处理)
	m %= n;
	ReverseString(str, 0, m - 1);
	ReverseString(str, m, n - 1);
	ReverseString(str, 0, n - 1);
}

int main()
{
	char str[] = "abcdefg";

	printf(" 3 余 7 = %d\n", 3 % 7);
	printf(" 11 余 7 = %d\n", 11 % 7);


	printf("strlen(str) = %d\n", strlen(str));

	LeftRotateString(str, strlen(str), 3);

	printf("str = %s\n", str);

	printf("strlen(str) = %d\n", strlen(str));

	return 0;
}

#endif


#if 1
// 拓展练习
// 反转英文句子的单词(标点与普通字符一样处理)
// 如：i am a student. ===>  student. a am i
// 我的思路：
// 将每个单词的字符反转 i ma a .tneduts
// 将句子整体反转 student. a am i

// 反转字符串
void ReverseString(char *str, int from, int to)
{
	// 1 2 3 4     4 2 3 1   4 3 2 1
	while (from < to)
	{
		char tmp = str[from];  // 缓存首
		str[from++] = str[to]; // 将末尾字符放到首位来
		str[to--] = tmp;	   // 将缓存起来的首字符放到末尾去
	}
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
	char str[] = "i am a student.";
	
	printf("str = %s\n", str);

	ReverseWord(str, strlen(str), 3);

	printf("str = %s\n", str);

	return 0;
}

#endif