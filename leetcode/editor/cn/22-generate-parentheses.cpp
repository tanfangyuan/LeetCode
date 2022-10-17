//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：["((()))","(()())","(())()","()(())","()()()"]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：["()"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 8 
// 
//
// Related Topics 字符串 动态规划 回溯 👍 2911 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string> > dp(n+1);
        dp[0] = {""};
        dp[1] = { "()" };

        for (int m = 2; m <= n; ++m) { // 计算dp[m], m为当前括号对的数目
            for (int i = 0; i <= m - 1; ++i) { // 对于dp[m],遍历右括号的位置
                if (!dp[i].empty() && !dp[m - 1 - i].empty()) {
                    for (string p:dp[i]) {
                        for (string q:dp[m-i-1]) {
                            string newAns = "(" + p + ")" + q;
                            dp[m].push_back(newAns);
                        }
                    }
                }
            }
        }
        return dp[n];
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