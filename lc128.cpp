
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

void print_vector(const vector<int>& nums)
{
    for(int i = 0; i< nums.size(); ++i)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void printHashSet(const unordered_set<int> st)
{
    for (int i : st)
        cout<<i<<" ";

    cout<<endl;
}



class Solution {
public:
    // 方法一：哈希表 
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) 
            return 0;
        
        unordered_set<int> st;
        for (int num : nums)
            st.insert(num);

        int max_len = 0;
        for (int num : st)
        {
            // 只从连续序列的起点开始计算
            if (st.count(num - 1))
                continue;

            // 从起点开始向后扩展
            int current_len = 1;
            int current_num = num;
            while (st.count(current_num + 1))
            {
                current_len++;
                current_num++;
            }
            max_len = max(max_len, current_len);
        }
        return max_len;
    }

    // 方法二：排序法 
    int longestConsecutive2(vector<int>& nums) {
        if (nums.size() == 0) 
            return 0;

        // 排序 
        sort(nums.begin(),nums.end());
        // 去重
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

        int max_len = 1;
        int tmp_len = 1;
        for(int i = 1; i< nums.size(); ++i )
        {
            if (nums[i-1] + 1 == nums[i])
            {
                tmp_len++;
                if (tmp_len > max_len)
                {
                    max_len = tmp_len;    
                }
            }
            else 
            {
                tmp_len = 1;
            }
        }
        return max_len;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {9,1,4,7,3,-1,0,5,8,-1,6};
    int result = solution.longestConsecutive(nums);
    cout << result << endl;
    return 0;
}