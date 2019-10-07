#include<iostream>
using namespace std;
/*
	后序 "AEFDHZMG";
	中序 "ADEFGHMZ";
	求前续遍历的序列
	tips: 后序遍历尾节点一定为根
*/

/*
	pMidOrder：中序序列
	pBackOrder: 后序序列
	nLength:序列长度
	pPreOrder:待求先序序列
	nIndex:序号
*/
void MidBack2Pre(const char *pMidOrder, const char * pBackOrder, int nLength, char *pPreOrder, int &nIndex)
{
	if (nLength <= 0)
	{
		return;
	}
	if (nLength == 1)
	{
		pPreOrder[nIndex] = *pBackOrder;
		nIndex++;
		return;
	}
	
	char root = pBackOrder[nLength - 1]; // 后序遍历尾节点一定为根
	// 得到根
	pPreOrder[nIndex] = root;
	nIndex++;

	int nRoot = 0; // 保存根序号

	for (; nRoot < nLength; nRoot++) // 在中序中找到根所在位置
	{
		if (pMidOrder[nRoot] == root)
		{
			break;
		}
	}

	// 前半部分
	MidBack2Pre(pMidOrder, pBackOrder, nRoot, pPreOrder, nIndex);

	// 后半部分
	MidBack2Pre(pMidOrder + nRoot + 1, pBackOrder + nRoot, nLength - (nRoot + 1), pPreOrder, nIndex);	
}

int main()
{
	char pBackOrder[] = "AEFDHZMG";
	char pMidOrder[] = "ADEFGHMZ";
	int size = sizeof(pMidOrder) / sizeof(char);
	char *pPreOrder = new char[size];
	int nIndex = 0;

	MidBack2Pre(pMidOrder, pBackOrder, size - 1, pPreOrder, nIndex);

	pPreOrder[size - 1] = 0;
	cout << pPreOrder << endl;
	delete[] pPreOrder;

	system("pause");
	return 0;

}