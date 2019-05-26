/********************************************************************
题目描述：
给定两个链表，分别表示两个非负整数。它们的数字逆序存储在链表中，且每个节点只存储一个数字，
计算两个数的和，并且返回和的链表的头指针。
如:
	 输入：2->4->3,5->6->4
     输出：7->0->8

	 即输入顺序为 个位十位百位...

*********************************************************************/
#include<stdio.h>
#include"LinkList.h"

void print_link(void *data){	
	int *p = (int*)data;
	printf("%d -> ", data);
}

void test(){
	// 初始化链表
	LinkList*list = Init();
	// 插入节点
	Insert(list, 0, 1);
	Insert(list, 0, 2);
	Insert(list, 0, 3);

	// 打印节点
	PrintLink(list, print_link);

	// 删除节点
	Delete(list, 0);

	// 删除第一个节点
	printf("\n删除第0个节点：\n");

	// 打印节点
	PrintLink(list, print_link);

	// 链表长度	
	printf("\nlen = %d\n", Length(list));

	// 释放链表
	FreeSpace(list);
}

LinkList*Add(LinkList *list1,LinkList *list2){

    int maxLength = list1->size > list2->size ? list1->size : list2->size;
	int minLength = list1->size < list2->size ? list1->size : list2->size;

	// 初始化新链表
	LinkList *newList = Init();	
	/*
	 输入：2->4->3 , 5->6->4
     输出：7->0->8
	 即输入顺序为 个位十位百位...	
	*/
	LinkNode *currentNode1 = list1->head->next;
	LinkNode *currentNode2 = list2->head->next;
	LinkNode *currentNewNode = newList->head;
	int carry = 0,current = 0; // 进位位,本位
	int temp = minLength;
	
	while (temp--)
	{				
		current = 0;
		// 新节点
		LinkList *newNode = (LinkNode *)malloc(sizeof(LinkNode));
		int data1 = currentNode1->data;
		int data2 = currentNode2->data;
		int sum = data1 + data2 + carry;

		// 进位处理
		carry = sum / 10;	// 13/10 = 1 , 9/10=0
		current = sum % 10; // 13%10 = 3 , 9%10=9

		// 将新值进新链表		
		Back_Insert(newList, current);

		// 指向下一个节点
		currentNode1 = currentNode1->next;
		currentNode2 = currentNode2->next;
	}

	// 如果两条链表的长度不对称，将剩余的节点串进新链表
	int more = maxLength - minLength;
	LinkNode *currentNode = list1->size > list2->size ? currentNode1 : currentNode2;
	while (more--)
	{		
		// 新节点
		LinkList *newNode = (LinkNode *)malloc(sizeof(LinkNode));
		
		// 将新值进新链表
		Back_Insert(newList, currentNode->data);
		
		// 指向下一个节点
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
	// 插入节点
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

	// 链表相加
	LinkList *resLink = Add(list1, list2);	
	
	// 打印结果
	PrintLink(resLink, print_link);


	// 释放链表
	FreeSpace(list1);
	FreeSpace(list2);
	FreeSpace(resLink);

	system("pause");
	return 0;
}

