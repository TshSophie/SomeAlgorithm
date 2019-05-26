/*
	描述:
	 对一个有向无环图（Directed Acyclic Gragph DAG）G进行拓扑排序，是将G中所有顶点排序成线性序列，
	 使得图中任意一对顶点u、v，若边(u，v)∈E(G),则在线性序列中u出现在v之前。
	 需要注意的是：拓扑排序可能并不是唯一的

	 1、在有向图中选一个没有前驱的顶点并且输出（即入度为0的点)
	 2、从图中删除该顶点和所有以它为尾的弧，即删除所有与它有关的边。
	 3、重复上述两步，直至全部顶点均已输出；或者当图中不存在无前驱的顶点为止

	 一些参考资料：
	 https://www.cnblogs.com/en-heng/p/5085690.html
	 https://blog.csdn.net/qq_37618797/article/details/81070577
	 https://blog.csdn.net/qq_41713256/article/details/80805338
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"queue.h"
#define N 13
int map[N][N] = { 0 }; // 邻接矩阵 , 全部初始化为0表示各个顶点建没有边连接
int indegree[N] = { 0 }; // 存放入度
int v = 12; // 顶点数
int l = 16; //边数

void topoLogic(int *toposort){

	int cnt = 0; // 保存当前拓扑排序列表中有多少节点
	Queue *q = InitQueue(); // 保存入度为0的节点
	int i;
	for ( i = 1; i <= v; i++)
	{
		if (indegree[i] == 0)
			PushQueue(q, i);
	}
	int cur; // 当前入度为0的节点
	while (IsEmptyQueue(q))
	{
		cur = FrontQueue(q);
		PopQueue(q);
		toposort[cnt++] = cur;		
		for (int i = 1; i <= v; i++)
		{
			if (map[cur][i] != 0){ 
				indegree[i]--;  // 与零度点的有连接的所有点的入度减去1
				if (indegree[i]==0)
				{
					PushQueue(q, i);
				}
			}
		}
	}
}

// 队列api测试
void test(){
	
	Queue * queue = InitQueue();
	PushQueue(queue, 1);
	PushQueue(queue, 2);
	PushQueue(queue, 3);
	PushQueue(queue, 4);
	PushQueue(queue, 5);
	PushQueue(queue, 6);

	while (IsEmptyQueue(queue))
	{
		int data = FrontQueue(queue);
		printf("%d<-", data);
		PopQueue(queue);
	}
}

int main1(){
	
	test();
	system("pause");
	return 0;
}


void enterData(int *v , int *l){

	int a, b; // 定义两个变量，用来输入
	int v_, l_;
	printf("请输入顶点数:");
	scanf("%d",&v_);
	printf("请输入边数:");
	scanf("%d", &l_);

	*v = v_;
	*l = l_;

	printf("请输入边:\n");

	for (int i = 0; i < l; i++)
	{
		scanf("%d", &a);
		scanf("%d", &b);
		map[a][b] = 1; // 表示顶点a指向顶点b的边
	}

}

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

// 计算入度
void CalcuInDegree(){
	int k;
	for (int i = 1; i <= v; i++) // 计算顶点的入度
	{
		k = 0;
		for (int j = 1; j <= v; j++)
		{
			if (map[j][i] == 1) // 如果顶点j到顶点i有边，则顶点i的入度加1
				k++;
		}
		indegree[i] = k;
	}
}


int main()
{			
	//读取数据创建邻接矩阵
	ReadData();

	printf("邻接矩阵如下所示:\n");
	
	PrintMap();
	
	// 计算入度
	CalcuInDegree();
	
	int list[N-1] = { 0 };

	printf("入度\n");
	for (int i = 1; i <= v; i++)
	{
		printf("顶点%d 的入度 = %d\n",i, indegree[i]);
	}

	// 拓扑排序
	topoLogic(list);

	printf("\n");
	for (int i = 0; i < v; i++)
	{
		printf("%d ", list[i]);
	}

	system("pause");
	return 0;
   
}