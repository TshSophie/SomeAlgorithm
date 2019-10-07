#include<iostream>
#include<vector>
#include<string>
using namespace std;

/***************************************************
	N对括号能够得到的有效括号序列有哪些?
	如N=3时，有效括号串共5个，分别为：
	1:()()() 2:()(()) 3:(())() 4:(()()) 5:((()))

***************************************************/

void Unit(vector<string>& result,
	const vector<string>& prefix, const vector<string>& suffix){
	vector<string>::const_iterator ip, is;
	for (ip = prefix.begin(); ip != prefix.end(); ip++)
	{
		for (is = suffix.begin(); is != suffix.end(); is++)
		{
			result.push_back("");
			string& r = result.back();
			r += "(";
			r += *ip;
			r += ")";
			r += *is;
		}
	}
}

vector<string> AllParentheses(int n)
{
	if (n == 0)
	{
		return vector<string>(1, "");		
	}
	if (n == 1)
	{
		return vector<string>(1, "()");		
	}
	vector<string> prefix, suffix, result;
	for (int i = 0; i < n; i++)
	{
		prefix = AllParentheses(i); // i对括号的可行序列A
		suffix = AllParentheses(n - i - 1); // N-i-1对括号的可行序列B
		Unit(result, prefix, suffix); // 组装A(B)
	}
	return result;
}

int main()
{
	vector<string> ret = AllParentheses(3);
	int i = 0;
	for (vector<string>::iterator ip = ret.begin(); ip != ret.end(); ip++)
	{
		cout << i + 1 <<" : "<< ret[i] << endl;
		i++;
	}

	system("pause");
	return 0;
}