#include<iostream>
using namespace std;

typedef struct STreeNode{
	int value;
	STreeNode * pLeft;
	STreeNode * pRight;
	STreeNode(int v) :value(v), pLeft(NULL), pRight(NULL){}
}STreeNode;


class BinaryTree
{
public:
	
	STreeNode *&get(){
		return this->m_pRoot;
	}

	// 根据前序中序构造二叉树
	void Insert(STreeNode *& root, const int*preOrder, int len1,
		const int *midOrder, int len2);

	bool _LargestBST(STreeNode *root, int & nMin, int &nMax,
		int &count, int & nNumber, STreeNode *& pNode)const;

	int LargestBST(STreeNode *& pNode, int &nNumber, int &value)const;

	void PreOrder(STreeNode *root)const; // 二叉树先序遍历(递归)
	void MidOrder(STreeNode *root)const; // 二叉树中序遍历(递归)

private:
	STreeNode * m_pRoot;
};

void  BinaryTree::PreOrder(STreeNode *root)const{
	if (root)
	{
		cout << root->value << "->"; // 根
		PreOrder(root->pLeft); // 遍历左子树
		PreOrder(root->pRight); // 遍历右子树
	}
}

// 二叉树中序遍历(递归)
void BinaryTree::MidOrder(STreeNode *root)const{
	if (root)
	{
		MidOrder(root->pLeft);
		cout << root->value << "->";
		MidOrder(root->pRight);
	}
}

/*
	root: 根，输出参数
	preOrder：前序序列
	len1：前序序列长度
	midOrder：中序序列
	len2：中序序列长度
*/
void BinaryTree::Insert(STreeNode *& root, const int* preOrder, int len1,
	const int *midOrder, int len2)
{
	if (len2 <= 0)
	{
		return;
	}	

	// 从前序找根节点
	int cRoot = preOrder[0];
	root = new STreeNode(cRoot);		
	if (len2 == 1)
	{
		return;
	}

	// 去中序找根
	int i;
	for (i = 0; i < len2; i++)
	{
		if (cRoot == midOrder[i]){
			break;
		}
	}

	// 左边遍历
	Insert(root->pLeft, preOrder + 1, len1 - 1, midOrder, i);

	// 右边遍历  
	Insert(root->pRight, preOrder + i + 1, len2 - i - 1 , midOrder + i + 1, len2 - i - 1);

}


// 最大搜索子树
int BinaryTree::LargestBST(STreeNode *& pNode,int &nNumber,int &value)const{

	int nMin, nMax, count;
	nNumber = 0;
	
	_LargestBST(m_pRoot, nMin, nMax, count, nNumber, pNode);
	// return nNumber;
	value = pNode->value;
	return pNode->value;

}

bool BinaryTree::_LargestBST(STreeNode *root, int &nMin, int &nMax,
	int &count, int & nNumber, STreeNode *& pNode)const
{
	count = 0;
	if (!root)
	{
		return true;
	}
	int nMin1 = INT_MAX;
	int nMin2 = INT_MAX;
	int nMax1 = INT_MIN;
	int nMax2 = INT_MIN;

	int c1 = 0, c2 = 0; // 左右子树节点个数

	// 左子树最左边
	if (!_LargestBST(root->pLeft, nMin1, nMax1, c1, nNumber, pNode))
	{
		return false;
	}

	// 右子树最右边
	if (!_LargestBST(root->pRight, nMin2, nMax2, c2, nNumber, pNode))
	{
		return false;
	}


	// 如果当前根节点小于左子树最大值 或者大于右子树最小值 则不满足条件
	if ((root->value < nMax1) || (root->value > nMin2))
	{
		return false;
	}

	count = c1 + c2 + 1;
	nMin = nMin1 < root->value ? nMin1 : root->value;
	nMax = nMax2 > root->value ? nMax2 : root->value;
	if (count > nNumber) // 更新
	{
		nNumber = count; // 节点个数
		pNode = root;    // 最大子树根
	}

	return true;
}
