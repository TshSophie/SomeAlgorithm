/*
	����ĳ������ͨͼG����ɾ��ĳ�ڵ�X�Լ���Y�ڽӵ����бߣ�
	ͼG��ɷ���ͨͼ����ڵ�X��ΪͼG�ĸ�㡣
	����ĳͼ���ڽӾ�����ڽӱ���μ����ͼ�����и�㣿
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
using namespace std;

/*
	const vector<vector<int>>& graph ͼ
	int i ��ǰ���ڵ�
	int parent �丸�ڵ㣨��һ���ڵ㣩
	int root ���ڵ�
	int *dfn ��¼�ڵ��Ƿ񱻷��ʹ�
	int *low ��¼��������Ľڵ�
	int &n   �ڵ���
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
		if (graph[i][j] != 0)  // �ڵ�i���ڵ�j������,������i�����Ľڵ�
		{
			if (dfn[j] == -1)  // �ڵ�j��δ�����ʹ�
			{
				child++;
				// j��Ϊ���ڵ㿪ʼ�ݹ�
				_ArticulationPoint(graph, j, i, root, dfn, low, n, an);
				// �õ��ڵ�i���ݵ�����ڵ�
				low[i] = min(low[i], low[j]);
				// ����ڵ�j������ݵĽڵ�Ҫ����i�ڵ㲢�ұ��ֵĸ��ڵ㲻����ʼ�ĸ��ڵ�
				if ((i != root) && (low[j] >= dfn[i]))
				{
					an[i] = true;
				}
				else if ((i == root) && (child == 2))
				{
					an[i] = true;
				}

			} // �Ѿ����ʹ���˵��j��i�ĸ��ڵ�����Ƚڵ㣬����ʱi�ĸ��ڵ㲻��j����j��i�����Ƚڵ�
			else if (parent != j) 
			{
				// ��ô�Ա�һ�µ�ǰi������ݵĽڵ�����ڵ�j�ı�ţ���˭����
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
	int * dfn = new int[N];  // dfn[i]=j ��i���ڵ��ǵ�j�������ʵ�
	fill(dfn, dfn + N, -1); // ���нڵ���δ����
	int *low = new int[N]; // low[i] = j; i ����������ݵ�����ڵ�Ϊj
	int root = 0;  // ����ָ��һ���ڵ���Ϊ���ڵ�
	int n = 0;	// ����������
	_ArticulationPoint(graph, root, -1, root, dfn, low, n, an);
	delete[] dfn;
	delete[] low;
}


int main(){
	int N = 13;
	vector<vector<int>> graph(N, vector<int>(N));
	//int i, j;
	// ifstream iFile("Graph.txt");
	
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