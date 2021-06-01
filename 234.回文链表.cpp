/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        ListNode* rightTail = findMid(head);
        ListNode* right = reverse(rightTail);
        ListNode* left = head;
        while(right != nullptr) {
            if (left->val != right->val) return false;
            right = right->next;
            left = left->next;
        }
        return true;
    }
private:
    // 反转链表
    ListNode* reverse(ListNode* head) {
        ListNode* newHead = new ListNode();
        while(head != nullptr) {
            ListNode* next = head->next;
            head->next = newHead->next;
            newHead->next = head;
            head = next;
        }
        return newHead->next;
    }

private:
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != nullptr) slow = slow->next;
        return slow;
    }
};
// @lc code=end

