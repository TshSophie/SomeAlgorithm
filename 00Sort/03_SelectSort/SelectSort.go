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
