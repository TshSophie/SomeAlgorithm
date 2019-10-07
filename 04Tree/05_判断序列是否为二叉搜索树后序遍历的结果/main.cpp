#include<iostream>
using namespace std;

/*
	问题描述:
	给定一个整数数组，判断该数组有无可能是一棵二叉搜索树后续遍历的结果，假定数组中没有重复元素。

	解决方案：
	由题述二叉树为搜索二叉树那么可知道该树左子树一定是小于根节点，而右子树一定是大于根节点的。
	我们可以这样来进行判断：
	假定给的后序数组是正确的那么就有，最后一个元素一定是根节点，拿着这个根节点去将序列分成左右两半，
	使得左半段的节点都小于根节点且右半段的节点都大于根节点，如果存在这样的划分，那么该后序序列存在，否则不存在这样的后序序列。
*/

bool CheckBackOrder(const int *list,int size){
	if (size <= 1)
	{
		return true;
	}
	int root = list[size - 1]; // 后序序列最后一个元素一定为根节点
	int nLeft = 0;
	while (nLeft < size-1) 
	{
		if (list[nLeft] > root)
		{
			break;
		}
		nLeft++;
	}

	int nRight = size - 2;
	while(nRight >= 0)
	{
		if (list[nRight] < root)
		{
			break;
		}
		nRight--;
	}

	// 如果上述划分符合二叉搜索树那么，他们的指针最后会只相差一个单位
	if (nRight != nLeft-1)
	{
		return false;
	}

	// 左子树，右子树
	return CheckBackOrder(list, nLeft) && CheckBackOrder(list + nLeft, size - nLeft - 1);
}

int main()
{

	int list[] = { 1, 2, 5, 4, 3 };
	bool b = CheckBackOrder(list, sizeof(list) / sizeof(int));
	cout <<( b? "是正确的后续遍历结果" : "不是正确的后续遍历结果") << endl;
	system("pause");
	return 0;
}