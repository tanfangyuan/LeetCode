//以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返
//回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。 
//
// 
//
// 示例 1： 
//
// 
//输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
//输出：[[1,6],[8,10],[15,18]]
//解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 
//
// 示例 2： 
//
// 
//输入：intervals = [[1,4],[4,5]]
//输出：[[1,5]]
//解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。 
//
// 
//
// 提示： 
//
// 
// 1 <= intervals.length <= 10⁴ 
// intervals[i].length == 2 
// 0 <= starti <= endi <= 10⁴ 
// 
//
// Related Topics 数组 排序 👍 1696 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > ans;
        // 0. 对原数组排序
        /**
        struct {
            bool operator()(vector<int> a, vector<int> b) const { return a[0] < b[0]; }
        } customsort;
        std::sort(intervals.begin(), intervals.end(), customsort);
        **/
        std::sort(intervals.begin(), intervals.end());

        // 1. 合并区间
        int start=intervals[0][0], end=intervals[0][1];
        /**
        for (int id=1; id<intervals.size(); ++id) {
            int i = intervals[id][0];
            int j = intervals[id][1];
            if (j <= end) {
                continue;
            } else if (i<=end) {
                end = j;
            } else {
                ans.push_back(vector<int>{start, end});
                start = i; end = j;
            }
        }
        ans.push_back(vector<int>{start, end});
        **/
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!ans.size() || ans.back()[1] < L) {
                ans.push_back({L, R});
            } else {
                ans.back()[1] = max(ans.back()[1], R);
            }
        }

        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> data{7, 1, 5, 3, 6, 4};
    auto res = "Hello LeetCode";
    cout<<res<<endl;
}