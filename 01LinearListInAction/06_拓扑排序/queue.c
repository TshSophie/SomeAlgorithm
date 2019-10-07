#include<stdio.h>
#include"queue.h"

// ��ʼ������
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

// ���ٶ���
void DestroyQueue(Queue *queue){
	while (IsEmptyQueue(queue))
	{
		PopQueue(queue);
	}
	queue->size = 0;
	free(queue);
}

// ����Ԫ��
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

// ��ȡ���г���
int GetSizeOfQueue(Queue *queue){
	return queue->size;
}

// ��ȡ��ͷԪ��
void *FrontQueue(Queue *queue){
	
	return queue->head->data;
}

// ������ͷԪ��
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

// �ж϶����Ƿ�Ϊ��
int IsEmptyQueue(Queue *queue){
	
	return queue->size > 0 ? 1 : 0;
}