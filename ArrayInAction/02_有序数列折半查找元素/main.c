/*
	����һ�������������Ԫ�أ����ǿ��Բ��ö��ַ���ʵ�ֲ���
*/

#include<stdio.h>

int SearchInSortArray(int *array,int len,int target)
{
	if (len < 0)
	{
		return -1;
	}
	else if (len == 1)
	{
		return array[0] == target ? 0 : -1;
	}

	int start = 0;
	int end = len - 1;
	int asc = array[0] < array[1] ? 1 : 0;
	while (start <= end)
	{		
		// �۰�
		int middle = (start + end) / 2;
		// ���м��ֵ��
		if (target == array[middle])
		{
			return middle;
		}
		else if (target < array[middle])// ���м��ֵС�������������������еĻ����������
		{		
			if (asc == 1) // ����
			{
				end = middle - 1;
			}
			else
			{
				start = middle + 1;
			}
						
		}
		else // ���м��ֵ�󣬲����������������еĻ������ұ���
		{
			if (asc == 1) // ����
			{
				start = middle + 1;
			}
			else
			{
				end = middle - 1;
			}				
		}
	}

	return -1;
}

int main()
{

	int array[10] = { 10,9,8,7,6,5,4,3,2,1};
	int ret = SearchInSortArray(array, sizeof(array) / sizeof(int), 9);

	printf("target's position = %d\n", ret);

	system("pause");
	return 0;
}