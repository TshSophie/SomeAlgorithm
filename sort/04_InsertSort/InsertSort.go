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
