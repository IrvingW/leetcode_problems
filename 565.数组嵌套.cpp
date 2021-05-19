/*
 * @lc app=leetcode.cn id=565 lang=cpp
 *
 * [565] 数组嵌套
 *
 * https://leetcode-cn.com/problems/array-nesting/description/
 *
 * algorithms
 * Medium (60.64%)
 * Likes:    150
 * Dislikes: 0
 * Total Accepted:    12.1K
 * Total Submissions: 19.9K
 * Testcase Example:  '[5,4,0,3,1,6,2]'
 *
 * 索引从0开始长度为N的数组A，包含0到N - 1的所有整数。找到最大的集合S并返回其大小，其中 S[i] = {A[i], A[A[i]],
 * A[A[A[i]]], ... }且遵守以下的规则。
 *
 * 假设选择索引为i的元素A[i]为S的第一个元素，S的下一个元素应该是A[A[i]]，之后是A[A[A[i]]]...
 * 以此类推，不断添加直到S出现重复的元素。
 *
 *
 *
 * 示例 1:
 *
 * 输入: A = [5,4,0,3,1,6,2]
 * 输出: 4
 * 解释:
 * A[0] = 5, A[1] = 4, A[2] = 0, A[3] = 3, A[4] = 1, A[5] = 6, A[6] = 2.
 *
 * 其中一种最长的 S[K]:
 * S[0] = {A[0], A[5], A[6], A[2]} = {5, 6, 2, 0}
 *
 *
 *
 *
 * 提示：
 *
 *
 * N是[1, 20,000]之间的整数。
 * A中不含有重复的元素。
 * A中的元素大小在[0, N-1]之间。
 *
 *
 */

#include <vector>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        if (nums.empty()) return 0;
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != -1) {
                int size = count(nums, i);
                if (size > nums.size() / 2) return size;
                result = max(size, result);
            }
        }
        return result;
    }
private:
    int count(vector<int>& nums, int n) {
        int result = 0;
        while(nums[n] != -1) {
            int next = nums[n];
            nums[n] = -1;
            result += 1;
            n = next;
        }
        return result;
    }
};
// @lc code=end

