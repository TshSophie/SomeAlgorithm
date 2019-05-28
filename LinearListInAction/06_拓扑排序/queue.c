#include<stdio.h>
#include"queue.h"

// 初始化队列
Queue *InitQueue(){
	Queue *queue = malloc(sizeof(Queue));
	if (queue==NULL)
	{
		return NULL;
	}

	queue->head = NULL;
	queue->end = NULL;
	queue->size = 0;

	return queue;
}

// 销毁队列
void DestroyQueue(Queue *queue){
	while (IsEmptyQueue(queue))
	{
		PopQueue(queue);
	}
	queue->size = 0;
	free(queue);
}

// 插入元素
int PushQueue(Queue *queue, void *data){
	QueueNode *newNode = malloc(sizeof(QueueNode));
	newNode->data = data;
	newNode->next = NULL;

	if (queue->size==0)
	{
		queue->end = newNode;
		queue->head = newNode;
		queue->size++;
		return 0;
	}

	newNode->next = queue->end;
	queue->end = newNode;
	queue->size++;

	return 0;
}

// 获取队列长度
int GetSizeOfQueue(Queue *queue){
	return queue->size;
}

// 获取队头元素
void *FrontQueue(Queue *queue){
	
	return queue->head->data;
}

// 弹出队头元素
void PopQueue(Queue *queue){
	
	if (queue->size == 1)
	{
		free(queue->head);
		queue->head = NULL;
		queue->end = NULL;
		queue->size--;
		return;
	}

	QueueNode *prevNode = queue->end;
	QueueNode *currentNode = prevNode->next;

	while (currentNode->next != NULL)
	{	
		prevNode = currentNode;
		currentNode = currentNode->next;
	}
	free(currentNode);
	prevNode->next = NULL;
	queue->head = prevNode;
	queue->size--;
	return;
}

// 判断队列是否为空
int IsEmptyQueue(Queue *queue){
	
	return queue->size > 0 ? 1 : 0;
}