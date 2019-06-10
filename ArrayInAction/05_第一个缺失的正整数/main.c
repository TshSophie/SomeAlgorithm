/*
	����һ������A[0...N-1]���ҵ���һ��ʼ����һ�����������е�������
	�磺3,5,1,2,-3,7,14,8���4

	��������N-1
*/

int FindMissNumber(int *a, int size)
{
	a--; // ָ��ǰ��һλ������Ŵ�1��ʼ
	int i = 1;
	while (i <= size)
	{
		if (a[i] == i){ // �����ǰλֵ������ţ����ж���һ��
			
			i++;

		} // �����ǰλֵС����� ���� �����˵�ǰ����ĳ��� ���� ��ǰλ��ֵ����Ҫ�������Ǹ�λ�õ�ֵ�Ļ�(���ظ�Ԫ��)
		else if ((a[i] < i) || (a[i]>size) || (a[i] == a[a[i]]) )
		{
			a[i] = a[size]; // �ѵ�ǰ����ĩβԪ�ػ�����
			size--;			// ���鳤�ȼ�-���൱�ڰѵ�ǰ��Ԫ�ظ�ɾ����
		}
		else
		{
			// ����ֵ
			int temp = a[i];
			a[i] = a[temp];
			a[temp] = temp;
		}		
	}

	return i;
}

int main()
{
	int a[] = { 3, 5, 1, -2, 9, 8 };

	int ret = FindMissNumber(a, sizeof(a) / sizeof(int));

	printf("ret = %d\n", ret);
	system("pause");
	return 0;
}