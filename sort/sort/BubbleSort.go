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
