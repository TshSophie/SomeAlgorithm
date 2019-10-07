#include<iostream>
#include"BinaryTree.h";
using namespace std;

/**************************************************************

	�������ķ�ת��
		- ����һ�ö������������ҷ�ת

	���������
		- �Զ������Ľڵ㣬���������Һ���ָ�룬�ݹ�����ڵ�

***************************************************************/



int main()
{
	int pre[] = { 27, 81, 5, 47, 92, 23, 21, 45 };

	int mid[] = { 5, 47, 81, 92, 27, 21, 23, 45 };

	// ����������
	BinaryTree bt;

	bt.Insert(bt.get(), pre, sizeof(pre) / sizeof(int), mid, sizeof(mid) / sizeof(int));

	bt.PreOrder(bt.get());

	cout << endl;

	bt.MidOrder(bt.get());

	cout << endl;

	bt.Reverse(bt.get());

	bt.PreOrder(bt.get());

	cout << endl;

	bt.MidOrder(bt.get());

	cout << endl;

	system("pause");
	return 0;

}