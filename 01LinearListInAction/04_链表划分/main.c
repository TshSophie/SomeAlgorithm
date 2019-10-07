/*
	��Ŀ������
	����һ�������һ��ֵX���������ֳ��������֣�ʹ�û��ֺ�С��X�Ľڵ���ǰ�����ڵ���X�Ľڵ��ں�
	������������Ҫ����ԭ�����еĳ���˳��
	�磺
		�������� 1->4->3->2->5->2 �� X = 3
			��벿�֣�1 2 2 
			�Ұ벿�֣�4 3 5
	    ���� 1->2->2->4->3->5
*/
#include<stdio.h>
#include"LinkList.h"
void print_link(void *data){
	int *p = (int*)data;
	printf("%d -> ", data);
}


void DividLinkList(LinkList *list, void *X){

	LinkNode *currentNode = list->head->next;

	LinkNode *left = malloc(sizeof(LinkNode)); // ���ͷ�ڵ�
	LinkNode *right = malloc(sizeof(LinkNode)); // �ұ�ͷ�ڵ�

	LinkNode *leftC = left; 
	LinkNode *rightC = right;

	while (currentNode != NULL)
	{
		if (currentNode->data < X)
		{
			leftC->next = currentNode;
			leftC = leftC->next;
		}
		else
		{
			rightC->next = currentNode;
			rightC = rightC->next;
		}
		currentNode = currentNode->next;
	}

	// ��������
	leftC->next = right->next;

	rightC->next = NULL;

	list->head->next = left->next;

	free(left);
	free(right);
}

int main(){

	LinkList *list = Init();
	Back_Insert(list, 1);
	Back_Insert(list, 4);
	Back_Insert(list, 3);
	Back_Insert(list, 2);
	Back_Insert(list, 5);
	Back_Insert(list, 2);

	PrintLink(list, print_link);

	DividLinkList(list, 3);
	
	PrintLink(list, print_link);

	// �ͷ�����
	FreeSpace(list);
	system("pause");
	return 0;
}