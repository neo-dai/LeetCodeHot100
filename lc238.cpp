#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        // slow 保存最左边0的位置
        // fast 遍历数组
        size_t slow = 0;
        for (size_t fast = 0; fast < nums.size(); ++fast) {
            if (nums[fast] != 0) {
                if (slow != fast) {  // 避免自己和自己交换
                    swap(nums[slow], nums[fast]);
                }
                slow++;
            }
        }
    }
};

int main() {
    Solution su; 
    vector<int> nums{0,1,0,3,12};

    for(int i : nums)
        cout<<i<<" ";
    cout<<endl;
    
    su.moveZeroes(nums);

    for(int i : nums)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}