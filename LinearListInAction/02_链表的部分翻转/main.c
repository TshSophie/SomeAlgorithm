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

void ReverseLiink(LinkList *list,int m,int n){

	if (m >= n){
		printf("n must greater than m\n");
		return;
	}	

	LinkNode *currentNode = list->head->next; // 头节点
	int start = m;
	while (start--)
	{
		currentNode = currentNode->next;
	}
	// 开始"头"插入后面n-m个节点
	int tmp = n - m;
	int i = 0;
	while (tmp--)
	{
		i++;
		// 缓存节点数据
		void * tmp = currentNode->data;		
		// 插入节点
		Insert(list, m - 1, tmp);			
		// 下一个节点
		currentNode = currentNode->next;
	}
	// 删除多余的节点
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

	// 释放链表
	FreeSpace(list);

	system("pause");
	return 0;
}
