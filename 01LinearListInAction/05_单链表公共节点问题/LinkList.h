#include<stdio.h>
#include<stdlib.h>

typedef struct LinkNode{

	void *data; // 数据域
	struct LinkNode *next; // 指针域

}LinkNode;

typedef struct LinkList{
	
	LinkNode *head; // 头节点
	int size; // 链表长度

}LinkList;

// 函数指针
typedef  void(*PRINT_LINK)(void *);

// 链表初始化
LinkList * Init();

// 在某个位置插入节点
void Insert(LinkList * list, int pos, void* data);

// 头插
void Front_Insert(LinkList * list, void* data);

//尾插
void Back_Insert(LinkList * list, void* data);


// 删除某节点
void Delete(LinkList * list, int pos);

// 返回第一个节点的值
void * Front(LinkList * list);

// 返回链表长度
int Length(LinkList *list);

// 打印链表
void PrintLink(LinkList *list, PRINT_LINK print);

// 释放链表
void FreeSpace(LinkList * list);




