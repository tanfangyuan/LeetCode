//你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。 
//
// 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表
//示如果要学习课程 ai 则 必须 先学习课程 bi 。 
//
// 
// 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。 
// 
//
// 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。 
//
// 
//
// 示例 1： 
//
// 
//输入：numCourses = 2, prerequisites = [[1,0]]
//输出：true
//解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。 
//
// 示例 2： 
//
// 
//输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
//输出：false
//解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。 
//
// 
//
// 提示： 
//
// 
// 1 <= numCourses <= 10⁵ 
// 0 <= prerequisites.length <= 5000 
// prerequisites[i].length == 2 
// 0 <= ai, bi < numCourses 
// prerequisites[i] 中的所有课程对 互不相同 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 👍 1437 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
private:
    // graph的顺序即为课程的顺序值，因此不用额外的位置保存节点的值
    vector<vector<int>> graph;
    vector<int> indegree;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. 构建图的表示，初始化入度数组 以及 栈，记录拓扑排序记录节点数目
        initGraph(numCourses, prerequisites);
        int count;
        std::stack<int> record;
        for (int i=0; i<numCourses; ++i) {
            if (!indegree[i]) {
                record.push(i);
            }
        }
        // 2. 遍历查找入度为0的点，将其从图中删除，直到不存在入度为0的点
        while (!record.empty()) {
            int node = record.top();
            record.pop();
            count ++;
            for (int i=0; i<graph[node].size(); ++i) {
                if (--indegree[graph[node][i]] == 0) {
                    record.push(graph[node][i]);
                }
            }
        }

        // 3. 检测此时拓扑排序输出的节点数目，判定是否存在环
        return count == numCourses;
    }
private:
    void initGraph(int numCourses, vector<vector<int>>& prerequisites) {
        graph.resize(numCourses);
        indegree.resize(numCourses);
        for (const auto &info: prerequisites) {
            graph[info[1]].push_back(info[0]);
            indegree[info[0]] ++;
        }
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