/*
	给定一个数组A[0...N-1]，找到从一开始，第一个不在数组中的正整数
	如：3,5,1,2,-3,7,14,8输出4

	最大可能是N-1
*/

int FindMissNumber(int *a, int size)
{
	a--; // 指针前移一位，让序号从1开始
	int i = 1;
	while (i <= size)
	{
		if (a[i] == i){ // 如果当前位值等于序号，则判断下一个
			
			i++;

		} // 如果当前位值小于序号 或者 超过了当前数组的长度 或者 当前位的值等于要交换的那个位置的值的话(即重复元素)
		else if ((a[i] < i) || (a[i]>size) || (a[i] == a[a[i]]) )
		{
			a[i] = a[size]; // 把当前数组末尾元素换过来
			size--;			// 数组长度减-，相当于把当前的元素给删除了
		}
		else
		{
			// 交换值
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