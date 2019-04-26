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
int flag = 1;
void ImprovedBubbleSort(int *arr, int len)
{
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

