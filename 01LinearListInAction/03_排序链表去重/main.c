/*
  ��Ŀ1������
  �������������ɾ���ظ�Ԫ�أ�ֻ�����ظ�Ԫ�ص�һ�γ��ֵĽڵ㡣
  �磺
	������2->3->3->5->7->8->8->8->9->9->10
	���أ�2->3->5->7->8->9->10
*/

/*
 ��Ŀ2������
 ��������������������ظ�Ԫ�أ����ظ�Ԫ��ȫ��ɾ��
	 �磺
		������2->3->3->5->7->8->8->8->9->9->10
		���أ�2->5->7->10
*/

/*
	�Ľ��㣬��ʵ���㷨ʱ��������Ҫɾ��ĳ���ڵ�������
	Ŀǰ��ֱ�Ӹ��ݽڵ��indexȥʵ��ɾ���ģ�Ч�ʲ��ߣ����������һ��api���ݽڵ���ɾ��
*/

#include<stdio.h>
#include"LinkList.h"
#define T1

void print_link(void *data){
	int *p = (int*)data;
	printf("%d -> ", data);
}

// ȥ���ظ��ڵ�
void RemoveDuplicateNode(LinkList *list){

	LinkNode * currentNode = list->head->next; 
		
	while (currentNode->next!=NULL)
	{
		// �����һ���ڵ�͵�ǰ�ڵ�����һ����ɾ����һ���ڵ�
		if (currentNode->data == currentNode->next->data)
		{			
			// Delete(list, i+1);
			LinkNode *tempNode = currentNode->next; // �����¸��ڵ�

			currentNode->next = currentNode->next->next;

			list->size--;

			free(tempNode);
		}
		else
		{
			currentNode = currentNode->next;			
		}		
	}
}

// ȥ��ȫ���ظ�Ԫ��
void RemoveAllDuplicateNode(LinkList *list){

	LinkNode * currentNode = list->head->next;

	int i = 0;
	int flag = 0; // flag����Ƿ�����ظ�Ԫ��
	while (currentNode->next!=NULL)
	{		
		// �����һ���ڵ�͵�ǰ�ڵ�����һ����ɾ����һ���ڵ�
		if (currentNode->data == currentNode->next->data)
		{			
			Delete(list, i+1);	
			flag = 1;  // ��Ǵ����ظ�Ԫ��
		}
		else
		{
			currentNode = currentNode->next;
			// �ж��Ƿ�����ظ�Ԫ�أ��ظ�����Լ���ɾ����
			if (flag)
			{				
				Delete(list, i);
				flag = 0;
			}
			else
			{				
				i++;
			}			
		}
	}
}



#ifdef T1
int main()
{
	LinkList *list = Init();
	Back_Insert(list, 2);
	Back_Insert(list, 3);
	Back_Insert(list, 3);
	Back_Insert(list, 5);
	Back_Insert(list, 7);
	Back_Insert(list, 8);
	Back_Insert(list, 8);
	Back_Insert(list, 8);
	Back_Insert(list, 9);
	Back_Insert(list, 9);
	Back_Insert(list, 10);

	PrintLink(list, print_link);
	
	RemoveDuplicateNode(list);

	PrintLink(list, print_link);

	system("pause");
	return 0;
}
#endif



#ifdef T2
int main()
{
	LinkList *list = Init();
	Back_Insert(list, 2);
	Back_Insert(list, 3);
	Back_Insert(list, 3);
	Back_Insert(list, 5);
	Back_Insert(list, 7);
	Back_Insert(list, 8);
	Back_Insert(list, 8);
	Back_Insert(list, 8);
	Back_Insert(list, 9);
	Back_Insert(list, 9);
	Back_Insert(list, 10);

	PrintLink(list, print_link);

	RemoveAllDuplicateNode(list);

	PrintLink(list, print_link);

	// �ͷ�����
	FreeSpace(list);

	system("pause");
	return 0;
}

#endif






