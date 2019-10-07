/********************************************************************
	����һ��������ת�������m��n��λ�á�Ҫ��ֱ�ӷ�ת���������¿ռ䡣
	����� 1->��2->3->4��->5��m=2��n=4 ���� 1->��4->3->2��->5��
	�ٶ������Ĳ������㣺1<=m<=n<=������	
********************************************************************/

#include<stdio.h>
#include"LinkList.h"

void print_link(void *data){
	int *p = (int*)data;
	printf("%d -> ", data);
}

void ReverseLink(LinkList *list, int m, int n){

	if (m >= n){
		printf("n must greater than m\n");
		return;
	}
	else if (m <= 0)
	{
		printf("m must greater than 0\n");
		return;
	}
	LinkNode *head = list->head; // ͷָ��
	int start = m - 1;
	while (start--) // ��תm-1��
	{
		head = head->next;  // �ҵ�ָ��ת�ε��Ǹ��ڵ�
	}

	LinkNode *preNode = head->next; // ��ת����Ҫ��ת�ڵ����һ���ڵ�
	LinkNode *curNode = preNode->next; // ��ת����Ҫ��ת�Ľڵ�

	// ��ʼ��ת
	int times = n - m; // ��תn-m��
	while (times--)
	{
		// ���浱ǰheadָ��Ľڵ�
		LinkNode * tmpNode = head->next;

		// �ѵ�ǰ�ڵ���뵽ͷ��
		head->next = curNode;

		// ��ָ��ǰ�ڵ��ָ��ָ��ǰ�ڵ����һ���ڵ�
		preNode->next = curNode->next;

		// curNodeָ����һ���ڵ�
		curNode = curNode->next; 

		// �ѵ�ǰ�ڵ�ָ�򻺴�Ľڵ�
		head->next->next = tmpNode;
	}
}


int main(){

	LinkList *list = Init();
	Back_Insert(list, 1);
	Back_Insert(list, 2);
	Back_Insert(list, 3);
	Back_Insert(list, 4);
	Back_Insert(list, 5);

	PrintLink(list,print_link);

	ReverseLink(list, 1,  4);

	PrintLink(list, print_link);

	// �ͷ�����
	FreeSpace(list);

	system("pause");
	return 0;
}
