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
