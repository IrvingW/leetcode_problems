/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 *
 * https://leetcode-cn.com/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (53.29%)
 * Likes:    405
 * Dislikes: 0
 * Total Accepted:    70.2K
 * Total Submissions: 131.6K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 现在你总共有 n 门课需要选，记为 0 到 n-1。
 *
 * 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]
 *
 * 给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。
 *
 * 可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。
 *
 * 示例 1:
 *
 * 输入: 2, [[1,0]]
 * 输出: [0,1]
 * 解释: 总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
 *
 * 示例 2:
 *
 * 输入: 4, [[1,0],[2,0],[3,1],[3,2]]
 * 输出: [0,1,2,3] or [0,2,1,3]
 * 解释: 总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
 * 因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
 *
 *
 * 说明:
 *
 *
 * 输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
 * 你可以假定输入的先决条件中没有重复的边。
 *
 *
 * 提示:
 *
 *
 * 这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。
 * 通过 DFS 进行拓扑排序 - 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。
 *
 * 拓扑排序也可以通过 BFS 完成。
 *
 *
 *
 */

#include <vector>
#include <queue>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * @brief Kahn算法
     */
    // vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    //     vector<int> inDegree(numCourses, 0);
    //     vector<vector<int>> edges(numCourses, vector<int>());
    //     queue<int> q;
    //     for (auto& preRequest : prerequisites) {
    //         inDegree[preRequest[0]] += 1;
    //         edges[preRequest[1]].push_back(preRequest[0]);

    //     }
    //     vector<int> result;
    //     for (int i = 0; i < numCourses; i++) {
    //         if (inDegree[i] == 0) {
    //             q.push(i);
    //         }
    //     }
    //     while(!q.empty()) {
    //         int node = q.front();
    //         q.pop();
    //         result.push_back(node);
    //         for (auto& nextNode : edges[node]) {
    //             inDegree[nextNode] -= 1;
    //             if (inDegree[nextNode] == 0) {
    //                 q.push(nextNode);
    //             }
    //         }
    //     }

    //     // has cycle
    //     if (result.size() < numCourses) {
    //         return vector<int>();
    //     }
    //     return result;
    // }

    /**
     * @brief DFS
     */
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        visited.assign(numCourses, 0);
        edges.resize(numCourses);
        for (auto& preRequest : prerequisites) {
            edges[preRequest[1]].push_back(preRequest[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                dfs(i);
                if (!valid) return result;
            }
        }

        while(!stk.empty()) {
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }
private:
    void dfs(int node) {
        visited[node] = 1;
        for (auto& to : edges[node]) {
            if (visited[to] == 1) {
                valid = false;
                return;
            } else if (visited[to] == 0) {
                dfs(to);
                if (!valid) return;
            }
        }
        visited[node] = 2;
        stk.push(node);
    }

private:
    stack<int> stk;
    bool valid = true;
    vector<int> visited;
    vector<vector<int>> edges;
};
// @lc code=end

