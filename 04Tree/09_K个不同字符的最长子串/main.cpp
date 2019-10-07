#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

/********************************
	�����ַ���str������������k����ͬ�ַ�����Ӵ���
	������ַ���"eceba"��k=3�������3����ͬ�ַ�����Ӵ�Ϊ"eceb"

	���������


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