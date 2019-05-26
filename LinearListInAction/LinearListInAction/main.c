/********************************************************************
��Ŀ������
�������������ֱ��ʾ�����Ǹ����������ǵ���������洢�������У���ÿ���ڵ�ֻ�洢һ�����֣�
�����������ĺͣ����ҷ��غ͵������ͷָ�롣
��:
	 ���룺2->4->3,5->6->4
     �����7->0->8

	 ������˳��Ϊ ��λʮλ��λ...

*********************************************************************/
#include<stdio.h>
#include"LinkList.h"

void print_link(void *data){	
	int *p = (int*)data;
	printf("%d -> ", data);
}

void test(){
	// ��ʼ������
	LinkList*list = Init();
	// ����ڵ�
	Insert(list, 0, 1);
	Insert(list, 0, 2);
	Insert(list, 0, 3);

	// ��ӡ�ڵ�
	PrintLink(list, print_link);

	// ɾ���ڵ�
	Delete(list, 0);

	// ɾ����һ���ڵ�
	printf("\nɾ����0���ڵ㣺\n");

	// ��ӡ�ڵ�
	PrintLink(list, print_link);

	// ������	
	printf("\nlen = %d\n", Length(list));

	// �ͷ�����
	FreeSpace(list);
}

LinkList*Add(LinkList *list1,LinkList *list2){

    int maxLength = list1->size > list2->size ? list1->size : list2->size;
	int minLength = list1->size < list2->size ? list1->size : list2->size;

	// ��ʼ��������
	LinkList *newList = Init();	
	/*
	 ���룺2->4->3 , 5->6->4
     �����7->0->8
	 ������˳��Ϊ ��λʮλ��λ...	
	*/
	LinkNode *currentNode1 = list1->head->next;
	LinkNode *currentNode2 = list2->head->next;
	LinkNode *currentNewNode = newList->head;
	int carry = 0,current = 0; // ��λλ,��λ
	int temp = minLength;
	
	while (temp--)
	{				
		current = 0;
		// �½ڵ�
		LinkList *newNode = (LinkNode *)malloc(sizeof(LinkNode));
		int data1 = currentNode1->data;
		int data2 = currentNode2->data;
		int sum = data1 + data2 + carry;

		// ��λ����
		carry = sum / 10;	// 13/10 = 1 , 9/10=0
		current = sum % 10; // 13%10 = 3 , 9%10=9

		// ����ֵ��������		
		Back_Insert(newList, current);

		// ָ����һ���ڵ�
		currentNode1 = currentNode1->next;
		currentNode2 = currentNode2->next;
	}

	// �����������ĳ��Ȳ��Գƣ���ʣ��Ľڵ㴮��������
	int more = maxLength - minLength;
	LinkNode *currentNode = list1->size > list2->size ? currentNode1 : currentNode2;
	while (more--)
	{		
		// �½ڵ�
		LinkList *newNode = (LinkNode *)malloc(sizeof(LinkNode));
		
		// ����ֵ��������
		Back_Insert(newList, currentNode->data);
		
		// ָ����һ���ڵ�
		currentNode = currentNode->next;
	}

	return newList;
}

int main(){

	test();
	system("pause");
	return 0;
}

int main1()
{	
	LinkList *list1 = Init();
	LinkList *list2 = Init();
	// ����ڵ�
	Back_Insert(list1, 4);
	Back_Insert(list1, 9);
	Back_Insert(list1, 0);
	Back_Insert(list1, 4);
	Back_Insert(list1, 7);
	Back_Insert(list1, 1);


	Back_Insert(list2, 1);
	Back_Insert(list2, 7);
	Back_Insert(list2, 1);
	Back_Insert(list2, 5);
	Back_Insert(list2, 5);
	Back_Insert(list2, 4);
	Back_Insert(list2, 2);
	Back_Insert(list2, 8);

	PrintLink(list1, print_link);
	PrintLink(list2, print_link);

	// �������
	LinkList *resLink = Add(list1, list2);	
	
	// ��ӡ���
	PrintLink(resLink, print_link);


	// �ͷ�����
	FreeSpace(list1);
	FreeSpace(list2);
	FreeSpace(resLink);

	system("pause");
	return 0;
}

