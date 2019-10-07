/*
	�ٶ�һ������������ĳ��δ֪Ԫ��Ϊ֧��������ת���磺ԭ����0 1 2 4 5 6 7��ת��õ� 4 5 6 7 0 1 2
	���ҳ���ת���������Сֵ���ٶ�������û���ظ�����

	���������
	����������Ϊ����
	����������ص㣬��ת��ĩβ����һ��Ԫ��һ���Ǳ�δ��ת���Ƕ�Ԫ�ض�ҪС�����Բ��ö��ֵ�˼��:
	����Ϊ start �� βΪ end���м����� mid = (start + end)/2
	��� 
	   - array[mid] > array[end]: ˵�����ڵ�mid������δ��ת���ϵģ�������mid~end��ȥѰ�ң�����start = mid
	   - array[mid] < array[end]��˵�����ڵ�mid������δ��ת���ϵģ�������start~mid��ȥѰ�ң�����end = mid	

*/

int FindMin(int *a, int size)
{
	int start = 0;
	int end = size - 1;
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (a[mid] > a[end])
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return a[start];
}

int main()
{
	int a[] = { 4 ,5, 6, 7, 0, 1, 2 };

	int ret = FindMin(a, sizeof(a) / sizeof(int));

	printf("ret = %d\n", ret);

	system("pause");
	return 0;
}






