排序(Sort)

## 1.冒泡排序(BubbleSort)

### 实现思路(Introduction)

> 这里以降序排列为例子

- 对于n个元素的冒泡排序，分为n-1轮冒泡
- 其中每一轮会通过相邻元素依次进行比较选出最小的那个，并且这个数会被冒泡到无序列表(即本轮待冒泡列表)的末尾
- 相邻元素进行比较时，如果当前数比后一个数小则交换
- 每一轮冒泡结束后即进行下一轮，下一轮的列表即为上一轮冒泡除开末尾已经排列好的元素的列表

![](images\BubbleSort.png)

### C语言实现

```c
#include<stdio.h>

void Swap(int *a,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(int *arr, int len)
{
	for (int j = len - 1; j > 0; j--)
	{
		for (int i = 0; i < j; i++)
		{
			if (arr[i] < arr[i+1])
			{
				Swap(&arr[i], &arr[i + 1]);
			}
		}
	}
}

void PrintArray(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("arr[%d]:%d    ", i, arr[i]);
	}
	printf("\n");
}
int main()
{
	int num[] = { 5, 8, 4, 7};
	// print before sort
	printf("before sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	// sort
	BubbleSort(num, sizeof(num) / sizeof(num[0]));

	// print after sort
	printf("after sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	system("pause");
	return 0;
}
```

### Go语言实现

```go
package main

import "fmt"

func BubbleSort(arr []int) {
	leng := len(arr)
	for j := leng - 1; j > 0; j-- {
		for i := 0; i < j; i++ {
			if arr[i] < arr[i+1] {

				arr[i], arr[i+1] = arr[i+1], arr[i]
			}
		}
	}
}
func main() {
	arr := []int{5, 8, 4, 7}
	fmt.Println(arr)
	BubbleSort(arr)
	fmt.Println(arr)
}

```





## 2.改进版冒泡排序(BubbleSort)

### 实现思路

- 基本思路同基本的冒泡排序一样
- 通过添加全局标识符变量flag记录序列是否已经有序，如已经有序则不再进行下一轮外层遍历
- 因此在某些情况下(序列较有序)可减少循环次数。

![](images\Improved_BubbleSort.png)

### C语言实现

```c
#include<stdio.h>
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void ImprovedBubbleSort(int *arr, int len)
{
    int flag = 1;
	for (int j = len - 1; j > 0 && flag; j--)
	{
		flag = 0;
		for (int i = 0; i < j; i++)
		{
			if (arr[i] < arr[i + 1])
			{
				flag = 1;
				Swap(&arr[i], &arr[i + 1]);
			}
		}
	}
}

void PrintArray(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("arr[%d]:%d    ", i, arr[i]);
	}
	printf("\n");
}

int main()
{
	int num[] = { 5, 8, 7,3};

	// print before sort
	printf("before sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	// sort
	ImprovedBubbleSort(num, sizeof(num) / sizeof(num[0]));

	// print after sort
	printf("after sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	system("pause");
	return 0;
}
```



### Go语言实现

```go
package main
import "fmt"
func ImprovedBubbleSort(arr []int) {
	flag := true
	leng := len(arr)
	for j := leng - 1; j > 0 && flag; j-- {
		flag = false
		for i := 0; i < j; i++ {
			if arr[i] < arr[i+1] {
				flag = true
				arr[i], arr[i+1] = arr[i+1], arr[i]
			}
		}
	}
}
func main() {
	arr := []int{5, 8, 7, 3}
	fmt.Println(arr)
	ImprovedBubbleSort(arr)
	fmt.Println(arr)
}

```



## 3.选择排序(select sort)

### 实现思路(Introduction)

- 与冒泡排序有点类似，每一轮排序会选出最小或最大的那个数，将其放入有序序列中
- 不同之处在与，冒泡排序是相邻元素间逐次进行比较，而选择排序则是与上一次选出的那个最小或最大元素进行比较，从而选出每轮的最小或最大元素



![](images\selectSort.png)

### C语言实现

```c
#include <stdio.h>
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void PrintArray(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("arr[%d]:%d    ", i, arr[i]);
	}
	printf("\n");
}

void SelectSort(int *arr, int length)
{
	int min = 0;

	for (int i = 0; i < length; i++)
	{
		min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}

		if (min != i) // 如果有更小的值出现则交换它们
		{
			Swap(&arr[min], &arr[i]); // 交换
		}
	}
}


int main()
{
	int num[] = {3,5,1,6 };

	// print before sort
	printf("before sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	// sort
	SelectSort(num, sizeof(num) / sizeof(num[0]));

	// print after sort
	printf("after sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	system("pause");
	return 0;

}
```



### Go语言实现

```go
package main

import "fmt"

func SelectSort(arr []int) {
	length := len(arr)
	min := 0
	for i := 0; i < length; i++ {
		min = i
		for j := i + 1; j < length; j++ {
			if arr[min] > arr[j] {
				min = j
			}
		}
		if min != i {
			arr[min], arr[i] = arr[i], arr[min]
		}
	}

}

func main() {
	arr := []int{3, 5, 1, 6}

	fmt.Println(arr)

	SelectSort(arr)

	fmt.Println(arr)
}

```



## 4.插入排序(InsertSort)

### 实现思路(Introduction)（升序）

【1】将一组序列分成两拨，一拨为有序序列，另一拨为待排序的序列，
【2】可以设第一个元素为有序序列，第二个元素及之后的为无序序列
【3】将无序序列的首元素与有序序列的首元素进行比较，若小于，则将该首元素缓存
【4】并用缓存元素与有序序列中的元素从右至左依次进行比较，碰到大于自己的则将其往后挪一个位置， 碰到小于等于自己的则结束比较将缓存值插入结束位置的后一个位置
【5】此时一轮比较结束，无序序列的首元素下标+1，继续下一轮比较



> 插入排序：
> 在什么情况下效率最高？
> 1、如果序列基本有序的情况下
> 2、数据序列比较少
> 插入排序总结
> 稳定性：
> 插入排序是稳定的排序算法
> 插入排序效率：O（n²）

![](images\InsertSort.png)



### C语言实现

```c
#include<stdio.h>
void PrintArray(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("arr[%d]:%d    ", i, arr[i]);
	}
	printf("\n");
}


// 升序
void InsertSort(int *arr, int length)
{
	// 假定第一个元素为有序序列，而其后的元素为无序序列
	for (int i = 1; i < length; i++)
	{
		if (arr[i] < arr[i - 1]) //  从无序序列中选出一个比有序序列尾元素小的来
		{
			int temp = arr[i];
			int j;
			for (j = i - 1; j >= 0 && temp < arr[j]; j--) // 将选出的元素放入有序序列合适的位置
			{
				arr[j + 1] = arr[j]; // 向右边移动元素
			}
			// 将元素放入有序序列
			arr[j + 1] = temp;
		}
	}
}

int main()
{
	int num[] = { 5,3,6,7,2 };

	// print before sort
	printf("before sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	// sort
	InsertSort(num, sizeof(num) / sizeof(num[0]));

	// print after sort
	printf("after sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	system("pause");
	return 0;

}
```



### Go语言实现

```go
package main

import "fmt"

func InsertSort(arr []int) {
	length := len(arr)
	for i := 1; i < length; i++ {
		if arr[i] < arr[i-1] {
			temp := arr[i]
			var j int
			for j = i - 1; j >= 0 && arr[j] > temp; j-- {
				arr[j+1] = arr[j]
			}
			arr[j+1] = temp
		}
	}
}

func main() {
	arr := []int{5, 3, 6, 7, 2}

	fmt.Println(arr)

	InsertSort(arr)

	fmt.Println(arr)
}

```



## 5.希尔排序(ShellSort)

### 实现思路(Introduction)

**希尔排序的实质就是分组插入排序**，该方法又称缩小增量排序。

**先将整个待排元素序列分割成若干个子序列**（由相隔某个“增量”的元素组成的）分别进行直接插入排序，然后依次缩减增量再进行排序，待整个序列中的元素基本有序（增量足够小）时，再对全体元素进行一次直接插入排序。因为**直接插入排序在元素基本有序的情况下（接近最好情况），效率是很高的**，因此希尔排序在时间效率上比前前面几种方法有较大提高。

![](images\ShellSort.png)

### C语言实现

```c
#include<stdio.h>

void PrintArray(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("arr[%d]:%d    ", i, arr[i]);
	}
	printf("\n");
}

void ShellSort(int *arr, int length)
{

	int increasement = length;

	do{

		increasement = increasement / 3 + 1; // 分组算法

		for (int k = 0; k < increasement; k++)
		{
			// 插入排序
			for (int i = increasement + k; i < length; i += increasement)
			{
				if (arr[i] > arr[i - increasement]) // 从无序列表找较大的元素
				{
					int temp = arr[i];
					// 在有序列表里找一个合适的位置(直到找不到比自己还大的元素)
					int j;
					for (j = i - increasement; j >= 0 && temp > arr[j]; j -= increasement) 
					{
						arr[j + increasement] = arr[j]; // 向右边挪动元素
					}
					
					arr[j + increasement] = temp; // 将元素插入有序列表
					
				}
			}
		}

	} while (increasement > 1);

}

int main()
{

	//int num[] = { 5,9,4,7,3,6 };
	int num[] = { 5,9,4,7,3,6,19,6,3,4,2,99,100,45,32,2,1,8 };

	// print before sort
	printf("before sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	// sort
	ShellSort(num, sizeof(num) / sizeof(num[0]));

	// print after sort
	printf("after sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	system("pause");
	return 0;
}

```



### Go语言实现

```go
package main

import "fmt"

func ShellSort(arr []int) {
	length := len(arr)
	increasement := length
	for {

		increasement = increasement/3 + 1

		for k := 0; k < increasement; k++ {
			for i := increasement + k; i < length; i += increasement {
				if arr[i] > arr[i-increasement] {
					temp := arr[i]
					var j int
					for j = i - increasement; j >= 0 && temp > arr[j]; j -= increasement {
						arr[j+increasement] = arr[j]
					}
					arr[j+increasement] = temp
				}
			}
		}

		if increasement <= 1 {
			break
		}

	}
}

func main() {
	arr := []int{5, 9, 4, 7, 3, 6, 19, 6, 3, 4, 2, 99, 100, 45, 32, 2, 1, 8}

	fmt.Println(arr)

	ShellSort(arr)

	fmt.Println(arr)
}

```



## 6.快速排序(QuickSort)

快速排序是 C.R.A.Hoare 于 1962 年提出的**一种划分交换排序**。 它**采用了一种分治的策略**，通常称其为分治法(Divide-and-ConquerMethod)。

分治法基本思想

- 先从数列中取出一个数作为基准数（枢轴）。
-  **分区过程将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。**(升序)


- 再对左右区间重复第二步，直到各区间只有一个数。
- 其效果就是要将一个大的序列拆分成小序列，对小序列进行排序，一旦小序列排序完成了，大序列的排序也就完成了

![](D:\GitHub\SomeAlgorithm\sort\images\QuickSort.png)

### C语言实现

```c
#include<stdio.h>
void PrintArray(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("arr[%d]:%d    ", i, arr[i]);
	}
	printf("\n");
}
void QuickSort(int *arr,int start,int end)
{
	// 起始位置
	int i = start;
	int j = end;

	int temp = arr[i]; //设基准数为第一个元素
	if (i < j)
	{
		while (i < j)
		{
			// 从右往左找小于基准数的
			while (i < j && arr[j] > temp)
			{
				j--;
			}
			// 找到了就放在i位置
			if (i < j)
			{
				arr[i] = arr[j];
				i++;
			}

			// 从左往右找大于基准数的
			while (i < j && arr[j] < temp)
			{
				i++;
			}
			// 找到了就放在j位置
			if (i < j)
			{
				arr[j] = arr[i];
				j--;
			}
		}

		arr[i] = temp;

		// 对左半部分进行排序
		QuickSort(arr, start, i - 1);
		// 对右半部分进行排序
		QuickSort(arr, i + 1, end);


	}
}

int main()
{

	//int num[] = { 5,9,4,7,3,6 };
	int num[] = { 5, 9, 4, 7, 3, 6, 19, 6, 3, 4, 2, 99, 100, 45, 32, 2, 1, 8 };

	// print before sort
	printf("before sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	// sort
	QuickSort(num, 0, (sizeof(num) / sizeof(num[0]))-1);

	// print after sort
	printf("after sort:\n");
	PrintArray(num, sizeof(num) / sizeof(num[0]));

	system("pause");
	return 0;
}

```



### Go语言实现

```go
package main

import "fmt"

func QuickSort(arr []int, start, end int) {
	i := start
	j := end
	if i < j {
		temp := arr[i]

		for i < j {
			// from left to right to find greater
			for i < j && temp < arr[j] {
				j--
			}
			if i < j {
				arr[i] = arr[j]
				i++
			}

			// from right to left to find smaller
			for i < j && temp > arr[i] {
				i++
			}

			if i < j {
				arr[j] = arr[i]
				j--
			}
		}

		arr[i] = temp

		// left part
		QuickSort(arr, start, i-1)
		// right part
		QuickSort(arr, i+1, end)
	}
}
func main() {

	arr := []int{5, 9, 4, 7, 3, 6, 19, 6, 3, 4, 2, 99, 100, 45, 32, 2, 1, 8}
	fmt.Println(arr)
	QuickSort(arr, 0, len(arr)-1)
	fmt.Println(arr)

}

```











































