#include <iostream>

#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    // 求数组内面积最大的长方形 
    // 暴力枚举即可 O(n) 选出面积最大的两个i
    //  双指针如何处理呢？ 没办法 必然只能枚举 
    // 从两端开始遍历，直到两个指针相遇然后选出其中面积最大的两个点
    int maxArea(vector<int>& height) {
        struct MaxPoint
        {
            int Area = 0;
            int Point1 = 0; 
            int Point2 = 0;
        }maxPoint;

        int left = 0;
        int right = height.size() - 1;
        while (left < right)
        {
            // 1. 计算面积 
            int Area = (right - left) * min(height[left],height[right]);
            if (Area > maxPoint.Area)
            {
                maxPoint.Area = Area;
                maxPoint.Point1 = left;
                maxPoint.Point2 = right;
            }

            // 2. 更新坐标
            if (height[left] > height[right] )
            {
                right--;
            }
            else 
            {
                left++;
            }
        }
        return maxPoint.Area;
    }

};

int main()
{
    Solution solution;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int result = solution.maxArea(height);
    cout << result << endl;
    return 0;
}