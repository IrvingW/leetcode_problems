/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 *
 * https://leetcode-cn.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (47.91%)
 * Likes:    266
 * Dislikes: 0
 * Total Accepted:    27.1K
 * Total Submissions: 56.6K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * 有 n 个网络节点，标记为 1 到 n。
 *
 * 给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点，
 * wi 是一个信号从源节点传递到目标节点的时间。
 *
 * 现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：times = [[1,2,1]], n = 2, k = 1
 * 输出：1
 *
 *
 * 示例 3：
 *
 *
 * 输入：times = [[1,2,1]], n = 2, k = 2
 * 输出：-1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 * times[i].length == 3
 * 1 i, vi
 * ui != vi
 * 0 i
 * 所有 (ui, vi) 对都 互不相同（即，不含重复边）
 *
 *
 */

#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> g(n + 1, vector<int>(n + 1, INT_MAX / 2));
        vector<int> visited(n + 1, 0);
        vector<int> dist(n + 1, INT_MAX / 2);
        // init
        for (auto& edge : times) {
            g[edge[0]][edge[1]] = edge[2];
            if (edge[0] == k) {
                dist[edge[1]] = edge[2];
            }
        }
        visited[k] = 1;
        dist[0] = 0; dist[k] = 0;

        for (int i = 1; i < n; i++) {
            int minDis = INT_MAX / 2;
            int nextNode = 0;
            for (int i = 1; i <= n; i++) {
                if (dist[i] < minDis && visited[i] == 0) {
                    minDis = dist[i];
                    nextNode = i;
                }
            }
            // exist node cannot reach
            if (minDis == INT_MAX / 2) return -1;

            // slack
            visited[nextNode] = 1;
            for (int i = 1; i <= n; i++) {
                if (g[nextNode][i] != INT_MAX / 2 && dist[i] > dist[nextNode] + g[nextNode][i]) {
                    dist[i] = dist[nextNode] + g[nextNode][i];
                }
            }
        }

        int result = *max_element(dist.begin(), dist.end());
        return result;
    }
};
// @lc code=end
