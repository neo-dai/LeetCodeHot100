package main

import (
	"fmt"
	"sort"
)

/*
1. 构建索引
mp := make(map[string][]string)
for _, str := range strs {
	b := []byte(str)
	sort.Slice(b, func(i, j int) bool { return b[i] < b[j] })
	key := string(b)
	mp[key] = append(mp[key], str)
}
*/

// 排序法
func groupAnagrams(strs []string) [][]string {
	// 1. 构建索引（排序法）
	// 由于 sort 无法直接排序 string，需要转换为 []byte
	mp := make(map[string][]string)
	for _, str := range strs {
		b := []byte(str)
		sort.Slice(b, func(i, j int) bool { return b[i] < b[j] })
		key := string(b)
		mp[key] = append(mp[key], str)
	}

	// 2. 构建结果
	result := make([][]string, 0, len(mp))
	for _, v := range mp {
		result = append(result, v)
	}

	return result
}

// 计数法
func groupAnagrams2(strs []string) [][]string {
	// 1. 构建索引
	mp := make(map[[26]int][]string)
	for _, str := range strs { // tips: 需要注意的是str仅仅为值拷贝，并非引用 如果需要修改数组元素需要访问strs[i]
		var count [26]int
		for _, c := range str {
			count[c-'a']++
		}
		mp[count] = append(mp[count], str)
	}

	// 2. 构建结果
	// tips: 使用make提前预分配容量可以显著减少内存分配和数据复制
	result := make([][]string, 0, len(mp))
	for _, v := range mp {
		result = append(result, v)
	}

	return result
}

func main() {
	fmt.Println("Hello, World!")
}
