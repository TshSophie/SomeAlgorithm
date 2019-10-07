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
