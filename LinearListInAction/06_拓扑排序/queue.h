
typedef struct QUEUENODE{
	void *data;
	struct QUEUENODE *next;
}QueueNode;

typedef struct QUEUE{	
	QueueNode *head;
	QueueNode *end;
	int size;
}Queue;

// ��ʼ������
Queue *InitQueue();

// ���ٶ���
void DestroyQueue(Queue *queue);

// ����Ԫ��
int PushQueue(Queue *queue, void *data);

// ��ȡ���г���
int GetSizeOfQueue(Queue *queue);

// ��ȡ��ͷԪ��
void *FrontQueue(Queue *queue);

// ������ͷԪ��
void PopQueue(Queue *queue);

// �ж϶����Ƿ�Ϊ��
int IsEmptyQueue(Queue *queue);