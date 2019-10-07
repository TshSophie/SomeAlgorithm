/*
	Huffman 编码是一种无损压缩编码方案。
	其主要思想：
	根据源字符出现的概率对字符编码，概率高的字符使用较短的编码，概率低的使用较长的编码，
	从而得到编码后的字符串长度期望最小
	Huffman编码是一种贪心算法：每一次总选择两个小概率的字符结合点合并。
	称字符出现的次数为频数，则概率约等于频数除以字符总长，因此，概率可以用频数代替。

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


// 计算字符的权重
void ClacFrequency(const char *str, int *pWeight)
{
	while (*str)
	{
		pWeight[*str]++;
		str++;
	}
}


// 把存在的字符筛选出来
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
	找出权值最小的两个节点(找最大和第二大的值)
	pHuffmanTree: 赫夫曼树
	n: 赫夫曼树节点个数
	s1: 赫夫曼树上当前权值最大节点，输出参数
	s2: 赫夫曼树上当前权值第二大节点，输出参数s
*/
void SelectNode(const HuffmanNode* pHuffmanTree, int n, int &s1, int &s2)
{
	s1 = -1; // 无效值
	s2 = -1;
	int nMin1 = -1; // 无效值
	int nMin2 = -1;
	for (int i = 0; i < n; i++)
	{
		// 如果该节点还没有合并且其权值大于0即字符出现过
		if ((pHuffmanTree[i].nParent == 0) && (pHuffmanTree[i].nWeight > 0))
		{
			// 找权值第一大的
			if ((s1 < 0)||(nMin1 > pHuffmanTree[i].nWeight))
			{
				// 先把上一次找到的最大的给第二大的
				s2 = s1; 
				nMin2 = nMin1;

				// 更新第一个大的值
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
	赫夫曼编码
	pWeight：字符权重数组
	N：有效字符个数
	code：二维数组，每个元素存放该字符的二进制编码，为输出参数
*/
void HuffmanCoding(int *pWeight, int N, vector<vector<char>>& code)
{	
		if (N < 0 )
		{
			return;
		}
		int m = 2 * N - 1; // N个节点的Huffman树需要2N-1个节点(节点间需要两两结合因此有n-1对，每对对产生一个组合节点，所以总的会有n+(n-1)个节点)
		HuffmanNode * pHuffmanTree = new HuffmanNode[m];
		int s1, s2;

		int i;
		// 建立叶子节点
		for ( i = 0; i < N; i++)
		{
			pHuffmanTree[i].nWeight = pWeight[i];
		}

		// 每次选择权值最小的两个节点建树
		for ( i = N; i < m; i++)
		{
			SelectNode(pHuffmanTree, i, s1, s2); // 找出权值最小的两个节点

			pHuffmanTree[s1].nParent = pHuffmanTree[s2].nParent = i;
			pHuffmanTree[i].leftNode = s1;
			pHuffmanTree[i].rightNode = s2;
			pHuffmanTree[i].nWeight = pHuffmanTree[s1].nWeight + pHuffmanTree[s2].nWeight;
		}	

		// 根据建好的Huffman树从叶子到根计算每个叶节点的编码
		int node, nParent;
		for ( i = 0; i < N; i++)
		{
			vector<char>& cur = code[i];

			node = i;
			nParent = pHuffmanTree[node].nParent;
			while (nParent != 0) // 从树顶到树根
			{
				// 左孩子编码为0，右孩子编码为1
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
	ClacFrequency(str, pWeight); // 计算各个字符出现的频率
	pWeight['\t'] = 0;

	vector<int> pChar; // 记录有效字符
	CalcExistChar(pWeight, N, pChar);
	int N2 = (int)pChar.size(); // 有效字符的长度

	vector<vector<char>> code(N2);
	HuffmanCoding(pWeight, N2, code); // 赫夫曼编码
	Print(code, pChar); // 打印
	
	system("pause");
	return 0;
}
