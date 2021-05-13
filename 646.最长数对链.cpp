/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * [646] 最长数对链
 *
 * https://leetcode-cn.com/problems/maximum-length-of-pair-chain/description/
 *
 * algorithms
 * Medium (57.29%)
 * Likes:    160
 * Dislikes: 0
 * Total Accepted:    17.6K
 * Total Submissions: 30.7K
 * Testcase Example:  '[[1,2],[2,3],[3,4]]'
 *
 * 给出 n 个数对。 在每一个数对中，第一个数字总是比第二个数字小。
 *
 * 现在，我们定义一种跟随关系，当且仅当 b < c 时，数对(c, d) 才可以跟在 (a, b) 后面。我们用这种形式来构造一个数对链。
 *
 * 给定一个数对集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。
 *
 *
 *
 * 示例：
 *
 *
 * 输入：[[1,2], [2,3], [3,4]]
 * 输出：2
 * 解释：最长的数对链是 [1,2] -> [3,4]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 给出数对的个数在 [1, 1000] 范围内。
 *
 *
 */

#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int size = pairs.size();
        if (size == 0) return 0;
        auto cmp = [](vector<int>& a, vector<int>& b) -> bool {
            if (a[1] == b[1]) return a[0] < b[0];
            else return a[1] < b[1];
        };
        sort(pairs.begin(), pairs.end(), cmp);
        vector<int> dp(size, 1);
        int maxCnt = 1;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxCnt = max(maxCnt, dp[i]);
                }
            }
        }
        return maxCnt;
    }
};
// @lc code=end

