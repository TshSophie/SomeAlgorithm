/*
	问题描述：
	给定N个数，称出现次数最多个数为众数；若某众数出现的次数大于N/2,称该众数为绝对众数
	 - 如： A={1,2,1,3,2}中，1和2都是众数，但都不是绝对众数。
	 - 如： A={1,2,1,3,1}中，1是绝对众数。
	已知给定的N个整数存在绝对众数，以最低的时空复杂度计算该绝对众数。

	解决方案：
	 由绝对众数的特点可知，绝对众数是过半的数，因此可推知：
	 删除数组中两个不同的数，绝对众数不变：
	 - 若两个数中有一个是绝对众数，则剩余的N-2个数中，绝对众数仍然大于(N-2)/2;
	 - 若两个数中没有绝对众数，显然不影响绝对众数。

	 算法操作：
	 - 记m为候选绝对众数，出现次数为count，初始化为0。
	 - 遍历数组A：
		+ 若count==0，则m=A[i]
		+ 若count!=0且m!=A[i]，则同时删掉m和A[i]
		+ 若count!=且m==A[i]，则count++
*/


// 求绝对众数
int Mode(int *a, int size)
{
	int count = 0;
	int m = a[0];
	for (int i = 0; i < size; i++)
	{
		if (count == 0) // 更新
		{
			m = a[i];
			count = 1;
		}
		else if (m != a[i]) // 同时删掉m和A[i]
		{
			count--;
		}
		else if (m == a[i]) // 记录重复的次数
		{
			count++;
		}	
	}
	return m;
}

int main()
{
	int a[] = { 1, 2, 2, 2, 3, 2 };

	int ret = Mode(a,sizeof(a)/sizeof(int));

	printf("mode = %d\n", ret);

	system("pause");
	return 0;
}





