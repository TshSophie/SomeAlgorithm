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

void ReverseLiink(LinkList *list,int m,int n){

	if (m >= n){
		printf("n must greater than m\n");
		return;
	}	

	LinkNode *currentNode = list->head->next; // ͷ�ڵ�
	int start = m;
	while (start--)
	{
		currentNode = currentNode->next;
	}
	// ��ʼ"ͷ"�������n-m���ڵ�
	int tmp = n - m;
	int i = 0;
	while (tmp--)
	{
		i++;
		// ����ڵ�����
		void * tmp = currentNode->data;		
		// ����ڵ�
		Insert(list, m - 1, tmp);			
		// ��һ���ڵ�
		currentNode = currentNode->next;
	}
	// ɾ������Ľڵ�
	int more = n - m;	
	while (more--)
	{
		Delete(list, n);
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

	ReverseLiink(list, 1,  4);

	PrintLink(list, print_link);

	// �ͷ�����
	FreeSpace(list);

	system("pause");
	return 0;
}
