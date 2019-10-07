/*
	给定某无向连通图G，若删除某节点X以及与Y邻接的所有边，
	图G变成非连通图，则节点X称为图G的割点。
	给定某图的邻接矩阵或邻接表，如何计算该图的所有割点？
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
using namespace std;

/*
	const vector<vector<int>>& graph 图
	int i 当前根节点
	int parent 其父节点（上一个节点）
	int root 根节点
	int *dfn 记录节点是否被访问过
	int *low 记录回溯最早的节点
	int &n   节点编号
	bool *an
*/
void _ArticulationPoint(const vector<vector<int>>& graph, int i,
	int parent, int root, int *dfn, int *low, int &n, bool *an)
{
	dfn[i] = low[i] = n;
	n++;
	int N = (int)graph.size();
	int child = 0;
	for (int j = 0; j < N; j++)
	{
		if (graph[i][j] != 0)  // 节点i到节点j有连接,遍历与i相连的节点
		{
			if (dfn[j] == -1)  // 节点j还未被访问过
			{
				child++;
				// j作为根节点开始递归
				_ArticulationPoint(graph, j, i, root, dfn, low, n, an);
				// 得到节点i回溯的最早节点
				low[i] = min(low[i], low[j]);
				// 如果节点j最早回溯的节点要晚于i节点并且本轮的根节点不是起始的根节点
				if ((i != root) && (low[j] >= dfn[i]))
				{
					an[i] = true;
				}
				else if ((i == root) && (child == 2))
				{
					an[i] = true;
				}

			} // 已经访问过，说明j是i的父节点或祖先节点，若此时i的父节点不是j，则j是i的祖先节点
			else if (parent != j) 
			{
				// 那么对比一下当前i最早回溯的节点编号与节点j的编号，看谁最早
				low[i] = min(low[i], dfn[j]);
			}
		}
	}
}

void Print(bool *an, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << char(i+'A') << ": " << an[i] << endl;
	}
}


void ArticulationPoint(const vector<vector<int>>& graph, bool *an)
{
	int N = (int)graph.size();
	int * dfn = new int[N];  // dfn[i]=j 第i个节点是第j个被访问的
	fill(dfn, dfn + N, -1); // 所有节点尚未访问
	int *low = new int[N]; // low[i] = j; i 及其子孙回溯的最早节点为j
	int root = 0;  // 任意指定一个节点作为根节点
	int n = 0;	// 访问任意编号
	_ArticulationPoint(graph, root, -1, root, dfn, low, n, an);
	delete[] dfn;
	delete[] low;
}


int main(){
	int N = 13;
	vector<vector<int>> graph(N, vector<int>(N));
	//int i, j;
	// ifstream iFile("Graph.txt");
	
	int a, b; // 定义两个变量，用来输入
	FILE *fp;
	if ((fp = fopen("Graph.txt", "r+")) == NULL)
	{
		printf("打开文件失败\n");
		exit(0);
	}
	while (fscanf(fp, "%d %d", &a, &b) != EOF)
	{
		a -= 1;
		b -= 1;
		graph[a][b] = 1; // 表示顶点a指向顶点b的边
		//printf("a = %d,b = %d\n", a, b);
	}
	fclose(fp);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (graph[i][j])
			{
				cout << char(i + 'A') << "->" << char(j + 'A') << "  ";
			}			
		}
		cout << endl;
	}

	bool* an = new bool[N];
	fill(an, an + N, false);
	ArticulationPoint(graph, an);
	Print(an, N);
	return 0;
}