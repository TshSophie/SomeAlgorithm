/*
	参考资料：https://www.cnblogs.com/MrSaver/p/9607552.html
	
	题目描述：
	某个国家有N个小岛屿组成，经过多年的基础设施积累，若干岛屿之间建立了若干桥梁。
	先重新完善该国的行政区划，规定只要有桥梁连接的岛屿则归属同一个城市（可以通过其他岛屿中转），
	问该国一共有多少个城市？
	求给定图G的连通分量的数目。

	   9---3
       |
	   6								8---0
	___|__                           ___|___
	|     |                          |     |
	2     5        7                 4     1
	
	解决方案：
	集合划分

	集合的性质：自反性，对称性
	传递性：如果c是b的子节点，b是a的子节点，则a，b，c位于相同的集合中
	由于集合中元素是等价的，选择任意一个元素作为代表，其他元素都指向该元素，即完成一个集合的表达
	称指向元素为子节点，被指向元素为父节点。
*/


#include <iostream>
using namespace std;

class CUnionFindSet{
private:
	int m_nN;
	int * m_pParent; // 每个元素存储其父节点
public:
	CUnionFindSet(int n);
	~CUnionFindSet();
	void Union(int i, int j);
	int Find(int i);
	void Print() const;
};


// 并查集
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

// 查找
int CUnionFindSet::Find(int i){
	if ((i < 0) || (i >= m_nN))
	{
		return -1;
	}
	int root = i;
	// 不断循环，直到找到i的根节点
	while (root != m_pParent[root])
	{
		root = m_pParent[root];
	}

	int t = i;
	int p;
	while (t != root)  // 压缩路径：将t到root之间的经过的节点都直接指向root
	{
		p = m_pParent[t];		// t2的原父节点
		m_pParent[t] = root;	// t2的父节点直接赋值给根t
		t = p;					// 沿着原来的父节点继续向上查找
	}

	return root;
}


// 合并
void CUnionFindSet::Union(int i, int j){
	if ((i < 0) || (i >= m_nN) || (j < 0) || (j >= m_nN))
	{
		return;
	}
	int ri = Find(i);
	int rj = Find(j);
	if (ri != rj)
	{
		m_pParent[ri] = rj;   // 合并两个分支
	}
}

int CalcCompoment(){

	const int N = 10; // 岛屿数量
	CUnionFindSet ufs(N); 
	ufs.Union(2, 6);  // 根据边初始化并查集
	ufs.Union(5, 6);
	ufs.Union(1, 8);
	ufs.Union(2, 9);
	ufs.Union(5, 3);
	ufs.Union(4, 8);
	ufs.Union(4, 0);

	int * component = new int[N];
	memset(component, 0, N*sizeof(int));
	int i;
	for ( i = 0; i < N; i++) // 计算每个岛屿的“首府”
	{
		component[ufs.Find(i)]++;
	}

	int nComponent = 0; // 统计“首府”数目
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
