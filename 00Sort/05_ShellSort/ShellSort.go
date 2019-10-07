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
