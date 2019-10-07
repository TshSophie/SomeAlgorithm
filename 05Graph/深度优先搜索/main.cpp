#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
using namespace std;

void DFS(const vector<vector<int>>& graph,int root,int &n/*����*/,int *dfn){
	int N = (int)graph.size();	
	dfn[root] = n;
	n++;
	for (int j = 0; j < N; j++)
	{
		// �ҵ��뵱ǰ���ڵ������Ľڵ�
		if (graph[root][j] != 0)
		{
			if (dfn[j] == -1)  // ��δ���ʹ��Ľڵ�
			{
				cout << n << char(j + 'A') << "->";
				// �ݹ����
				DFS(graph, j, n,dfn);
			}			
		}
	}
}


void readFile(vector<vector<int>> &graph){

	int a, b; // ����������������������
	FILE *fp;
	if ((fp = fopen("Graph.txt", "r+")) == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(0);
	}
	while (fscanf(fp, "%d %d", &a, &b) != EOF)
	{
		a -= 1;
		b -= 1;
		graph[a][b] = 1; // ��ʾ����aָ�򶥵�b�ı�		
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
	
	// ��ȡ��������
	readFile(graph);

	// ��ӡͼ��ϵ
	printGraph(graph);
	
	int n = 1;
	int *dfn = new int[N]; // ��¼�����ʹ��Ľڵ�
	fill(dfn, dfn + N, -1); // ���нڵ���δ����

	cout << n << char(0 + 'A') << "->"; // �׽ڵ�
	DFS(graph, 0, n,dfn);

	system("pause");
	return 0;
}
