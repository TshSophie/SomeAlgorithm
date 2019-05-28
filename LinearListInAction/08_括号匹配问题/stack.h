
typedef struct STACKNODE{
	void *data;
	struct STACKNODE *next;

}StackNode;

typedef struct STACK{
	StackNode *head;
	int size;
}Stack;

// ��ʼ��ջ
Stack *InitStack();

// ����ջ
void DestroyStack(Stack *stack);

// ��ȡջ��Ԫ��
void *TopStack(Stack *stack);

// ����ջ��Ԫ��
void PopStack(Stack *stack);

// ��ȡջ��С
int GetSizeOfStack(Stack *stack);

// ��ջ
int PushStack(Stack *stack, void *data);

// �ж�ջ�Ƿ�Ϊ��
int IsEmptyStack(Stack *stack);