/*
	问题描述：
	给定如图所示的无向连通图，假定图中所有边的权值都为1，
	显然，从原点A到终点T的最短路径有多条，求不同的最短路径的数目
	
	A0————E3    J8————N12
	|    |      |	   |
	|	 |	    |      |
	B1————F5————K9————O13
	|    |      |      |
	|    |	    |	   |
	C2————G6————L10————P14
	|    |      |      |
	|	 |	    |	   |
	D3————H7	M11————T15
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "queue.h"

#define N 16

int map[N][N] = { 0 }; // 邻接矩阵 , 全部初始化为0表示各个顶点建没有边连接

//读取数据创建邻接矩阵
void ReadData(){
	int a, b; // 定义两个变量，用来输入
	FILE *fp;
	if ((fp = fopen("data.txt", "r+")) == NULL)
	{
		printf("打开文件失败\n");
		exit(0);
	}

	while (fscanf(fp, "%d %d", &a, &b) != EOF)
	{
		map[a][b] = 1; // 表示顶点a指向顶点b的边
		//printf("a = %d,b = %d\n", a, b);
	}

	fclose(fp);
}


// 打印矩阵
void PrintMap(){
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 1; j <= N - 1; j++)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}

int CalcShortPathNum(int G[N][N]){

	int step[N] = { 0 }; // 每个节点第几步可以到达
	int stepNumber[N] = { 0 }; // 到每个节点有几种走法

	stepNumber[0] = 1;
	Queue *q = InitQueue(); // 当前搜索的节点
	PushQueue(q, 0);
	int from, i, s;
	while (IsEmptyQueue(q))
	{
		from = FrontQueue(q);
		PopQueue(q);
		s = step[from] + 1;
		for (i = 1; i < N; i++) // 0是起点，不遍历
		{
			if (G[from][i] == 1)  // 连通
			{
				// 进入到这个条件里的点有两种情况：
				// 【1】还从没被发现过的有连线的点 \
						这时候需要更新这个点的步数记录以及路径数记录
				// 【2】已经有步长记录的点，但是这次到达这个点的路径更短 \
						这时候需要更新这个点的步数记录以及路径数记录
				// 【3】已经有步长记录的点，但是这次到达这个点的路径与上一次是一样的，\
						这时候需要更新这个点的路径数记录

				// i尚未可达或者发现更快的路径
				if ((step[i]==0)||(step[i]>s))
				{
					step[i] = s;
					stepNumber[i] = stepNumber[from];
					PushQueue(q,i);
				}
				else if (step[i] == s) // 发现相同长度的路径
				{
					stepNumber[i] += stepNumber[from];
				}
			}
		}
	}
	/*for (int i = 0; i < N; i++)
	{
		printf("%c %d  ", 'A'+i, stepNumber[i]);
	}*/
	return stepNumber[N - 1];
	
}

int main(){

	ReadData();

	PrintMap();

	int n = CalcShortPathNum(map);

	printf("The number of short path where from A to P are %d\n", n);

	system("pause");
	return 0;
	
}