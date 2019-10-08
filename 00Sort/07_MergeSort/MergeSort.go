package main

import "fmt"

// 合并两个序列
func Merge(arr []int, start int, end int, mid int, temp []int) {
	i := start
	j := mid + 1
	length := 0
	for i <= mid && j <= end {
		if arr[i] < arr[j] {
			temp[length] = arr[i]
			i++
		} else {
			temp[length] = arr[j]
			j++
		}
		length++
	}

	// 处理两序列不对称部分
	for i <= mid {
		temp[length] = arr[i]
		i++
		length++
	}
	for j <= end {
		temp[length] = arr[j]
		j++
		length++
	}

	// 将temp里的处理结果替换回arr
	for i := 0; i < length; i++ {
		arr[start+i] = temp[i]
	}
}

func MergeSort(arr []int, start int, end int, temp []int) {
	if start >= end {
		return
	}

	mid := (start + end) / 2

	MergeSort(arr, start, mid, temp)

	MergeSort(arr, mid+1, end, temp)

	Merge(arr, start, end, mid, temp)
}

func main() {
	arr := []int{5, 9, 4, 7, 3, 6, 19, 6, 3}
	temp := make([]int, len(arr))

	fmt.Println(arr)
	MergeSort(arr, 0, len(arr)-1, temp)
	fmt.Println(arr)
}
