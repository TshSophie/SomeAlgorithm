#include<iostream>
#include"BinaryTree.h"

using namespace std;


// 搜索二叉树的插入、查找和删除节点
void test1()
{
	// 二叉树对象
	BinaryTree bt;

	// 生成二叉树
	bt._Insert(bt.get(), 15);
	bt._Insert(bt.get(), 5);
	bt._Insert(bt.get(), 3);
	bt._Insert(bt.get(), 12);
	bt._Insert(bt.get(), 16);
	bt._Insert(bt.get(), 20);
	bt._Insert(bt.get(), 23);
	bt._Insert(bt.get(), 13);
	bt._Insert(bt.get(), 18);
	bt._Insert(bt.get(), 10);
	bt._Insert(bt.get(), 6);
	bt._Insert(bt.get(), 7);

	// 查找二叉树
	STreeNode *tNode = bt.Find(12);

	if (tNode != NULL)
	{
		cout << "Find:" << tNode->value << endl;
	}
	else
	{
		cout << "Not found!" << endl;
	}

	// 删除节点
	bt.Delete(12);
	// 查找二叉树
	tNode = bt.Find(12);

	if (tNode != NULL)
	{
		cout << "Find:" << tNode->value << endl;
	}
	else
	{
		cout << "Not found!" << endl;
	}
}

// 二叉树的先序遍历
void test2()
{
	// 二叉树对象
	BinaryTree bt;

	// 生成二叉树
	bt._Insert(bt.get(), 15);
	bt._Insert(bt.get(), 5);
	bt._Insert(bt.get(), 3);
	bt._Insert(bt.get(), 12);
	bt._Insert(bt.get(), 16);
	bt._Insert(bt.get(), 20);
	bt._Insert(bt.get(), 23);
	bt._Insert(bt.get(), 13);
	bt._Insert(bt.get(), 18);
	bt._Insert(bt.get(), 10);
	bt._Insert(bt.get(), 6);
	bt._Insert(bt.get(), 7);

	// 先序遍历 递归
	bt.PreOrder(bt.get());
	cout << endl;
	// 先序遍历 非递归
	bt.PreOrder2();
	cout << endl;

	// 中序遍历 递归
	bt.MidOrder(bt.get());
	cout << endl;
	// 中序遍历非 递归
	bt.MidOrder2();
	cout << endl;
	// 中序遍历非 递归
	bt.MidOrder3();
	cout << endl;

	// 后序遍历 递归
	bt.BackOrder(bt.get());
	cout << endl;
	// 后序遍历 非递归
	bt.BackOrder2();
	cout << endl;	
}

int main(){

	test2();

	system("pause");
	return 0;
}