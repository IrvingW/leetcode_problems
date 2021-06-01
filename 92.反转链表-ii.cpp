/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (54.21%)
 * Likes:    909
 * Dislikes: 0
 * Total Accepted:    166.4K
 * Total Submissions: 306.9K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left  。请你反转从位置 left 到位置 right 的链表节点，返回
 * 反转后的链表 。
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,3,4,5], left = 2, right = 4
 * 输出：[1,4,3,2,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [5], left = 1, right = 1
 * 输出：[5]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点数目为 n
 * 1
 * -500
 * 1
 *
 *
 *
 *
 * 进阶： 你可以使用一趟扫描完成反转吗？
 *
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* preHead = new ListNode(0, head);
        ListNode* preNode = preHead;
        for (int i = 1; i < left; i++) {
            if (preNode == nullptr) return nullptr;
            preNode = preNode->next;
        }
        preNode->next = reverseN(preNode->next, right - left + 1);
        return preHead->next;
    }
private:
    ListNode* reverseN(ListNode* head, int size) {
        if (size == 1) {
            successor = head->next;
            return head;
        }
        ListNode* last = reverseN(head->next, size - 1);
        head->next->next = head;
        head->next = successor;
        return last;
    }
private:
    ListNode* successor;
};
// @lc code=end

