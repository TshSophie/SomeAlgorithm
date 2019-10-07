#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

/********************************
	给定字符串str，计算最多包括k个不同字符的最长子串。
	如给定字符串"eceba"和k=3，则包括3个不同字符的最长子串为"eceb"

	解决方案：


******************************/

int LongestSubstring(const char *str, int size, int k)
{
	if (size <= 0)
	{
		return 0;
	}
	map<char, int> wd;
	int left = 0;
	int mx = 0;
	for (int right = 0; right < size; right++)
	{
		wd[str[right]]++;
		while ((int)wd.size() > k)
		{
			wd[str[left]]--;
			if (wd[str[left]] == 0)
			{
				wd.erase(str[left]);
			}
			left++;
		}
		mx = max(right - left + 1, mx);
	}
	return mx;
}


int main()
{
	char s[] = "eceba";
	cout << LongestSubstring(s, sizeof(s) / sizeof(char)-1, 3) << endl;

	system("pause");
	return 0;
}