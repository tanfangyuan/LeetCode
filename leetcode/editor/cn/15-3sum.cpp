//给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != 
//k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请 
//
// 你返回所有和为 0 且不重复的三元组。 
//
// 注意：答案中不可以包含重复的三元组。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-1,0,1,2,-1,-4]
//输出：[[-1,-1,2],[-1,0,1]]
//解释：
//nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
//nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
//nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
//不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
//注意，输出的顺序和三元组的顺序并不重要。
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1,1]
//输出：[]
//解释：唯一可能的三元组和不为 0 。
// 
//
// 示例 3： 
//
// 
//输入：nums = [0,0,0]
//输出：[[0,0,0]]
//解释：唯一可能的三元组和为 0 。
// 
//
// 
//
// 提示： 
//
// 
// 3 <= nums.length <= 3000 
// -10⁵ <= nums[i] <= 10⁵ 
// 
//
// Related Topics 数组 双指针 排序 👍 5295 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        // 0. 排序
        std::sort(nums.begin(), nums.end());

        // 1. 双指针查找
        for (int i = 0; i < n; ++i) {
            if (i>0 && nums[i] == nums[i-1]) {
                continue;
            }

            int k = n-1;
            for (int j = i+1; j < n; ++j) {
                if (j > (i+1) && nums[j] == nums[j-1]) {
                    continue;
                }
                while (k > j && nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                }
                if (k == j) {
                    break;
                }
                if (nums[i] + nums[j] + nums[k] == 0) {
                    ans.push_back(vector<int>{nums[i], nums[j], nums[k]});
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{1,2,-2,-1};
    auto res = s.threeSum(data);
    for (auto array: res) {
        for (auto val: array) {
            std:: cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}