#include<iostream>

using namespace std;
/*
	前序 "GDAFEMHZ";
	中序 "ADEFGHMZ";
	求后续遍历的序列
	tips:先序遍历首个节点一定为根
*/

/*
	pMidOrder：中序序列
	pPreOrder: 先序序列
	nLength:序列长度
	pBackOrder:待求后序序列
	nIndex:序号
*/
void MidPre2Back(const char *pMidOrder,const char * pPreOrder,int nLength, char *pBackOrder, int &nIndex)
{
	if (nLength <= 0)
	{
		return;
	}
	if (nLength == 1)
	{
		pBackOrder[nIndex] = *pPreOrder;
		nIndex++;
		return;
	}
	char root = *pPreOrder; // 先序遍历首个节点一定为根
	int nRoot = 0; // 保存根序号

	for (;nRoot < nLength ; nRoot++) // 在中序中找到根所在位置
	{
		if (pMidOrder[nRoot] == root)
		{
			break;
		}
	}

	// 前半部分(0 ~ nRoot)
	MidPre2Back(pMidOrder, pPreOrder + 1, nRoot, pBackOrder, nIndex);

	// 后半部分(nRoot + 1 ~ nLength - (nRoot+1))
	MidPre2Back(pMidOrder + nRoot + 1, pPreOrder + nRoot + 1, nLength - (nRoot+1), pBackOrder, nIndex);

	pBackOrder[nIndex] = root; // 得到根

	nIndex++;
}

int main()
{
	char pPreOrder[] = "GDAFEMHZ";
	char pMidOrder[] = "ADEFGHMZ";
	int size = sizeof(pMidOrder) / sizeof(char);
	char *pBackOrder = new char[size];
	int nIndex = 0;

	MidPre2Back(pMidOrder, pPreOrder, size - 1, pBackOrder, nIndex);

	pBackOrder[size - 1] = 0;
	cout << pBackOrder << endl;
	delete[] pBackOrder;

	system("pause");
	return 0;

}