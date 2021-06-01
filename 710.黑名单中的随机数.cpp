/*
 * @lc app=leetcode.cn id=710 lang=cpp
 *
 * [710] 黑名单中的随机数
 *
 * https://leetcode-cn.com/problems/random-pick-with-blacklist/description/
 *
 * algorithms
 * Hard (33.77%)
 * Likes:    68
 * Dislikes: 0
 * Total Accepted:    3.9K
 * Total Submissions: 11.5K
 * Testcase Example:  '["Solution", "pick", "pick", "pick"]\n[[1, []], [], [], []]'
 *
 * 给定一个包含 [0，n) 中不重复整数的黑名单 blacklist ，写一个函数从 [0, n) 中返回一个不在 blacklist 中的随机整数。
 *
 * 对它进行优化使其尽量少调用系统方法 Math.random() 。
 *
 * 提示:
 *
 *
 * 1
 * 0
 * [0, n) 不包含 n ，详细参见 interval notation 。
 *
 *
 * 示例 1：
 *
 *
 * 输入：
 * ["Solution","pick","pick","pick"]
 * [[1,[]],[],[],[]]
 * 输出：[null,0,0,0]
 *
 *
 * 示例 2：
 *
 *
 * 输入：
 * ["Solution","pick","pick","pick"]
 * [[2,[]],[],[],[]]
 * 输出：[null,1,1,1]
 *
 *
 * 示例 3：
 *
 *
 * 输入：
 * ["Solution","pick","pick","pick"]
 * [[3,[1]],[],[],[]]
 * 输出：[null,0,0,2]
 *
 *
 * 示例 4：
 *
 *
 * 输入：
 * ["Solution","pick","pick","pick"]
 * [[4,[2]],[],[],[]]
 * 输出：[null,1,3,1]
 *
 *
 * 输入语法说明：
 *
 * 输入是两个列表：调用成员函数名和调用的参数。Solution的构造函数有两个参数，n 和黑名单 blacklist。pick
 * 没有参数，输入参数是一个列表，即使参数为空，也会输入一个 [] 空列表。
 *
 */

#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    Solution(int n, vector<int>& blacklist) {
        for (auto&& black : blacklist) {
            blackMap[black] = -1;
        }
        range = n - blacklist.size();
        int lastNormal = n - 1;
        for (auto&& black : blacklist) {
            if (black >= range) continue;
            while(blackMap.count(lastNormal)) {
                lastNormal--;
            }
            blackMap[black] = lastNormal;
            lastNormal--;
        }
    }

    int pick() {
        int index = (rand() % range);
        if (blackMap.count(index)) return blackMap[index];
        else return index;
    }
private:
    unordered_map<int, int> blackMap;
    int range = 0;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

