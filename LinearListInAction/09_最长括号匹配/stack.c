#include<stdio.h>
#include"stack.h"

// ��ʼ��ջ
Stack *InitStack(){
	Stack *stack = malloc(sizeof(Stack));
	stack->head = NULL;
	stack->size = 0;

	return stack;
}

// ����ջ
void DestroyStack(Stack *stack){
	while (!IsEmptyStack(stack))
	{
		PopStack(stack);
	}
	stack->size = 0;
	free(stack);
}

// ��ȡջ��Ԫ��
void *TopStack(Stack *stack){
	if (stack->size == 0)
	{
		return NULL;
	}
	return stack->head->data;
}

// ����ջ��Ԫ��
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

// ��ȡջ��С
int GetSizeOfStack(Stack *stack){

	return stack->size;
}

// ��ջ
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

// �ж�ջ�Ƿ�Ϊ��
int IsEmptyStack(Stack *stack){

	return stack->size == 0 ? 1 : 0;
}