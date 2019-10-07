/*
	�ο����ϣ�https://www.cnblogs.com/MrSaver/p/9607552.html
	
	��Ŀ������
	ĳ��������N��С������ɣ���������Ļ�����ʩ���ۣ����ɵ���֮�佨��������������
	���������Ƹù��������������涨ֻҪ���������ӵĵ��������ͬһ�����У�����ͨ������������ת����
	�ʸù�һ���ж��ٸ����У�
	�����ͼG����ͨ��������Ŀ��

	   9---3
       |
	   6								8---0
	___|__                           ___|___
	|     |                          |     |
	2     5        7                 4     1
	
	���������
	���ϻ���

	���ϵ����ʣ��Է��ԣ��Գ���
	�����ԣ����c��b���ӽڵ㣬b��a���ӽڵ㣬��a��b��cλ����ͬ�ļ�����
	���ڼ�����Ԫ���ǵȼ۵ģ�ѡ������һ��Ԫ����Ϊ��������Ԫ�ض�ָ���Ԫ�أ������һ�����ϵı��
	��ָ��Ԫ��Ϊ�ӽڵ㣬��ָ��Ԫ��Ϊ���ڵ㡣
*/


#include <iostream>
using namespace std;

class CUnionFindSet{
private:
	int m_nN;
	int * m_pParent; // ÿ��Ԫ�ش洢�丸�ڵ�
public:
	CUnionFindSet(int n);
	~CUnionFindSet();
	void Union(int i, int j);
	int Find(int i);
	void Print() const;
};


// ���鼯
CUnionFindSet::CUnionFindSet(int n){
	m_nN = n;
	m_pParent = new int[m_nN];
	for (int i = 0; i < m_nN; i++)
	{
		m_pParent[i] = i;
	}
}

CUnionFindSet::~CUnionFindSet(){
	if (m_pParent != NULL)
	{
		delete[] m_pParent;
		m_pParent = NULL;
	}
}

// ����
int CUnionFindSet::Find(int i){
	if ((i < 0) || (i >= m_nN))
	{
		return -1;
	}
	int root = i;
	// ����ѭ����ֱ���ҵ�i�ĸ��ڵ�
	while (root != m_pParent[root])
	{
		root = m_pParent[root];
	}

	int t = i;
	int p;
	while (t != root)  // ѹ��·������t��root֮��ľ����Ľڵ㶼ֱ��ָ��root
	{
		p = m_pParent[t];		// t2��ԭ���ڵ�
		m_pParent[t] = root;	// t2�ĸ��ڵ�ֱ�Ӹ�ֵ����t
		t = p;					// ����ԭ���ĸ��ڵ�������ϲ���
	}

	return root;
}


// �ϲ�
void CUnionFindSet::Union(int i, int j){
	if ((i < 0) || (i >= m_nN) || (j < 0) || (j >= m_nN))
	{
		return;
	}
	int ri = Find(i);
	int rj = Find(j);
	if (ri != rj)
	{
		m_pParent[ri] = rj;   // �ϲ�������֧
	}
}

int CalcCompoment(){

	const int N = 10; // ��������
	CUnionFindSet ufs(N); 
	ufs.Union(2, 6);  // ���ݱ߳�ʼ�����鼯
	ufs.Union(5, 6);
	ufs.Union(1, 8);
	ufs.Union(2, 9);
	ufs.Union(5, 3);
	ufs.Union(4, 8);
	ufs.Union(4, 0);

	int * component = new int[N];
	memset(component, 0, N*sizeof(int));
	int i;
	for ( i = 0; i < N; i++) // ����ÿ������ġ��׸���
	{
		component[ufs.Find(i)]++;
	}

	int nComponent = 0; // ͳ�ơ��׸�����Ŀ
	for ( i = 0; i < N; i++)
	{
		if (component[i] != 0)
			nComponent++;
	}
	delete[] component;
	return nComponent;
}

int main(){

	int ret = CalcCompoment();

	cout << ret << endl;
	return 0;
}
