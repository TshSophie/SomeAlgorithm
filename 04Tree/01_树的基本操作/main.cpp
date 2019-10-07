#include<iostream>
#include"BinaryTree.h"

using namespace std;


// �����������Ĳ��롢���Һ�ɾ���ڵ�
void test1()
{
	// ����������
	BinaryTree bt;

	// ���ɶ�����
	bt._Insert(bt.get(), 15);
	bt._Insert(bt.get(), 5);
	bt._Insert(bt.get(), 3);
	bt._Insert(bt.get(), 12);
	bt._Insert(bt.get(), 16);
	bt._Insert(bt.get(), 20);
	bt._Insert(bt.get(), 23);
	bt._Insert(bt.get(), 13);
	bt._Insert(bt.get(), 18);
	bt._Insert(bt.get(), 10);
	bt._Insert(bt.get(), 6);
	bt._Insert(bt.get(), 7);

	// ���Ҷ�����
	STreeNode *tNode = bt.Find(12);

	if (tNode != NULL)
	{
		cout << "Find:" << tNode->value << endl;
	}
	else
	{
		cout << "Not found!" << endl;
	}

	// ɾ���ڵ�
	bt.Delete(12);
	// ���Ҷ�����
	tNode = bt.Find(12);

	if (tNode != NULL)
	{
		cout << "Find:" << tNode->value << endl;
	}
	else
	{
		cout << "Not found!" << endl;
	}
}

// ���������������
void test2()
{
	// ����������
	BinaryTree bt;

	// ���ɶ�����
	bt._Insert(bt.get(), 15);
	bt._Insert(bt.get(), 5);
	bt._Insert(bt.get(), 3);
	bt._Insert(bt.get(), 12);
	bt._Insert(bt.get(), 16);
	bt._Insert(bt.get(), 20);
	bt._Insert(bt.get(), 23);
	bt._Insert(bt.get(), 13);
	bt._Insert(bt.get(), 18);
	bt._Insert(bt.get(), 10);
	bt._Insert(bt.get(), 6);
	bt._Insert(bt.get(), 7);

	// ������� �ݹ�
	bt.PreOrder(bt.get());
	cout << endl;
	// ������� �ǵݹ�
	bt.PreOrder2();
	cout << endl;

	// ������� �ݹ�
	bt.MidOrder(bt.get());
	cout << endl;
	// ��������� �ݹ�
	bt.MidOrder2();
	cout << endl;
	// ��������� �ݹ�
	bt.MidOrder3();
	cout << endl;

	// ������� �ݹ�
	bt.BackOrder(bt.get());
	cout << endl;
	// ������� �ǵݹ�
	bt.BackOrder2();
	cout << endl;	
}

int main(){

	test2();

	system("pause");
	return 0;
}