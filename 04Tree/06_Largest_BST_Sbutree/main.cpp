#include<iostream>
#include"BinaryTree.h"
using namespace std;

/*
	问题描述：
		给定某二叉树，计算它的最大二叉搜索子树。返回该最大二叉搜索子树的根节点。
	规定：
		+ 如果某子树拥有更多的节点，则该子树更大。
		+ 一棵树的子树，指以某节点为根的所有节点。	

	解决方案：
		
*/

int main()
{
	int pre[] = {27,81,5,47,92,23,21,45};

	int mid[] = {5,47,81,92,27,21,23,45};

	// 二叉树对象
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