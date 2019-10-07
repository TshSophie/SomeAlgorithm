#include<iostream>
#include<stack>
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
	BinaryTree();
	~BinaryTree();

	STreeNode *&get(){
		return this->m_pRoot;
	}
	bool _Insert(STreeNode *& pRoot, int value); // 递归插入节点
	bool _Insert2(int value); // 非插入节点
	STreeNode* Find(int value)const; // 查找节点
	bool Delete(int value); // 删除节点

	void PreOrder(STreeNode *root)const; // 二叉树先序遍历(递归)
	void PreOrder2()const; // 二叉树先序遍历(非递归)

	void MidOrder(STreeNode *root)const; // 二叉树中序遍历(递归)
	void MidOrder2()const; // 二叉树中序遍历(非递归)
	void MidOrder3()const; // 二叉树中序遍历(非递归)


	void BackOrder(STreeNode *root)const; // 二叉树后序遍历(递归)
	void BackOrder2()const; // 二叉树后序遍历(非递归)

	bool _LargestBST(STreeNode *root, int & nMin, int &nMax,
		int &count, int & nNumber, STreeNode *& pNode)const;
	
	int LargestBST( STreeNode *& pNode)const;


private:
	// 删除单支节点
	void DeleteSingleSon(STreeNode *parentNode, STreeNode * currentNode);
	// 删除叶子节点
	void DeleteEndNode(STreeNode *parentNode, STreeNode * currentNode);
private:
	STreeNode * m_pRoot;
};

