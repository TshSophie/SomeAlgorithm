/********************************************************************
	给定一个链表，翻转该链表从m到n的位置。要求直接翻转而非申请新空间。
	如给定 1->【2->3->4】->5，m=2，n=4 返回 1->【4->3->2】->5。
	假定给出的参数满足：1<=m<=n<=链表长度	
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
	LinkNode *head = list->head; // 头指针
	int start = m - 1;
	while (start--) // 空转m-1次
	{
		head = head->next;  // 找到指向翻转段的那个节点
	}

	LinkNode *preNode = head->next; // 翻转段需要翻转节点的上一个节点
	LinkNode *curNode = preNode->next; // 翻转段需要翻转的节点

	// 开始翻转
	int times = n - m; // 翻转n-m次
	while (times--)
	{
		// 缓存当前head指向的节点
		LinkNode * tmpNode = head->next;

		// 把当前节点插入到头部
		head->next = curNode;

		// 把指向当前节点的指针指向当前节点的下一个节点
		preNode->next = curNode->next;

		// curNode指向下一个节点
		curNode = curNode->next; 

		// 把当前节点指向缓存的节点
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

	// 释放链表
	FreeSpace(list);

	system("pause");
	return 0;
}
