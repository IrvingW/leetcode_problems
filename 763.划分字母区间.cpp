/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

#include <string>
#include <vector>
#include <set>
#include <math.h>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> result;
        if (S.empty()) return result;
        partitionRecursive(S, 0, result);
        return result;
    }
private:
    void partitionRecursive(string& S, int start, vector<int>& result) {
        int index = start;
        int right = start;
        while (index <= right) {
            set<char> dict;
            if (dict.count(S[index]) == 0) {
                int repeat = S.rfind(S[index]);
                right = max(right, repeat);
                dict.insert(S[index]);
            }
            index++;
        }
        result.push_back(right - start + 1);
        if (right < S.length() - 1) {
            partitionRecursive(S, right + 1, result);
        }
    }
};
// @lc code=end

