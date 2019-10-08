package main

import "fmt"

func swap(arr []int, pos1 int, pos2 int) {
	arr[pos1], arr[pos2] = arr[pos2], arr[pos1]
}

func HeapAdjust(arr []int, pos int, length int) {
	left := pos*2 + 1
	right := pos*2 + 2
	max := pos
	if left < length && arr[left] > arr[max] {
		max = left
	}
	if right < length && arr[right] > arr[max] {
		max = right
	}
	if max != pos {
		swap(arr, max, pos)
		HeapAdjust(arr, max, length)
	}
}

func HeapSort(arr []int) {
	length := len(arr)
	// 初始化堆
	for i := length/2 + 1; i >= 0; i-- {
		HeapAdjust(arr, i, length)
	}

	// 调整后的堆顶元素与未排序的末元素交换
	for i := length - 1; i >= 0; i-- {
		swap(arr, 0, i)
		HeapAdjust(arr, 0, i)
	}
}

func main() {
	arr := []int{5, 9, 4, 7, 3, 6, 19, 6, 3}
	fmt.Println(arr)
	HeapSort(arr)
	fmt.Println(arr)
}
