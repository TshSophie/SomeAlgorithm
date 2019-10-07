#include<iostream>
using namespace std;
/*
	���� "AEFDHZMG";
	���� "ADEFGHMZ";
	��ǰ������������
	tips: �������β�ڵ�һ��Ϊ��
*/

/*
	pMidOrder����������
	pBackOrder: ��������
	nLength:���г���
	pPreOrder:������������
	nIndex:���
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
	
	char root = pBackOrder[nLength - 1]; // �������β�ڵ�һ��Ϊ��
	// �õ���
	pPreOrder[nIndex] = root;
	nIndex++;

	int nRoot = 0; // ��������

	for (; nRoot < nLength; nRoot++) // ���������ҵ�������λ��
	{
		if (pMidOrder[nRoot] == root)
		{
			break;
		}
	}

	// ǰ�벿��
	MidBack2Pre(pMidOrder, pBackOrder, nRoot, pPreOrder, nIndex);

	// ��벿��
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