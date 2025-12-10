/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

==字母异位词== : 字母异位词是通过重新排列不同单词或短语的字母而形成的单词或短语，并使用所有原字母一次。

**示例 1:**

**输入:** strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

**输出:** [["bat"],["nat","tan"],["ate","eat","tea"]]

**解释：**

- 在 strs 中没有字符串可以通过重新排列来形成 `"bat"`。
- 字符串 `"nat"` 和 `"tan"` 是字母异位词，因为它们可以重新排列以形成彼此。
- 字符串 `"ate"` ，`"eat"` 和 `"tea"` 是字母异位词，因为它们可以重新排列以形成彼此。

**示例 2:**

**输入:** strs = [""]

**输出:** [[""]]

**示例 3:**

**输入:** strs = ["a"]

**输出:** [["a"]]

**提示：**

- `1 <= strs.length <= 104`
- `0 <= strs[i].length <= 100`
- `strs[i]` 仅包含小写字母
*/

#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <map> 
#include <unordered_map> 
using namespace std;

// map 15ms 
// unordered_map 7ms

class Solution {
    public:
        // 计数法
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            // 1. 构建索引
            unordered_map<string,vector<string>> tmp;
            for (const auto& str : strs)
            {
                string key(26,'0');
                for (const char& c : str )
                {
                    key[c-'a']++;
                }
                tmp[key].push_back(str);
            }

            // 2. 构建结果
            vector<vector<string>> result;
            result.reserve(tmp.size());
            for (auto& it : tmp)
            {
                result.push_back(std::move(it.second));
            }

            // 3. 返回结果
            return result;
        }

    // 排序法
    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        // 1. 构建索引
        unordered_map<string,vector<string>> tmp;
        for (const auto& str : strs)
        {
            string key = str;
            sort(key.begin(),key.end());
            tmp[key].push_back(str);
        }

        // 2. 构建结果
        vector<vector<string>> result;
        result.reserve(tmp.size());
        for (auto& it : tmp)
        {
            result.push_back(std::move(it.second));
        }

        // 3. 返回结果
        return result;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = solution.groupAnagrams(strs);
    for (auto vec : result) {
        for (auto str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
