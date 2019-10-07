#include"LinkList.h"

// 链表初始化
LinkList * Init(){
	LinkList *list = (LinkList *)malloc(sizeof(LinkList));	
	// 初始化链表大小
	list->size = 0;

	// 初始化头结点
	list->head = (LinkNode *)malloc(sizeof(LinkNode));
	list->head->data = NULL;
	list->head->next = NULL;

	return list;
}

// 在某个位置插入节点
void Insert(LinkList * list, int pos, void* data){
	// 找到该节点位置
	LinkNode *currentNode = list->head;
	// 给新节点分配空间
	LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
	newNode->data = data;	
	while (pos--)
	{
		currentNode = currentNode->next; // 移动节点
	}
	
	// 将新节点的指针指向下一个节点
	newNode->next = currentNode->next;

	// 将当前节点的指针指向新节点
	currentNode->next = newNode;
	
	list->size++;
	
	// 返回链表
	return list;
}

// 头插
void Front_Insert(LinkList * list, void* data){

	Insert(list, 0, data);
}

//尾插
void Back_Insert(LinkList * list, void* data){
	
	Insert(list, list->size, data);

}



// 删除某节点
void Delete(LinkList * list, int pos){

	if (list == NULL)
	{
		return;
	}

	if (pos < 0 || pos >= list->size)
	{
		return;
	}

	// 找到该节点位置
	LinkNode *currentNode = list->head;
	while (pos--)
	{
		currentNode = currentNode->next; // 移动节点
	}
	// 缓存要删除的节点
	LinkNode *tempNode = currentNode->next;
	// 将当前节点指向下下个节点
	currentNode->next = tempNode->next;
	// 释放节点
	free(tempNode);
	// 链表长度减1
	list->size--;
}

// 返回第一个节点的值
void * Front(LinkList * list){

	return list->head->next->data;
}

// 返回链表长度
int Length(LinkList *list){	
	
	return list->size;
}


// 打印链表
void PrintLink(LinkList *list, PRINT_LINK print){
	LinkNode *currentNode = list->head->next;
	int len = list->size;
	while (len--)
	{
		print(currentNode->data);
		currentNode = currentNode->next;
	}
	printf("\n");
}


// 释放链表
void FreeSpace(LinkList * list){

	// 首节点
	LinkNode *currentNode = list->head;
	while (currentNode != NULL)
	{
		// 缓存下一个节点
		LinkNode *tempNode = currentNode->next;
		// 释放当前节点
		free(currentNode);
		currentNode = tempNode;
	}
	list->size = 0;
	free(list);	
}
