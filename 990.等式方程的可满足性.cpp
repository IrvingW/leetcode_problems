/*
 * @lc app=leetcode.cn id=990 lang=cpp
 *
 * [990] 等式方程的可满足性
 *
 * https://leetcode-cn.com/problems/satisfiability-of-equality-equations/description/
 *
 * algorithms
 * Medium (48.33%)
 * Likes:    170
 * Dislikes: 0
 * Total Accepted:    28.8K
 * Total Submissions: 58.9K
 * Testcase Example:  '["a==b","b!=a"]'
 *
 * 给定一个由表示变量之间关系的字符串方程组成的数组，每个字符串方程 equations[i] 的长度为 4，并采用两种不同的形式之一："a==b" 或
 * "a!=b"。在这里，a 和 b 是小写字母（不一定不同），表示单字母变量名。
 *
 * 只有当可以将整数分配给变量名，以便满足所有给定的方程时才返回 true，否则返回 false。 
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：["a==b","b!=a"]
 * 输出：false
 * 解释：如果我们指定，a = 1 且 b = 1，那么可以满足第一个方程，但无法满足第二个方程。没有办法分配变量同时满足这两个方程。
 *
 *
 * 示例 2：
 *
 * 输入：["b==a","a==b"]
 * 输出：true
 * 解释：我们可以指定 a = 1 且 b = 1 以满足满足这两个方程。
 *
 *
 * 示例 3：
 *
 * 输入：["a==b","b==c","a==c"]
 * 输出：true
 *
 *
 * 示例 4：
 *
 * 输入：["a==b","b!=c","c==a"]
 * 输出：false
 *
 *
 * 示例 5：
 *
 * 输入：["c==c","b==d","x!=z"]
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= equations.length <= 500
 * equations[i].length == 4
 * equations[i][0] 和 equations[i][3] 是小写字母
 * equations[i][1] 要么是 '='，要么是 '!'
 * equations[i][2] 是 '='
 *
 *
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        UF uf('a', 'z');
        for (auto& eq : equations) {
            if (eq[1] == '=') {
                const char& A = eq[0];
                const char& B = eq[3];
                uf.makeUnion(A, B);
            }
        }
        for (auto& eq : equations) {
            if (eq[1] == '!') {
                const char& A = eq[0];
                const char& B = eq[3];
                if (uf.connected(A, B))
                    return false;
            }
        }
        return true;
    }

private:
    class UF {
    public:
        UF(const char& a, const char& b) {
            int size = b - a + 1;
            for (int i = 0; i < size; i++) {
                parent.push_back(i);
                weight.push_back(1);
            }
        }

        void makeUnion(const char& a, const char& b) {
            int rootA = find(a - 'a');
            int rootB = find(b - 'a');
            if (rootA == rootB) return;
            if (weight[rootA] > weight[rootB]) {
                parent[rootB] = rootA;
                weight[rootA] += weight[rootB];
            } else {
                parent[rootA] = rootB;
                weight[rootB] += weight[rootA];
            }
        }

        bool connected(const char& a, const char& b) {
            int rootA = find(a - 'a');
            int rootB = find(b - 'a');
            return (rootA == rootB);
        }

    private:
        int find(int node) {
            while(parent[node] != node) {
                // 路径压缩
                parent[node] = parent[parent[node]];
                node = parent[node];
            }
            return node;
        }

    private:
        vector<int> parent;
        // 用森林的节点个数决定哪个root联到哪个root上
        vector<int> weight;
    };
};
// @lc code=end

