#include<iostream>
#include"BinaryTree.h"

using namespace std;

/*******************************************
	���������(����������)���������������Ķ�������
	- �����������еĽڵ�ֵ��С�ڸ��ڵ�ֵ
	- �������ϵ����нڵ�ֵ����С�ڸ��ڵ�ֵ
	- ��������Ҳ����������������

*****************************************/

BinaryTree::BinaryTree()
{

}

BinaryTree::~BinaryTree()
{
}

/**********************************************************

�������������Ĳ��룺
- ����ǰ�Ķ��������Ϊ�գ�������Ԫ��Ϊ���ڵ�
- �������Ԫ��ֵС�ڸ��ڵ�ֵ����Ԫ�ز��뵽��������
- �������Ԫ��ֵ��С�ڸ��ڵ�ֵ����Ԫ�ز��뵽��������
- �ݹ��������̣�ֱ���ҵ������ΪҶ�ӽڵ㡣

***********************************************************/

bool BinaryTree::_Insert(STreeNode *& pRoot, int value)
{
	if (!pRoot)
	{
		pRoot = new STreeNode(value);
		return true;
	}
	if (value < pRoot->value)
	{
		return _Insert(pRoot->pLeft, value);
	}
	if (value > pRoot->value)
	{
		return _Insert(pRoot->pRight, value);
	}
	return false;
}


// �ǵݹ����ڵ�
bool BinaryTree::_Insert2(int value)
{	
	if (!m_pRoot)
	{
		m_pRoot = new STreeNode(value);
		return true;
	}
	STreeNode * pNode = m_pRoot; // �����������ʱ�Ľڵ�
	STreeNode * pCur = m_pRoot;  // �����ڵ�
	while (pNode)
	{
		pCur = pNode;
		if (value < pNode->value){ // ���С�ڵ�ǰ�ڵ��ֵ�����������
		
			pNode = pNode->pLeft;
		}
		else if (value > pNode->value){

			pNode = pNode->pRight;
		}
		else{		
			return false; // �����ֵ�Ѿ�������
		}
	}


	// ������Ŀ�길�ڵ�ʱ�ж������ӻ����Һ���
	if (value < pCur->value)
	{
		pCur->pLeft = new STreeNode(value);
	}
	else if (value > pCur->value){
		pCur->pRight = new STreeNode(value);
	}
	return true;
}


/***************************************************
	�����������Ĳ��ң����ҽڵ�p
	- ����ǰ�ڵ�cur��ֵΪ���ڵ�root
	- ��p��ֵС�ڵ�ǰ�ڵ�cur��ֵ���Ͳ���cur��������
	- ��p��ֵ��С�ڵ�ǰ�ڵ�cur��ֵ���Ͳ���cur��������
	- �ݹ��������̣�ֱ��cur��ֵ����p��ֵ����curΪ��

***************************************************/

STreeNode* BinaryTree::Find(int value) const
{
	if (!m_pRoot)
	{
		return NULL; // ����û��Ԫ�ط��ؿ�
	}
	// �Ӹ��ڵ㿪ʼ����
	STreeNode * currentNode = m_pRoot;
	while (currentNode)
	{
		if (currentNode->value == value){

			return currentNode;
		}
		else if (currentNode->value > value){ // Ҫ���ҵ�ֵС�ڵ�ǰ�ڵ��ֵ

			currentNode = currentNode->pLeft;
		}
		else 
		{
			currentNode = currentNode->pRight;
		}
	}

	return NULL;
}


// ɾ����֧�ڵ�
void BinaryTree::DeleteSingleSon(STreeNode *parentNode, STreeNode * currentNode){

	// ȡ���亢�ӽڵ�
	STreeNode *childNode = currentNode->pLeft ? currentNode->pLeft : currentNode->pRight;
	if (currentNode == m_pRoot)
	{
		m_pRoot = childNode;

	}// �жϵ�ǰ�ڵ��Ƿ�����ڵ㣬Ȼ���亢�ӽڵ�������λ��
	else if (parentNode->pLeft == currentNode) {

		parentNode->pLeft = childNode;
	}
	else{

		parentNode->pRight = childNode;
	}
	delete currentNode;
}

// ɾ��Ҷ�ӽڵ�
void BinaryTree::DeleteEndNode(STreeNode *parentNode, STreeNode * currentNode){
	
	if (currentNode == m_pRoot) // ����ýڵ��Ǹ��ڵ�Ļ���˵���ýڵ���Ψһ�Ľڵ���
	{
		m_pRoot = NULL;
	}
	else if (parentNode->pLeft == currentNode){ // �ж��Ǹ��ڵ���ĸ�����

		parentNode->pLeft = NULL;
	}
	else{
		parentNode->pRight = NULL;
	}

	delete currentNode;
}


/*********************************************
 ɾ���ڵ㣺
 ��ɾ���ڵ�p������
 - pΪҶ�ӽڵ�
 - pΪ��֧�ڵ�
 - p����������������������

**********************************************/
bool BinaryTree::Delete(int value){
	if (!m_pRoot)
	{
		return false;
	}

	// �����ҵ�Ҫɾ���Ľڵ�
	STreeNode *currentNode = m_pRoot;
	// ���ڵ�
	STreeNode *parentNode = NULL;

	while (currentNode)
	{
		if (currentNode->value == value){
		
			break;
		}
		else if (currentNode->value > value){
			parentNode = currentNode;
			currentNode = currentNode->pLeft;

		}else{
			parentNode = currentNode;
			currentNode = currentNode->pRight;
		}		
	}
	if (!currentNode) // û�ҵ�
	{
		return false;
	}

	// ���һ�����������Һ���(��Ҷ�ӽڵ�)�����丸�ڵ�ָ��NULL��ֱ��ɾ���ýڵ�
	if (!currentNode->pLeft && !currentNode->pRight)
	{
		DeleteEndNode(parentNode, currentNode);

	}// ��������ýڵ�ֻ��һ������
	else if (!currentNode->pLeft || !currentNode->pRight)
	{
		DeleteSingleSon(parentNode, currentNode);

	}// ������������Һ��ӵĽڵ㣬����Ҫ���ľ��ǰѸýڵ��Һ��Ӻ���е���С�ڵ���滻����(��p���Һ��ӵ���������d)��Ȼ��Ͱ�d��ɾ�����൱��ɾ����֧�ڵ�(��Ϊd�Ѿ�����С���˿϶�û����������)
	else
	{
		STreeNode *tempNode = currentNode; //�����ɾ���ڵ�
		parentNode = currentNode;
		currentNode = currentNode->pLeft;
		while (currentNode->pRight)
		{
			parentNode = currentNode;
			currentNode = currentNode->pRight;
		}
		tempNode->value = currentNode->value; // ɾ������(�����ݸ��ǹ�ȥ��Ȼ���d��ɾ��)
		if (!currentNode->pLeft)
		{
			DeleteEndNode(parentNode, currentNode);
		}
		else
		{
			DeleteSingleSon(parentNode, currentNode);
		}
	}
	
	return true;
}


/***************************************
 �������������:
 ��1�����ʸ��ڵ�
 ��2���������������
 ��2���������������
***************************************/
void  BinaryTree::PreOrder(STreeNode *root)const{
	if (root)
	{
		cout << root->value << "->"; // ��
		PreOrder(root->pLeft); // ����������
		PreOrder(root->pRight); // ����������
	}
}

// �������������(�ǵݹ�)
void  BinaryTree::PreOrder2()const{
	if (!m_pRoot)
	{
		return;
	}
	stack<STreeNode *> s; // ջ
	s.push(m_pRoot); // �Ѹ��ڵ���ջ
	STreeNode* pCur;
	while (!s.empty()) // ջ��Ϊ��
	{
		pCur = s.top(); 
		s.pop(); // ��ջ
		cout << pCur->value << "->";

		if (pCur->pRight)
		{
			s.push(pCur->pRight); // �Һ�����ջ
		}
		if (pCur->pLeft)
		{
			s.push(pCur->pLeft); // ������ջ
		}
	}

}



/***************************************
�������������:
��1���ȱ���������
��2�����ʸ��ڵ�
��2������������
***************************************/
// �������������(�ݹ�)
void BinaryTree::MidOrder(STreeNode *root)const{
	if (root)
	{
		MidOrder(root->pLeft);
		cout << root->value << "->";
		MidOrder(root->pRight);
	}
}

// �������������(�ǵݹ�)
void BinaryTree::MidOrder2()const{

	if (!m_pRoot)
	{
		return;
	}
	stack<STreeNode *> s; // ջ	
	STreeNode* pCur = m_pRoot; // ���ڵ�

	while (pCur || !s.empty()) // ��ǰ�ڵ��ջ��Ϊ��
	{		
		while (pCur) // ������ߵĺ���(�ýڵ�϶���û�����ӵ�)����;�����Ӿ���ջ
		{
			s.push(pCur);
			pCur = pCur->pLeft;
		}
		// �ҵ����������ˣ���ô�Ͱѵ�ǰָ��Ľڵ��������ָ���Һ��Ӽ���������
		if (!s.empty())
		{
			pCur = s.top();
			s.pop();
			cout << pCur->value << "->";
			pCur = pCur->pRight; // ת�����Һ���			
		}
	}
}

// �������������(�ǵݹ�)
void BinaryTree::MidOrder3()const
{
	if (!m_pRoot)
	{
		return;
	}
	stack<pair<STreeNode *, int>> s; // ջ	
	s.push(make_pair(m_pRoot, 0)); // ���ڵ���ջ
	STreeNode* pCur; // ���ڵ�
	int times = 0;

	while (!s.empty())
	{
		pCur = s.top().first; // ȡ���ڵ�
		times = s.top().second; // ȡ���ýڵ���ջ����
		s.pop(); // ����ջ��		
		if (times == 0)
		{
			if (pCur->pRight)
			{
				s.push(make_pair(pCur->pRight, 0)); // ��һ����ջ
			}
			s.push(make_pair(pCur, 1)); // ������ջ

			if (pCur->pLeft)
			{
				s.push(make_pair(pCur->pLeft, 0)); // ��һ����ջ
			}
		}
		else
		{
			// ���
			cout << pCur->value << "->";
		}
	}

}

/***************************************
�������������:
��1������������
��2������������
��2�����ʸ��ڵ�
***************************************/
// �������������(�ݹ�)
void BinaryTree::BackOrder(STreeNode *root)const
{
	if (root)
	{
		BackOrder(root->pLeft);
		BackOrder(root->pRight);
		cout << root->value << "->";
	}
}

// �������������(�ǵݹ�)
void BinaryTree::BackOrder2()const
{
	if (!m_pRoot)
	{
		return;
	}
	stack<pair<STreeNode *,int>> s; // ջ	
	s.push(make_pair(m_pRoot, 0)); // ���ڵ���ջ
	STreeNode* pCur; // ���ڵ�
	int times = 0;

	while (!s.empty())
	{
		pCur = s.top().first; // ȡ���ڵ�
		times = s.top().second; // ȡ���ýڵ���ջ����
		s.pop(); // ����ջ��		
		if (times == 0)
		{
			s.push(make_pair(pCur, 1)); // ������ջ
			if (pCur->pRight)
			{
				s.push(make_pair(pCur->pRight,0)); // ��һ����ջ
			}
			if (pCur->pLeft)
			{
				s.push(make_pair(pCur->pLeft, 0)); // ��һ����ջ
			}
		}
		else
		{
			// ���
			cout << pCur->value << "->";
		}
	}

}

/*****************************************************************
	��������������


******************************************************************/
int BinaryTree::LargestBST(STreeNode *& pNode)const{

	int nMin, nMax, count;
	int nNumber = 0;
	_LargestBST(m_pRoot, nMin, nMax, count, nNumber, pNode);
	return nNumber;

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

	int c1, c2;	
	if (!_LargestBST(root->pLeft, nMin1, nMax1, c1, nNumber, pNode))
	{
		return false;
	}
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

