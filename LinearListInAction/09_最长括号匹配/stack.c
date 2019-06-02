#include<stdio.h>
#include"stack.h"

// 初始化栈
Stack *InitStack(){
	Stack *stack = malloc(sizeof(Stack));
	stack->head = NULL;
	stack->size = 0;

	return stack;
}

// 销毁栈
void DestroyStack(Stack *stack){
	while (!IsEmptyStack(stack))
	{
		PopStack(stack);
	}
	stack->size = 0;
	free(stack);
}

// 获取栈顶元素
void *TopStack(Stack *stack){
	if (stack->size == 0)
	{
		return NULL;
	}
	return stack->head->data;
}

// 弹出栈顶元素
void PopStack(Stack *stack){
	if (stack->size == 0)
	{
		return;
	}

	StackNode *tempNode = stack->head;
	stack->head = tempNode->next;
	free(tempNode);

	stack->size--;	
}

// 获取栈大小
int GetSizeOfStack(Stack *stack){

	return stack->size;
}

// 入栈
int PushStack(Stack *stack, void *data){

	StackNode *newNode = malloc(sizeof(StackNode));
	newNode->data = data;
	newNode->next = NULL;

	if (stack->size == 0)
	{
		stack->head = newNode;
		stack->size++;
		return 0;
	}

	newNode->next = stack->head;
	stack->head = newNode;

	stack->size++;
	return 0;
}

// 判断栈是否为空
int IsEmptyStack(Stack *stack){

	return stack->size == 0 ? 1 : 0;
}