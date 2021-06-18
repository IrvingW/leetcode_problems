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
        ListNode* right = findMidNode(head);
        right = reverseList(right);
        ListNode* left = head;
        while(right != nullptr) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
private:
    ListNode* reverseList(ListNode* head) {
        ListNode dummy = ListNode();
        ListNode* cur = head;
        while(cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = dummy.next;
            dummy.next = cur;
            cur = next;
        }
        return dummy.next;
    }

    ListNode* findMidNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return (fast == nullptr) ? slow : slow->next;
    }
};
// @lc code=end

