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

	// ����ǰ�������������
	void Insert(STreeNode *& root, const int*preOrder, int len1,
		const int *midOrder, int len2);

	bool _LargestBST(STreeNode *root, int & nMin, int &nMax,
		int &count, int & nNumber, STreeNode *& pNode)const;

	int LargestBST(STreeNode *& pNode, int &nNumber, int &value)const;

	void PreOrder(STreeNode *root)const; // �������������(�ݹ�)
	void MidOrder(STreeNode *root)const; // �������������(�ݹ�)

private:
	STreeNode * m_pRoot;
};

void  BinaryTree::PreOrder(STreeNode *root)const{
	if (root)
	{
		cout << root->value << "->"; // ��
		PreOrder(root->pLeft); // ����������
		PreOrder(root->pRight); // ����������
	}
}

// �������������(�ݹ�)
void BinaryTree::MidOrder(STreeNode *root)const{
	if (root)
	{
		MidOrder(root->pLeft);
		cout << root->value << "->";
		MidOrder(root->pRight);
	}
}

/*
	root: �����������
	preOrder��ǰ������
	len1��ǰ�����г���
	midOrder����������
	len2���������г���
*/
void BinaryTree::Insert(STreeNode *& root, const int* preOrder, int len1,
	const int *midOrder, int len2)
{
	if (len2 <= 0)
	{
		return;
	}	

	// ��ǰ���Ҹ��ڵ�
	int cRoot = preOrder[0];
	root = new STreeNode(cRoot);		
	if (len2 == 1)
	{
		return;
	}

	// ȥ�����Ҹ�
	int i;
	for (i = 0; i < len2; i++)
	{
		if (cRoot == midOrder[i]){
			break;
		}
	}

	// ��߱���
	Insert(root->pLeft, preOrder + 1, len1 - 1, midOrder, i);

	// �ұ߱���  
	Insert(root->pRight, preOrder + i + 1, len2 - i - 1 , midOrder + i + 1, len2 - i - 1);

}


// �����������
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

	int c1 = 0, c2 = 0; // ���������ڵ����

	// �����������
	if (!_LargestBST(root->pLeft, nMin1, nMax1, c1, nNumber, pNode))
	{
		return false;
	}

	// ���������ұ�
	if (!_LargestBST(root->pRight, nMin2, nMax2, c2, nNumber, pNode))
	{
		return false;
	}


	// �����ǰ���ڵ�С�����������ֵ ���ߴ�����������Сֵ ����������
	if ((root->value < nMax1) || (root->value > nMin2))
	{
		return false;
	}

	count = c1 + c2 + 1;
	nMin = nMin1 < root->value ? nMin1 : root->value;
	nMax = nMax2 > root->value ? nMax2 : root->value;
	if (count > nNumber) // ����
	{
		nNumber = count; // �ڵ����
		pNode = root;    // ���������
	}

	return true;
}
