/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (board.empty() || board[0].empty()) return false;
        int m = board.size();
        int n = board[0].size();
        vector<bool> row(n, false);
        vector<vector<bool>> visited(m, row);
        const char& start = word[0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == start && judge(board, visited, word, i, j))
                    return true;
            }
        }
        return false;
    }
private:
    bool judge(vector<vector<char>>& board, vector<vector<bool>>& visited, const string& word, int x, int y) {
        if (x < 0 || x > board.size())
            return false;
        if (y < 0 || y > board[0].size())
            return false;
        if (visited[x][y]) return false;
        visited[x][y] = true;
        if (word.length() == 1 && board[x][y] == word[0]) {
            return true;
        }
        if (board[x][y] != word[0]) {
            return false;
        }
        string subWord = word.substr(1, word.length() - 1);
        bool result =  judge(board, visited, subWord, x + 1, y) ||
               judge(board, visited, subWord, x, y + 1) ||
               judge(board, visited, subWord, x - 1, y) ||
               judge(board, visited, subWord, x, y - 1);
        if (result) return true;
        else {
            visited[x][y] = false;
            return false;
        }
    }
};
// @lc code=end

