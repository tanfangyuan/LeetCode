//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。 
//
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。 
//
// 此外，你可以假设该网格的四条边均被水包围。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 300 
// grid[i][j] 的值为 '0' 或 '1' 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 👍 1955 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                ans += (int)isIsland(grid, i, j);
            }
        }
        return ans;
    }

    bool isIsland(vector<vector<char>> &grid, int i, int j) {
        if ((i<0 || i>=grid.size() || j < 0 || j >= grid[i].size())
            || grid[i][j]=='0') {
            return false;
        }
        grid[i][j] = '0';
        isIsland(grid, i-1, j); // 上
        isIsland(grid, i+1, j); // 下
        isIsland(grid, i, j-1); // 左
        isIsland(grid, i, j+1); // 右
        return true;
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