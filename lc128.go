package main

import (
	"sort"
)

func longestConsecutive(nums []int) int {
	if len(nums) == 0 {
		return 0
	}

	// 构建哈希表
	mp := make(map[int]bool)
	for _, num := range nums {
		mp[num] = true
	}

	// 找出最长的连续字段
	maxLen := 0
	for num := range mp {
		// 避免重复遍历: 如果num-1存在，则num不是连续字段的起点，跳过
		if mp[num-1] {
			continue
		}

		// 以num为起点，计算连续字段的长度
		curNum := num
		curLen := 1
		for mp[curNum+1] {
			curNum++
			curLen++
		}
		if curLen > maxLen {
			maxLen = curLen
		}
	}

	return maxLen
}

func longestConsecutive2(nums []int) int {
	if len(nums) <= 0 {
		return 0
	}

	// 1. 排序
	sort.Ints(nums)

	// 2. 找出最长的连续字段
	tmp_len := 1
	max_len := 1
	for i := 1; i < len(nums); i++ {
		if nums[i] == nums[i-1] {
			continue
		} else if nums[i] == nums[i-1]+1 {
			tmp_len++
			if tmp_len > max_len {
				max_len = tmp_len
			}
		} else {
			tmp_len = 1
		}
	}

	return max_len
}

func main() {
	nums := []int{9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6}
	result := longestConsecutive(nums)
	println(result)
}
