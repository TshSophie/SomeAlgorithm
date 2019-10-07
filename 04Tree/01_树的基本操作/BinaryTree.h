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
	bool _Insert(STreeNode *& pRoot, int value); // �ݹ����ڵ�
	bool _Insert2(int value); // �ǲ���ڵ�
	STreeNode* Find(int value)const; // ���ҽڵ�
	bool Delete(int value); // ɾ���ڵ�

	void PreOrder(STreeNode *root)const; // �������������(�ݹ�)
	void PreOrder2()const; // �������������(�ǵݹ�)

	void MidOrder(STreeNode *root)const; // �������������(�ݹ�)
	void MidOrder2()const; // �������������(�ǵݹ�)
	void MidOrder3()const; // �������������(�ǵݹ�)


	void BackOrder(STreeNode *root)const; // �������������(�ݹ�)
	void BackOrder2()const; // �������������(�ǵݹ�)

	bool _LargestBST(STreeNode *root, int & nMin, int &nMax,
		int &count, int & nNumber, STreeNode *& pNode)const;
	
	int LargestBST( STreeNode *& pNode)const;


private:
	// ɾ����֧�ڵ�
	void DeleteSingleSon(STreeNode *parentNode, STreeNode * currentNode);
	// ɾ��Ҷ�ӽڵ�
	void DeleteEndNode(STreeNode *parentNode, STreeNode * currentNode);
private:
	STreeNode * m_pRoot;
};

