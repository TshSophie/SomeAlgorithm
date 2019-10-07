package main

import (
	"fmt"
)

func searchMatrix(matrix [][]int, target int) bool {

	if len(matrix)== 0 || len(matrix[0]) ==0{
		return false
	}


	// 从第一行查找合适的位置开始进行搜索
	line1 := matrix[0]

	// 从左往右
	i := 0
	val :=0
	for i,val = range line1  {
		if target ==val{
			return true
		}
		if target < val{
			i--
			break
		}
	}
	if i<0 {
		return false
	}

	// 纵向查找 , 查找第i列
	col := len(matrix)
	// 只有一行
	if col == 1{
		return false
	}

	for j:=0;j<col;j++{
		if matrix[j][i] == target {
			return true
		}
	}


	// 从第一列查找合适的位置开始进行搜索
	j:=0
	for j = 0;j<col;j++{
		if matrix[j][0] == target {
			return true
		}
		if target < matrix[j][0]{
			break
		}
	}
	j--
	// 横向查找, 查找第k行
	for k:=0;k < len(line1);k++{
		if matrix[k][j] == target {
			return true
		}
	}

	return  false
}

func main()  {

	//matrix := [][]int{{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}}
	matrix := [][]int{{-1},{-1}}

	ret := searchMatrix(matrix,0)
	fmt.Println(ret)
}
