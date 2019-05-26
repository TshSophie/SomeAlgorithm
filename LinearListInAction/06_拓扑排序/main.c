/*
	����:
	 ��һ�������޻�ͼ��Directed Acyclic Gragph DAG��G�������������ǽ�G�����ж���������������У�
	 ʹ��ͼ������һ�Զ���u��v������(u��v)��E(G),��������������u������v֮ǰ��
	 ��Ҫע����ǣ�����������ܲ�����Ψһ��

	 1��������ͼ��ѡһ��û��ǰ���Ķ��㲢������������Ϊ0�ĵ�)
	 2����ͼ��ɾ���ö������������Ϊβ�Ļ�����ɾ�����������йصıߡ�
	 3���ظ�����������ֱ��ȫ�����������������ߵ�ͼ�в�������ǰ���Ķ���Ϊֹ

	 һЩ�ο����ϣ�
	 https://www.cnblogs.com/en-heng/p/5085690.html
	 https://blog.csdn.net/qq_37618797/article/details/81070577
	 https://blog.csdn.net/qq_41713256/article/details/80805338
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"queue.h"
#define N 13
int map[N][N] = { 0 }; // �ڽӾ��� , ȫ����ʼ��Ϊ0��ʾ�������㽨û�б�����
int indegree[N] = { 0 }; // ������
int v = 12; // ������
int l = 16; //����

void topoLogic(int *toposort){

	int cnt = 0; // ���浱ǰ���������б����ж��ٽڵ�
	Queue *q = InitQueue(); // �������Ϊ0�Ľڵ�
	int i;
	for ( i = 1; i <= v; i++)
	{
		if (indegree[i] == 0)
			PushQueue(q, i);
	}
	int cur; // ��ǰ���Ϊ0�Ľڵ�
	while (IsEmptyQueue(q))
	{
		cur = FrontQueue(q);
		PopQueue(q);
		toposort[cnt++] = cur;		
		for (int i = 1; i <= v; i++)
		{
			if (map[cur][i] != 0){ 
				indegree[i]--;  // ����ȵ�������ӵ����е����ȼ�ȥ1
				if (indegree[i]==0)
				{
					PushQueue(q, i);
				}
			}
		}
	}
}

// ����api����
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

	int a, b; // ����������������������
	int v_, l_;
	printf("�����붥����:");
	scanf("%d",&v_);
	printf("���������:");
	scanf("%d", &l_);

	*v = v_;
	*l = l_;

	printf("�������:\n");

	for (int i = 0; i < l; i++)
	{
		scanf("%d", &a);
		scanf("%d", &b);
		map[a][b] = 1; // ��ʾ����aָ�򶥵�b�ı�
	}

}

//��ȡ���ݴ����ڽӾ���
void ReadData(){
	int a, b; // ����������������������
	FILE *fp;
	if ((fp = fopen("data.txt", "r+")) == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(0);
	}

	while (fscanf(fp, "%d %d", &a, &b) != EOF)
	{
		map[a][b] = 1; // ��ʾ����aָ�򶥵�b�ı�
		//printf("a = %d,b = %d\n", a, b);
	}

	fclose(fp);
}

// ��ӡ����
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

// �������
void CalcuInDegree(){
	int k;
	for (int i = 1; i <= v; i++) // ���㶥������
	{
		k = 0;
		for (int j = 1; j <= v; j++)
		{
			if (map[j][i] == 1) // �������j������i�бߣ��򶥵�i����ȼ�1
				k++;
		}
		indegree[i] = k;
	}
}


int main()
{			
	//��ȡ���ݴ����ڽӾ���
	ReadData();

	printf("�ڽӾ���������ʾ:\n");
	
	PrintMap();
	
	// �������
	CalcuInDegree();
	
	int list[N-1] = { 0 };

	printf("���\n");
	for (int i = 1; i <= v; i++)
	{
		printf("����%d ����� = %d\n",i, indegree[i]);
	}

	// ��������
	topoLogic(list);

	printf("\n");
	for (int i = 0; i < v; i++)
	{
		printf("%d ", list[i]);
	}

	system("pause");
	return 0;
   
}