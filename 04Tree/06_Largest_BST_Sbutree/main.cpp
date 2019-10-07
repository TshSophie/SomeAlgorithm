#include<iostream>
#include"BinaryTree.h"
using namespace std;

/*
	����������
		����ĳ�����������������������������������ظ����������������ĸ��ڵ㡣
	�涨��
		+ ���ĳ����ӵ�и���Ľڵ㣬�����������
		+ һ������������ָ��ĳ�ڵ�Ϊ�������нڵ㡣	

	���������
		
*/

int main()
{
	int pre[] = {27,81,5,47,92,23,21,45};

	int mid[] = {5,47,81,92,27,21,23,45};

	// ����������
	BinaryTree bt;
	
	bt.Insert(bt.get(), pre, sizeof(pre) / sizeof(int), mid, sizeof(mid) / sizeof(int));
	
	bt.PreOrder(bt.get());

	cout << endl;

	bt.MidOrder(bt.get());

	cout << endl;

	int number, value;
	int ret = bt.LargestBST(bt.get(),number,value);

	cout << "number:" << number <<"  value:" << value << endl;

	system("pause");

	return 0;
}