/*
	Huffman ������һ������ѹ�����뷽����
	����Ҫ˼�룺
	����Դ�ַ����ֵĸ��ʶ��ַ����룬���ʸߵ��ַ�ʹ�ý϶̵ı��룬���ʵ͵�ʹ�ýϳ��ı��룬
	�Ӷ��õ��������ַ�������������С
	Huffman������һ��̰���㷨��ÿһ����ѡ������С���ʵ��ַ���ϵ�ϲ���
	���ַ����ֵĴ���ΪƵ���������Լ����Ƶ�������ַ��ܳ�����ˣ����ʿ�����Ƶ�����档

*/
#include<iostream>
#include<vector>
using namespace std;


typedef struct HuffmanNode{
	int leftNode;
	int rightNode;
	int nWeight;
	int nParent;
	HuffmanNode() :leftNode(0), rightNode(0), nWeight(0), nParent(0){}
}HuffmanNode;


// �����ַ���Ȩ��
void ClacFrequency(const char *str, int *pWeight)
{
	while (*str)
	{
		pWeight[*str]++;
		str++;
	}
}


// �Ѵ��ڵ��ַ�ɸѡ����
void CalcExistChar(int *pWeight, int N, vector<int>& pChar)
{
	int j = 0;
	for (int i = 0; i < N; i++)
	{
		if (pWeight[i] != 0)
		{
			pChar.push_back(i);
			if (j != i)
			{
				pWeight[j] = pWeight[i];
			}
			j++;
		}
	}
}


/*
	�ҳ�Ȩֵ��С�������ڵ�(�����͵ڶ����ֵ)
	pHuffmanTree: �շ�����
	n: �շ������ڵ����
	s1: �շ������ϵ�ǰȨֵ���ڵ㣬�������
	s2: �շ������ϵ�ǰȨֵ�ڶ���ڵ㣬�������s
*/
void SelectNode(const HuffmanNode* pHuffmanTree, int n, int &s1, int &s2)
{
	s1 = -1; // ��Чֵ
	s2 = -1;
	int nMin1 = -1; // ��Чֵ
	int nMin2 = -1;
	for (int i = 0; i < n; i++)
	{
		// ����ýڵ㻹û�кϲ�����Ȩֵ����0���ַ����ֹ�
		if ((pHuffmanTree[i].nParent == 0) && (pHuffmanTree[i].nWeight > 0))
		{
			// ��Ȩֵ��һ���
			if ((s1 < 0)||(nMin1 > pHuffmanTree[i].nWeight))
			{
				// �Ȱ���һ���ҵ������ĸ��ڶ����
				s2 = s1; 
				nMin2 = nMin1;

				// ���µ�һ�����ֵ
				s1 = i;
				nMin1 = pHuffmanTree[s1].nWeight;
			}
			else if ((s2 < 0) || (nMin2 > pHuffmanTree[i].nWeight))
			{
				s2 = i;
				nMin2 = pHuffmanTree[s2].nWeight;
			}
		}
	}
}


/* 
	�շ�������
	pWeight���ַ�Ȩ������
	N����Ч�ַ�����
	code����ά���飬ÿ��Ԫ�ش�Ÿ��ַ��Ķ����Ʊ��룬Ϊ�������
*/
void HuffmanCoding(int *pWeight, int N, vector<vector<char>>& code)
{	
		if (N < 0 )
		{
			return;
		}
		int m = 2 * N - 1; // N���ڵ��Huffman����Ҫ2N-1���ڵ�(�ڵ����Ҫ������������n-1�ԣ�ÿ�ԶԲ���һ����Ͻڵ㣬�����ܵĻ���n+(n-1)���ڵ�)
		HuffmanNode * pHuffmanTree = new HuffmanNode[m];
		int s1, s2;

		int i;
		// ����Ҷ�ӽڵ�
		for ( i = 0; i < N; i++)
		{
			pHuffmanTree[i].nWeight = pWeight[i];
		}

		// ÿ��ѡ��Ȩֵ��С�������ڵ㽨��
		for ( i = N; i < m; i++)
		{
			SelectNode(pHuffmanTree, i, s1, s2); // �ҳ�Ȩֵ��С�������ڵ�

			pHuffmanTree[s1].nParent = pHuffmanTree[s2].nParent = i;
			pHuffmanTree[i].leftNode = s1;
			pHuffmanTree[i].rightNode = s2;
			pHuffmanTree[i].nWeight = pHuffmanTree[s1].nWeight + pHuffmanTree[s2].nWeight;
		}	

		// ���ݽ��õ�Huffman����Ҷ�ӵ�������ÿ��Ҷ�ڵ�ı���
		int node, nParent;
		for ( i = 0; i < N; i++)
		{
			vector<char>& cur = code[i];

			node = i;
			nParent = pHuffmanTree[node].nParent;
			while (nParent != 0) // ������������
			{
				// ���ӱ���Ϊ0���Һ��ӱ���Ϊ1
				if (pHuffmanTree[nParent].leftNode == node)
				{					
					cur.push_back('0');
				}
				else
				{
					cur.push_back('1');
				}
				node = nParent;
				nParent = pHuffmanTree[node].nParent;
			}
			reverse(cur.begin(), cur.end());
		}	
}


void PrintCode(char c, vector<char>& code)
{
	cout << (int)c << "   " << c << ":  ";
	for (vector<char>::iterator it = code.begin(); it !=code.end(); it++)
	{
		cout << *it;
	}
	cout << "\n";
}

void Print(vector<vector<char>> &code,vector<int>& pChar)
{
	int size = (int)code.size();
	for (int i = 0; i < size; i++)
	{
		PrintCode(pChar[i], code[i]);
	}
}

int main()
{
	const int N = 256;
	//char str[] = "when I was young I'd listen to the ridio\
				 waiting for my favorite songs\
				 when they played I'd sing along,\
				 it make me smile.\
				 those were such happy times and not so long ago\
				 how I wondered where they'd gone.";
				 
	char str[] = "AAAAAAAAAAAAAAABBBBBBBCCCCCCDDDDDDEEEEE";
	int pWeight[N] = { 0 };
	ClacFrequency(str, pWeight); // ��������ַ����ֵ�Ƶ��
	pWeight['\t'] = 0;

	vector<int> pChar; // ��¼��Ч�ַ�
	CalcExistChar(pWeight, N, pChar);
	int N2 = (int)pChar.size(); // ��Ч�ַ��ĳ���

	vector<vector<char>> code(N2);
	HuffmanCoding(pWeight, N2, code); // �շ�������
	Print(code, pChar); // ��ӡ
	
	system("pause");
	return 0;
}
