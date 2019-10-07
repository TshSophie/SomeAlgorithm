#include<iostream>
using namespace std;

/*
	��������:
	����һ���������飬�жϸ��������޿�����һ�ö������������������Ľ�����ٶ�������û���ظ�Ԫ�ء�

	���������
	������������Ϊ������������ô��֪������������һ����С�ڸ��ڵ㣬��������һ���Ǵ��ڸ��ڵ�ġ�
	���ǿ��������������жϣ�
	�ٶ����ĺ�����������ȷ����ô���У����һ��Ԫ��һ���Ǹ��ڵ㣬����������ڵ�ȥ�����зֳ��������룬
	ʹ�����εĽڵ㶼С�ڸ��ڵ����Ұ�εĽڵ㶼���ڸ��ڵ㣬������������Ļ��֣���ô�ú������д��ڣ����򲻴��������ĺ������С�
*/

bool CheckBackOrder(const int *list,int size){
	if (size <= 1)
	{
		return true;
	}
	int root = list[size - 1]; // �����������һ��Ԫ��һ��Ϊ���ڵ�
	int nLeft = 0;
	while (nLeft < size-1) 
	{
		if (list[nLeft] > root)
		{
			break;
		}
		nLeft++;
	}

	int nRight = size - 2;
	while(nRight >= 0)
	{
		if (list[nRight] < root)
		{
			break;
		}
		nRight--;
	}

	// ����������ַ��϶�����������ô�����ǵ�ָ������ֻ���һ����λ
	if (nRight != nLeft-1)
	{
		return false;
	}

	// ��������������
	return CheckBackOrder(list, nLeft) && CheckBackOrder(list + nLeft, size - nLeft - 1);
}

int main()
{

	int list[] = { 1, 2, 5, 4, 3 };
	bool b = CheckBackOrder(list, sizeof(list) / sizeof(int));
	cout <<( b? "����ȷ�ĺ����������" : "������ȷ�ĺ����������") << endl;
	system("pause");
	return 0;
}