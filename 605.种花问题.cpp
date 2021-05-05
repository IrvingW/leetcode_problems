/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (n == 0) return true;
            if (flowerbed[i] == 1) continue;
            else {
                if (i - 1 > 0 && i + 1 < flowerbed.size()) {
                    if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                        n--;
                        flowerbed[i] = 1;
                    }
                } else if (flowerbed.size() == 1 && flowerbed[i] == 0) {
                        n--;
                        flowerbed[i] = 1;
                } else if (i == 0 && flowerbed[1] == 0) {
                        n--;
                        flowerbed[i] = 1;
                } else if (i == flowerbed.size() - 1 && flowerbed[i - 1] == 0) {
                        n--;
                        flowerbed[i] = 1;
                }
            }
        }
        return n == 0;
    }
};
// @lc code=end

