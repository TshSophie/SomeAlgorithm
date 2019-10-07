#include<iostream>
#include"BinaryTree.h";
using namespace std;

/**************************************************************

	二叉树的翻转：
		- 给定一棵二叉树将其左右翻转

	解决方案：
		- 对二叉树的节点，交换其左右孩子指针，递归遍历节点

***************************************************************/



int main()
{
	int pre[] = { 27, 81, 5, 47, 92, 23, 21, 45 };

	int mid[] = { 5, 47, 81, 92, 27, 21, 23, 45 };

	// 二叉树对象
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