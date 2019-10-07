
typedef struct STACKNODE{
	void *data;
	struct STACKNODE *next;

}StackNode;

typedef struct STACK{
	StackNode *head;
	int size;
}Stack;

// 初始化栈
Stack *InitStack();

// 销毁栈
void DestroyStack(Stack *stack);

// 获取栈顶元素
void *TopStack(Stack *stack);

// 弹出栈顶元素
void PopStack(Stack *stack);

// 获取栈大小
int GetSizeOfStack(Stack *stack);

// 入栈
int PushStack(Stack *stack, void *data);

// 判断栈是否为空
int IsEmptyStack(Stack *stack);