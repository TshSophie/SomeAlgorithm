
typedef struct QUEUENODE{
	void *data;
	struct QUEUENODE *next;
}QueueNode;

typedef struct QUEUE{	
	QueueNode *head;
	QueueNode *end;
	int size;
}Queue;

// 初始化队列
Queue *InitQueue();

// 销毁队列
void DestroyQueue(Queue *queue);

// 插入元素
int PushQueue(Queue *queue, void *data);

// 获取队列长度
int GetSizeOfQueue(Queue *queue);

// 获取队头元素
void *FrontQueue(Queue *queue);

// 弹出队头元素
void PopQueue(Queue *queue);

// 判断队列是否为空
int IsEmptyQueue(Queue *queue);