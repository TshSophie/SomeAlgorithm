#include<iostream>
#include"BinaryTree.h"

using namespace std;

/*******************************************
	二叉查找树(二叉搜索树)是满足如下条件的二叉树：
	- 左子树上所有的节点值均小于根节点值
	- 右子树上的所有节点值均不小于根节点值
	- 左右子树也满足上述两个条件

*****************************************/

BinaryTree::BinaryTree()
{

}

BinaryTree::~BinaryTree()
{
}

/**********************************************************

二叉树查找树的插入：
- 若当前的二叉查找树为空，则插入的元素为根节点
- 若插入的元素值小于根节点值，则将元素插入到左子树中
- 若插入的元素值不小于根节点值，则将元素插入到右子树中
- 递归上述过程，直到找到插入点为叶子节点。

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


// 非递归插入节点
bool BinaryTree::_Insert2(int value)
{	
	if (!m_pRoot)
	{
		m_pRoot = new STreeNode(value);
		return true;
	}
	STreeNode * pNode = m_pRoot; // 用来保存遍历时的节点
	STreeNode * pCur = m_pRoot;  // 辅助节点
	while (pNode)
	{
		pCur = pNode;
		if (value < pNode->value){ // 如果小于当前节点的值，则往左边走
		
			pNode = pNode->pLeft;
		}
		else if (value > pNode->value){

			pNode = pNode->pRight;
		}
		else{		
			return false; // 插入的值已经存在了
		}
	}


	// 遍历到目标父节点时判断是左孩子还是右孩子
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
	二叉搜索树的查找：查找节点p
	- 将当前节点cur赋值为根节点root
	- 若p的值小于当前节点cur的值，就查找cur的左子树
	- 若p的值不小于当前节点cur的值，就查找cur的右子树
	- 递归上述过程，直到cur的值等于p的值或者cur为空

***************************************************/

STreeNode* BinaryTree::Find(int value) const
{
	if (!m_pRoot)
	{
		return NULL; // 树还没有元素返回空
	}
	// 从根节点开始查找
	STreeNode * currentNode = m_pRoot;
	while (currentNode)
	{
		if (currentNode->value == value){

			return currentNode;
		}
		else if (currentNode->value > value){ // 要查找的值小于当前节点的值

			currentNode = currentNode->pLeft;
		}
		else 
		{
			currentNode = currentNode->pRight;
		}
	}

	return NULL;
}


// 删除单支节点
void BinaryTree::DeleteSingleSon(STreeNode *parentNode, STreeNode * currentNode){

	// 取出其孩子节点
	STreeNode *childNode = currentNode->pLeft ? currentNode->pLeft : currentNode->pRight;
	if (currentNode == m_pRoot)
	{
		m_pRoot = childNode;

	}// 判断当前节点是否是左节点，然后将其孩子节点代替其的位置
	else if (parentNode->pLeft == currentNode) {

		parentNode->pLeft = childNode;
	}
	else{

		parentNode->pRight = childNode;
	}
	delete currentNode;
}

// 删除叶子节点
void BinaryTree::DeleteEndNode(STreeNode *parentNode, STreeNode * currentNode){
	
	if (currentNode == m_pRoot) // 如果该节点是根节点的话，说明该节点是唯一的节点了
	{
		m_pRoot = NULL;
	}
	else if (parentNode->pLeft == currentNode){ // 判断是父节点的哪个孩子

		parentNode->pLeft = NULL;
	}
	else{
		parentNode->pRight = NULL;
	}

	delete currentNode;
}


/*********************************************
 删除节点：
 待删除节点p可能是
 - p为叶子节点
 - p为单支节点
 - p的左子树和右子树均不空

**********************************************/
bool BinaryTree::Delete(int value){
	if (!m_pRoot)
	{
		return false;
	}

	// 首先找到要删除的节点
	STreeNode *currentNode = m_pRoot;
	// 父节点
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
	if (!currentNode) // 没找到
	{
		return false;
	}

	// 情况一：不存在左右孩子(即叶子节点)，将其父节点指向NULL并直接删除该节点
	if (!currentNode->pLeft && !currentNode->pRight)
	{
		DeleteEndNode(parentNode, currentNode);

	}// 情况二：该节点只有一个孩子
	else if (!currentNode->pLeft || !currentNode->pRight)
	{
		DeleteSingleSon(parentNode, currentNode);

	}// 情况三：有左右孩子的节点，我们要做的就是把该节点右孩子后继中的最小节点给替换过来(即p的右孩子的最左子孙d)，然后就把d给删除，相当于删除单支节点(因为d已经是最小的了肯定没有左子树了)
	else
	{
		STreeNode *tempNode = currentNode; //缓存待删除节点
		parentNode = currentNode;
		currentNode = currentNode->pLeft;
		while (currentNode->pRight)
		{
			parentNode = currentNode;
			currentNode = currentNode->pRight;
		}
		tempNode->value = currentNode->value; // 删除数据(把数据覆盖过去，然后把d给删掉)
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
 二叉树先序遍历:
 【1】访问根节点
 【2】先序遍历左子树
 【2】先序遍历右子树
***************************************/
void  BinaryTree::PreOrder(STreeNode *root)const{
	if (root)
	{
		cout << root->value << "->"; // 根
		PreOrder(root->pLeft); // 遍历左子树
		PreOrder(root->pRight); // 遍历右子树
	}
}

// 二叉树先序遍历(非递归)
void  BinaryTree::PreOrder2()const{
	if (!m_pRoot)
	{
		return;
	}
	stack<STreeNode *> s; // 栈
	s.push(m_pRoot); // 把根节点入栈
	STreeNode* pCur;
	while (!s.empty()) // 栈不为空
	{
		pCur = s.top(); 
		s.pop(); // 出栈
		cout << pCur->value << "->";

		if (pCur->pRight)
		{
			s.push(pCur->pRight); // 右孩子入栈
		}
		if (pCur->pLeft)
		{
			s.push(pCur->pLeft); // 左孩子入栈
		}
	}

}



/***************************************
二叉树中序遍历:
【1】先遍历左子树
【2】访问根节点
【2】遍历右子树
***************************************/
// 二叉树中序遍历(递归)
void BinaryTree::MidOrder(STreeNode *root)const{
	if (root)
	{
		MidOrder(root->pLeft);
		cout << root->value << "->";
		MidOrder(root->pRight);
	}
}

// 二叉树中序遍历(非递归)
void BinaryTree::MidOrder2()const{

	if (!m_pRoot)
	{
		return;
	}
	stack<STreeNode *> s; // 栈	
	STreeNode* pCur = m_pRoot; // 根节点

	while (pCur || !s.empty()) // 当前节点或栈不为空
	{		
		while (pCur) // 找最左边的孩子(该节点肯定是没有左孩子的)，沿途的左孩子均入栈
		{
			s.push(pCur);
			pCur = pCur->pLeft;
		}
		// 找到最左左孩子了，那么就把当前指向的节点输出，并指向右孩子继续找左孩子
		if (!s.empty())
		{
			pCur = s.top();
			s.pop();
			cout << pCur->value << "->";
			pCur = pCur->pRight; // 转向有右孩子			
		}
	}
}

// 二叉树中序遍历(非递归)
void BinaryTree::MidOrder3()const
{
	if (!m_pRoot)
	{
		return;
	}
	stack<pair<STreeNode *, int>> s; // 栈	
	s.push(make_pair(m_pRoot, 0)); // 根节点入栈
	STreeNode* pCur; // 根节点
	int times = 0;

	while (!s.empty())
	{
		pCur = s.top().first; // 取出节点
		times = s.top().second; // 取出该节点入栈次数
		s.pop(); // 弹出栈顶		
		if (times == 0)
		{
			if (pCur->pRight)
			{
				s.push(make_pair(pCur->pRight, 0)); // 第一次入栈
			}
			s.push(make_pair(pCur, 1)); // 二次入栈

			if (pCur->pLeft)
			{
				s.push(make_pair(pCur->pLeft, 0)); // 第一次入栈
			}
		}
		else
		{
			// 输出
			cout << pCur->value << "->";
		}
	}

}

/***************************************
二叉树后序遍历:
【1】遍历左子树
【2】遍历右子树
【2】访问根节点
***************************************/
// 二叉树后序遍历(递归)
void BinaryTree::BackOrder(STreeNode *root)const
{
	if (root)
	{
		BackOrder(root->pLeft);
		BackOrder(root->pRight);
		cout << root->value << "->";
	}
}

// 二叉树后序遍历(非递归)
void BinaryTree::BackOrder2()const
{
	if (!m_pRoot)
	{
		return;
	}
	stack<pair<STreeNode *,int>> s; // 栈	
	s.push(make_pair(m_pRoot, 0)); // 根节点入栈
	STreeNode* pCur; // 根节点
	int times = 0;

	while (!s.empty())
	{
		pCur = s.top().first; // 取出节点
		times = s.top().second; // 取出该节点入栈次数
		s.pop(); // 弹出栈顶		
		if (times == 0)
		{
			s.push(make_pair(pCur, 1)); // 二次入栈
			if (pCur->pRight)
			{
				s.push(make_pair(pCur->pRight,0)); // 第一次入栈
			}
			if (pCur->pLeft)
			{
				s.push(make_pair(pCur->pLeft, 0)); // 第一次入栈
			}
		}
		else
		{
			// 输出
			cout << pCur->value << "->";
		}
	}

}

/*****************************************************************
	最大二叉搜索子树


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

