/*
	题目描述：
	给定一个链表和一个值X，将链表划分成两个部分，使得划分后小于X的节点在前，大于等于X的节点在后。
	在这两部分中要保持原链表中的出现顺序。
	如：
		给定链表 1->4->3->2->5->2 和 X = 3
			左半部分：1 2 2 
			右半部分：4 3 5
	    返回 1->2->2->4->3->5
*/
#include<stdio.h>
#include"LinkList.h"
void print_link(void *data){
	int *p = (int*)data;
	printf("%d -> ", data);
}


void DividLinkList(LinkList *list, void *X){

	LinkNode *currentNode = list->head->next;

	LinkNode *left = malloc(sizeof(LinkNode)); // 左边头节点
	LinkNode *right = malloc(sizeof(LinkNode)); // 右边头节点

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

	// 连接左右
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

	// 释放链表
	FreeSpace(list);
	system("pause");
	return 0;
}