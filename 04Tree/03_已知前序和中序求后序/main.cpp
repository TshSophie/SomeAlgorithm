#include<iostream>

using namespace std;
/*
	ǰ�� "GDAFEMHZ";
	���� "ADEFGHMZ";
	���������������
	tips:��������׸��ڵ�һ��Ϊ��
*/

/*
	pMidOrder����������
	pPreOrder: ��������
	nLength:���г���
	pBackOrder:�����������
	nIndex:���
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
	char root = *pPreOrder; // ��������׸��ڵ�һ��Ϊ��
	int nRoot = 0; // ��������

	for (;nRoot < nLength ; nRoot++) // ���������ҵ�������λ��
	{
		if (pMidOrder[nRoot] == root)
		{
			break;
		}
	}

	// ǰ�벿��(0 ~ nRoot)
	MidPre2Back(pMidOrder, pPreOrder + 1, nRoot, pBackOrder, nIndex);

	// ��벿��(nRoot + 1 ~ nLength - (nRoot+1))
	MidPre2Back(pMidOrder + nRoot + 1, pPreOrder + nRoot + 1, nLength - (nRoot+1), pBackOrder, nIndex);

	pBackOrder[nIndex] = root; // �õ���

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