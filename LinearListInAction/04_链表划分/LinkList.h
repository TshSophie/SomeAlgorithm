#include<stdio.h>
#include<stdlib.h>

typedef struct LinkNode{

	void *data; // ������
	struct LinkNode *next; // ָ����

}LinkNode;

typedef struct LinkList{
	
	LinkNode *head; // ͷ�ڵ�
	int size; // ������

}LinkList;

// ����ָ��
typedef  void(*PRINT_LINK)(void *);

// �����ʼ��
LinkList * Init();

// ��ĳ��λ�ò���ڵ�
void Insert(LinkList * list, int pos, void* data);

// ͷ��
void Front_Insert(LinkList * list, void* data);

//β��
void Back_Insert(LinkList * list, void* data);


// ɾ��ĳ�ڵ�
void Delete(LinkList * list, int pos);

// ���ص�һ���ڵ��ֵ
void * Front(LinkList * list);

// ����������
int Length(LinkList *list);

// ��ӡ����
void PrintLink(LinkList *list, PRINT_LINK print);

// �ͷ�����
void FreeSpace(LinkList * list);




