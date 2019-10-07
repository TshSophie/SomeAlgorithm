/*
  题目1描述：
  给定排序的链表，删除重复元素，只保留重复元素第一次出现的节点。
  如：
	给定：2->3->3->5->7->8->8->8->9->9->10
	返回：2->3->5->7->8->9->10
*/

/*
 题目2描述：
 给定排序的链表，若发现重复元素，则重复元素全部删除
	 如：
		给定：2->3->3->5->7->8->8->8->9->9->10
		返回：2->5->7->10
*/

/*
	改进点，在实现算法时，有遇到要删除某个节点的情况，
	目前是直接根据节点的index去实现删除的，效率不高，建议再添加一个api根据节点来删除
*/

#include<stdio.h>
#include"LinkList.h"
#define T1

void print_link(void *data){
	int *p = (int*)data;
	printf("%d -> ", data);
}

// 去除重复节点
void RemoveDuplicateNode(LinkList *list){

	LinkNode * currentNode = list->head->next; 
		
	while (currentNode->next!=NULL)
	{
		// 如果下一个节点和当前节点数据一样则删除下一个节点
		if (currentNode->data == currentNode->next->data)
		{			
			// Delete(list, i+1);
			LinkNode *tempNode = currentNode->next; // 缓存下个节点

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

// 去除全部重复元素
void RemoveAllDuplicateNode(LinkList *list){

	LinkNode * currentNode = list->head->next;

	int i = 0;
	int flag = 0; // flag标记是否存在重复元素
	while (currentNode->next!=NULL)
	{		
		// 如果下一个节点和当前节点数据一样则删除下一个节点
		if (currentNode->data == currentNode->next->data)
		{			
			Delete(list, i+1);	
			flag = 1;  // 标记存在重复元素
		}
		else
		{
			currentNode = currentNode->next;
			// 判断是否存在重复元素，重复则把自己给删除了
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

	// 释放链表
	FreeSpace(list);

	system("pause");
	return 0;
}

#endif






