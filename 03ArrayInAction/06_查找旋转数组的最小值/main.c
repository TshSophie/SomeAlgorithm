/*
	假定一个排序数组以某个未知元素为支点做了旋转，如：原数组0 1 2 4 5 6 7旋转后得到 4 5 6 7 0 1 2
	请找出旋转后数组的最小值。假定数组中没有重复数字

	解决方案：
	以升序数组为例：
	分析问题的特点，旋转到末尾的那一段元素一定是比未旋转的那段元素都要小，可以采用二分的思想:
	设首为 start ， 尾为 end，中间则是 mid = (start + end)/2
	如果 
	   - array[mid] > array[end]: 说明现在的mid是落在未旋转段上的，可以在mid~end段去寻找，即让start = mid
	   - array[mid] < array[end]：说明现在的mid是落在未旋转段上的，可以在start~mid段去寻找，即让end = mid	

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






