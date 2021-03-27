/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode();
        ListNode *resultTail = result;
        resultTail->next = result;
        auto getValue = [](ListNode* node) -> int {
            if (node == nullptr)
                return 0;
            return node->val;
        };
        auto getNextNode = [](ListNode* node) -> ListNode* {
            if (node == nullptr)
                return nullptr;
            return node->next;
        };
        int ten = 0;
        while(l1 != nullptr || l2 != nullptr) {
            if (resultTail->next == nullptr) {
                resultTail->next = new ListNode();
            }
            resultTail = resultTail->next;
            resultTail->next = nullptr;
            int sum = getValue(l1) + getValue(l2) + ten;
            if (sum >= 10) {
                resultTail->val = sum - 10;
                ten = 1;
            } else {
                resultTail->val = sum;
                ten = 0;
            }
            l1 = getNextNode(l1);
            l2 = getNextNode(l2);
        }
        if (ten == 1) {
            resultTail->next = new ListNode(1);
        }
        return result;
    }
};
// @lc code=end

