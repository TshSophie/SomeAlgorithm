package main

import "fmt"

/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:

输入: [2,2,1]
输出: 1
示例 2:

输入: [4,1,2,1,2]
输出: 4
*/

// 包容性强
func singleNumber(nums []int) int {
	temp := make(map[int]int)

	for _, val := range nums {

		temp[val] += 1
	}
	val2 := 0
	for _, val2 = range nums {
		if temp[val2] == 1 {
			break
		}
	}
	return val2
}

// 针对其他数出现次数为偶数次时，是非常好的算法
func singleNumber_8s(nums []int) int {
	res := 0
	for _, i := range nums {
		res ^= i // 按位异或 res = res ^ i
		fmt.Println("res = ", res)
	}
	return res
}

func main() {

	nums := []int{4, 4, 5, 2, 3, 3, 99, 2, 5}

	result := singleNumber_8s(nums)

	fmt.Println(result)
}
