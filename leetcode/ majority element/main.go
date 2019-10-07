package main
/*
给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在众数。

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2
 */
import (
	"fmt"
	"sort"
)

// 对于过n/2的众数求解很nice，否则失灵
func majorityElement(nums []int) int {
	temp := make(map[int]int)
	target := len(nums) / 2
	for _, val := range nums {

		temp[val] += 1
		if temp[val] > target {
			return val
		}
	}
	val2 := 0
	for _, val2 = range nums {
		if temp[val2] > target {
			break
		}
	}
	return val2
}

// 利用排序算法后代码很简洁,但是有局限性，针对过n/2的众数求解很nice，否则可能失灵
func majorityElement_2(nums []int) int {

	sort.Ints(nums)

	return nums[len(nums)/2] // {0,0,1,2,2,2,3,4,5}
}


// 对于过n/2的众数求解很nice，否则失灵
func majorityElement_3(nums []int) int {
	num := 0
	count := 0
	len := len(nums)
	for i := 0; i < len; i++ {
		if count == 0 {
			num = nums[i]
		}
		if num == nums[i] {
			count++
		} else {
			count--
		}
	}

	return num
}

func main() {
	nums := []int{0,4,1,4,2,3,4}

	result := majorityElement(nums)
	fmt.Println(result)
}
