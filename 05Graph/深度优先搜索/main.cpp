#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
using namespace std;

void DFS(const vector<vector<int>>& graph,int root,int &n/*次序*/,int *dfn){
	int N = (int)graph.size();	
	dfn[root] = n;
	n++;
	for (int j = 0; j < N; j++)
	{
		// 找到与当前根节点相连的节点
		if (graph[root][j] != 0)
		{
			if (dfn[j] == -1)  // 还未访问过的节点
			{
				cout << n << char(j + 'A') << "->";
				// 递归访问
				DFS(graph, j, n,dfn);
			}			
		}
	}
}


void readFile(vector<vector<int>> &graph){

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
	}
	fclose(fp);
}

void printGraph(const vector<vector<int>> &graph){
	int N = graph.size();
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

}

int main(){
	int N = 13;
	vector<vector<int>> graph(N, vector<int>(N));		
	
	// 读取测试数据
	readFile(graph);

	// 打印图关系
	printGraph(graph);
	
	int n = 1;
	int *dfn = new int[N]; // 记录被访问过的节点
	fill(dfn, dfn + N, -1); // 所有节点尚未访问

	cout << n << char(0 + 'A') << "->"; // 首节点
	DFS(graph, 0, n,dfn);

	system("pause");
	return 0;
}
