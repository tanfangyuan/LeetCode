//给你一个字符串 s，找到 s 中最长的回文子串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
// 
//
// 示例 2： 
//
// 
//输入：s = "cbbd"
//输出："bb"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 仅由数字和英文字母组成 
// 
//
// Related Topics 字符串 动态规划 👍 5806 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int maxLen = 0;
        int n = s.size();
        for (int c = 0; c < n; ++c) {
            int i, j;
            for (int delta = 0; delta <= 1; ++delta) {
                i = c;
                j = i + delta;
                while (i >= 0 && j < n) {
                    if (s.at(i) == s.at(j)) {
                        if (maxLen < (j-i+1)) {
                            maxLen = j-i+1;
                            ans = s.substr(i, j-i+1);
                        }
                        i --;
                        j ++;
                    } else {
                        break;
                    }
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
    string testcase = "babad";
    auto ans = s.longestPalindrome(testcase);
    cout<< ans << endl;
}