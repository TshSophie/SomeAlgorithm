/*
	����������
	������ͼ��ʾ��������ͨͼ���ٶ�ͼ�����бߵ�Ȩֵ��Ϊ1��
	��Ȼ����ԭ��A���յ�T�����·���ж�������ͬ�����·������Ŀ
	
	A0��������E3    J8��������N12
	|    |      |	   |
	|	 |	    |      |
	B1��������F5��������K9��������O13
	|    |      |      |
	|    |	    |	   |
	C2��������G6��������L10��������P14
	|    |      |      |
	|	 |	    |	   |
	D3��������H7	M11��������T15
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "queue.h"

#define N 16

int map[N][N] = { 0 }; // �ڽӾ��� , ȫ����ʼ��Ϊ0��ʾ�������㽨û�б�����

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

int CalcShortPathNum(int G[N][N]){

	int step[N] = { 0 }; // ÿ���ڵ�ڼ������Ե���
	int stepNumber[N] = { 0 }; // ��ÿ���ڵ��м����߷�

	stepNumber[0] = 1;
	Queue *q = InitQueue(); // ��ǰ�����Ľڵ�
	PushQueue(q, 0);
	int from, i, s;
	while (IsEmptyQueue(q))
	{
		from = FrontQueue(q);
		PopQueue(q);
		s = step[from] + 1;
		for (i = 1; i < N; i++) // 0����㣬������
		{
			if (G[from][i] == 1)  // ��ͨ
			{
				// ���뵽���������ĵ������������
				// ��1������û�����ֹ��������ߵĵ� \
						��ʱ����Ҫ���������Ĳ�����¼�Լ�·������¼
				// ��2���Ѿ��в�����¼�ĵ㣬������ε���������·������ \
						��ʱ����Ҫ���������Ĳ�����¼�Լ�·������¼
				// ��3���Ѿ��в�����¼�ĵ㣬������ε���������·������һ����һ���ģ�\
						��ʱ����Ҫ����������·������¼

				// i��δ�ɴ���߷��ָ����·��
				if ((step[i]==0)||(step[i]>s))
				{
					step[i] = s;
					stepNumber[i] = stepNumber[from];
					PushQueue(q,i);
				}
				else if (step[i] == s) // ������ͬ���ȵ�·��
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