# 排序(Sort)

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

- 与冒泡排序有点类似，每一轮排序会选出最小或最大的那个数，将其放如有序序列中
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









