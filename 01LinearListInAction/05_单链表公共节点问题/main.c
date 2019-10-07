/*
	问题描述：
	 给定两个单向链表，计算两个链表的第一个公共节点，若没有公共节点，返回空。
*/

#include<stdio.h>
#include"LinkList.h"

LinkNode *CommonNode(LinkList *list1, LinkList *list2){

	int len1 = list1->size;
	int len2 = list2->size;
	int min = len1 < len2 ? len1 : len2;
	int max = len1 > len2 ? len1 : len2;
	
	LinkNode *longL = len1 > len2 ? list1->head->next : list2->head->next;
	LinkNode *shortL = len1 < len2 ? list1->head->next : list2->head->next;

	int tmp = max - min;
	while (tmp--)
	{
		longL = longL->next;
	}

	while (min--)
	{
		if (longL->data == shortL->data)
		{
			return longL;
		}
		longL = longL->next;
		shortL = shortL->next;
	}

	return NULL;
}

int main()
{
	LinkList *list1 = Init();
	LinkList *list2 = Init();

	Back_Insert(list1, 1);
	Back_Insert(list1, 4);
	Back_Insert(list1, 3);
	Back_Insert(list1, 4);
	Back_Insert(list1, 5);

	Back_Insert(list2, 9);
	Back_Insert(list2, 3);
	Back_Insert(list2, 4);
	Back_Insert(list2, 5);


	LinkNode *node = CommonNode(list1, list2);

	if (node!=NULL)
	{
		printf("node = %d\n", node->data);
	}
	else
	{
		printf("node = NULL\n");
	}

	system("pause");
	return 0;
}