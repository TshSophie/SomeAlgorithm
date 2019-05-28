#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
/*
 问题：
 给定一长字符串a和一短字符串b。如何最快地判断出最短字符串b中所有的字符是否都在长字符串a中？
 如：字符串a：ABCD,字符串b：BAD，答案是true
 如：字符串a：ABCD,字符串b：BDE，答案是false
 如：字符串a：ABCD,字符串b：AA，答案是true
 请编写函数bool StringContain(string &a,string &b)

*/

#if 0
// 解法一：蛮力轮询 \
	轮询短字符串b中的每一个字符，逐个与长字符串a中的每个字符进行比较，看是否都在字符串a中
int StringContain(char *strA, int lenA,char *strB,int lenB)  // 空间复杂度：1 时间复杂度：mn
{
	int i = 0;
	int j = 0;
	for (i = 0; i < lenB; i++)
	{
		for (j = 0; j < lenA; j++)
		{
			if (strB[i] == strA[j])
			{
				break;
			}
		}
		if (j >= lenA)
		{
			return 0;
		}
	}

	return 1;
}

int main()
{

	char strA[] = "ABCD";
	char strB[] = "AA";

	int a = StringContain(strA, strlen(strA), strB, strlen(strB));

	printf("a = %d\n", a);

	return 0;
}


#endif


#if 0

// 解法2：排序后轮询\
   先对这两个字符串中的字母进行排序，然后在对两个字符串依次轮询\
   常规情况下，两个字符串的排序需要mlogm + nlogn次排序，之后的线性扫描需要m+n次操作

bool StringContain(string &a, string &b)// 空间复杂度：1 时间复杂度：mn
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int j = 0;
	for (int i = 0; i < b.length(); i++)
	{
		for (j = 0; j < a.length(); j++)
		{
			if (b[i] == a[j])
			{
				break;
			}
		}
		if (j >= a.length())
		{
			return false;
		}
	}

	return true;
}

int main()
{
	string strA = "ABCD";
	string strB = "AR";

	bool a = StringContain(strA,  strB);

	printf("a = %d\n", a);

	return 0;
}

#endif

#if 0
// 解法三：素数相乘\
   1 按照从小到大的顺序，用26个素数分别代替长字符串a中的所有字母。\
   2 遍历长字符串a，求得a中的所有字母对应的素数的乘积\
   3 遍历短字符串b，判断上一步得到的乘积能否被b中的字母对应的素数整除\
   4 输出结果

bool StringContain(string &a, string &b)// 空间复杂度：1 时间复杂度：m+n
{

	const int p[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 31, 37, 41, 43, 47, 
						53, 59, 61, 71, 73, 79, 83, 89, 97, 101 };
	int f = 1;
	for (int i = 0; i < a.length(); i++)
	{
		int x = p[a[i] - 'A'];
		if (f % x)  // 排除重复的数
		{
			f *= x;
		}
	}
	for (int i = 0; i < b.length(); ++i)
	{
		int x = p[b[i] - 'A'];
		if (f % x) // 判断能否被整除
		{
			return false;
		}
	}
	return true;
}


int main()
{
	string strA = "ABACD";
	string strB = "AA";

	bool a = StringContain(strA, strB);

	printf("a = %d\n", a);

	return 0;
}

#endif

#if 0

// 位运算法
// 用位运算(26位整数表示)为长字符串a计算出一个“签名”，再逐一将短字符串b中的字符放到a中进行查找

bool StringContain(string &a, string &b) // 空间复杂度：1 时间复杂度：m+n
{
	int hash = 0;
	for (int i = 0; i < a.length(); ++i)
	{
		hash |= (1 << (a[i] - 'A'));  // 3 = 0010  --》 0100 | 0000 = 0100  ， \
											通过按位取或运算，记录字符并且可以过滤掉相同的字符，只保留一份
	}

	for (int i = 0; i < b.length(); ++i)
	{
		if ((hash & (1 << (b[i] - 'A'))) == 0) // 通过与运算来检验b中字符是否在a中
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string strA = "ABACD";
	string strB = "AA";

	bool a = StringContain(strA, strB);

	printf("a = %d\n", a);

	return 0;
}


#endif


#if 1
/*
 拓展题：
	 如果两个字符串中的字符一样，出现次数也一样，只是出现顺序不一样，
	 则认为这两个字符串是兄弟字符串，例如“bad”和“adb”即为兄弟字符串，
	 现在提供一个字符串，请问如何在字典中迅速找到它的兄弟字符串

*/

bool checkString(string &str1, string &str2)
{
	// 首先判断长度是否相等
	if (str1.length() != str2.length())
	{
		return false;
	}

	int hash1 = 0;
	for (int i = 0; i < str1.length(); ++i)
	{
		hash1 |= (1 << (str1[i] - 'A'));  
	}

	int hash2 = 0;
	for (int i = 0; i < str2.length(); ++i)
	{
		hash2 |= (1 << (str2[i] - 'A'));
	}

	return hash1 == hash2;
}


int main()
{
	string str1 = "aabc";
	string str2 = "abc";

	bool a = checkString(str1, str2);

	printf("a = %d\n", a);

}

#endif 