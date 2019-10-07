#include"LinkList.h"

// �����ʼ��
LinkList * Init(){
	LinkList *list = (LinkList *)malloc(sizeof(LinkList));	
	// ��ʼ�������С
	list->size = 0;

	// ��ʼ��ͷ���
	list->head = (LinkNode *)malloc(sizeof(LinkNode));
	list->head->data = NULL;
	list->head->next = NULL;

	return list;
}

// ��ĳ��λ�ò���ڵ�
void Insert(LinkList * list, int pos, void* data){
	// �ҵ��ýڵ�λ��
	LinkNode *currentNode = list->head;
	// ���½ڵ����ռ�
	LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
	newNode->data = data;	
	while (pos--)
	{
		currentNode = currentNode->next; // �ƶ��ڵ�
	}
	
	// ���½ڵ��ָ��ָ����һ���ڵ�
	newNode->next = currentNode->next;

	// ����ǰ�ڵ��ָ��ָ���½ڵ�
	currentNode->next = newNode;
	
	list->size++;
	
	// ��������
	return list;
}

// ͷ��
void Front_Insert(LinkList * list, void* data){

	Insert(list, 0, data);
}

//β��
void Back_Insert(LinkList * list, void* data){
	
	Insert(list, list->size, data);

}



// ɾ��ĳ�ڵ�
void Delete(LinkList * list, int pos){

	if (list == NULL)
	{
		return;
	}

	if (pos < 0 || pos >= list->size)
	{
		return;
	}

	// �ҵ��ýڵ�λ��
	LinkNode *currentNode = list->head;
	while (pos--)
	{
		currentNode = currentNode->next; // �ƶ��ڵ�
	}
	// ����Ҫɾ���Ľڵ�
	LinkNode *tempNode = currentNode->next;
	// ����ǰ�ڵ�ָ�����¸��ڵ�
	currentNode->next = tempNode->next;
	// �ͷŽڵ�
	free(tempNode);
	// �����ȼ�1
	list->size--;
}

// ���ص�һ���ڵ��ֵ
void * Front(LinkList * list){

	return list->head->next->data;
}

// ����������
int Length(LinkList *list){	
	
	return list->size;
}


// ��ӡ����
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


// �ͷ�����
void FreeSpace(LinkList * list){

	// �׽ڵ�
	LinkNode *currentNode = list->head;
	while (currentNode != NULL)
	{
		// ������һ���ڵ�
		LinkNode *tempNode = currentNode->next;
		// �ͷŵ�ǰ�ڵ�
		free(currentNode);
		currentNode = tempNode;
	}
	list->size = 0;
	free(list);	
}
