/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

#include <string>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        q.push(beginWord);
        int result = 0;
        vector<int> visit(wordList.size(), 0);
        while(!q.empty()) {
            result++;
            string& word = q.front();
            if (word == endWord) {
                return result;
            }
            for (int i = 0; i < wordList.size(); i++) {
                if (isConnect(word, wordList[i]) && visit[i] == 0) {
                    q.push(wordList[i]);
                    visit[i] = 1;
                }
            }
            q.pop();
        }
        return 0;
    }
private:
    bool isConnect(string wordA, string wordB) {
        if (wordA.length() != wordB.length()) return false;
        bool diff = false;
        for (int i = 0; i < wordA.length(); i++) {
            if (wordA[i] != wordB[i] && !diff) {
                diff = true;
            } else {
                return false;
            }
        }
        return false;
    }
};
// @lc code=end

