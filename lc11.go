package main

import (
	"fmt"
)

func maxArea(height []int) int {
	type MaxArea struct {
		Area   int
		Point1 int
		Point2 int
	}
	maxArea := MaxArea{
		Area:   0,
		Point1: 0,
		Point2: 0,
	}

	left := 0
	right := len(height) - 1
	for left < right {
		// 1. 计算面积
		tmpArea := (right - left) * min(height[left], height[right])
		if tmpArea > maxArea.Area {
			maxArea.Area = tmpArea
		}

		// 2. 移动“指针”
		if height[left] > height[right] {
			right--
		} else {
			left++
		}
	}

	return maxArea.Area
}

func main() {
	height := []int{1, 8, 6, 2, 5, 4, 8, 3, 7}
	result := maxArea(height)
	fmt.Println(result)
}
