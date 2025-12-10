from collections import defaultdict
from typing import List

class Solution(object):
    # 方法1：排序法
    def groupAnagrams(self, strs):
        """
        排序法：将每个字符串排序后作为 key
        时间复杂度：O(n * k * log k)，n 是字符串数量，k 是字符串平均长度
        
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        # 使用 defaultdict 自动初始化空列表
        mp = defaultdict(list)
        
        for s in strs:
            # Python 的 sorted() 返回排序后的字符列表
            # ''.join() 将字符列表连接成字符串
            key = ''.join(sorted(s))
            mp[key].append(s)
        
        # dict.values() 返回所有值的集合
        return list(mp.values())
    
    
    # 方法2：计数法（性能更好）
    def groupAnagrams2(self, strs):
        """
        计数法：统计每个字符出现次数作为 key
        时间复杂度：O(n * k)，n 是字符串数量，k 是字符串平均长度
        
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        mp = defaultdict(list)
        
        for s in strs:
            # 统计每个字母出现次数
            count = [0] * 26
            for c in s:
                count[ord(c) - ord('a')] += 1
            
            # 将列表转换为 tuple 作为 key（列表不能作为字典 key）
            key = tuple(count)
            mp[key].append(s)
        
        return list(mp.values())
    
    
    # 方法3：使用 Counter（Python 风格）
    def groupAnagrams3(self, strs):
        """
        使用 Counter 统计字符频率（最 Pythonic）
        时间复杂度：O(n * k * log k)，因为需要排序 Counter 的 items
        
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        from collections import Counter
        
        mp = defaultdict(list)
        
        for s in strs:
            # Counter 返回一个字典，frozenset 将其转换为不可变集合作为 key
            # 或者直接用 tuple(sorted(Counter(s).items()))
            key = tuple(sorted(Counter(s).items()))
            mp[key].append(s)
        
        return list(mp.values())


# 测试代码
def test():
    solution = Solution()
    
    # 测试用例1
    test1 = ["eat", "tea", "tan", "ate", "nat", "bat"]
    print("输入:", test1)
    print("方法1 - 排序法:", solution.groupAnagrams(test1))
    print("方法2 - 计数法:", solution.groupAnagrams2(test1))
    print("方法3 - Counter:", solution.groupAnagrams3(test1))
    
    # 测试用例2
    print("\n输入: ['']")
    print("输出:", solution.groupAnagrams([""]))
    
    # 测试用例3
    print("\n输入: ['a']")
    print("输出:", solution.groupAnagrams(["a"]))
    
    # 性能对比测试
    print("\n性能提示：")
    print("- 方法1 排序法：简洁直观，O(n * k * log k)")
    print("- 方法2 计数法：性能最优，O(n * k)")
    print("- 方法3 Counter：代码最 Pythonic，但略慢于方法2")


if __name__ == "__main__":
    test()
