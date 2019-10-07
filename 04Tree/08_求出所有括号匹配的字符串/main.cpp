#include<iostream>
#include<vector>
#include<string>
using namespace std;

/***************************************************
	N�������ܹ��õ�����Ч������������Щ?
	��N=3ʱ����Ч���Ŵ���5�����ֱ�Ϊ��
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
		prefix = AllParentheses(i); // i�����ŵĿ�������A
		suffix = AllParentheses(n - i - 1); // N-i-1�����ŵĿ�������B
		Unit(result, prefix, suffix); // ��װA(B)
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