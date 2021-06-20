/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (66.81%)
 * Likes:    1181
 * Dislikes: 0
 * Total Accepted:    177.2K
 * Total Submissions: 265.3K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 *
 * 进阶：
 *
 *
 * 你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [4,2,1,3]
 * 输出：[1,2,3,4]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [-1,5,3,4,0]
 * 输出：[-1,0,3,4,5]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [0, 5 * 10^4] 内
 * -10^5 
 *
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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return nullptr;
        int len = 0;
        ListNode* node = head;
        while(node != nullptr) {
            len++;
            node = node->next;
        }
        int subLen = 1;
        ListNode dummy = ListNode(0, head);
        for (; subLen < len; subLen *= 2) {
            ListNode* pre = &dummy;
            ListNode* cur = pre->next;
            while(cur != nullptr) {
                ListNode* head1 = cur;
                for (int i = 0; i < subLen - 1 && cur->next != nullptr; i++) cur = cur->next;
                ListNode* head2 = cur->next;
                cur->next = nullptr;
                cur = head2;
                for (int i = 0; i < subLen - 1 && cur != nullptr && cur->next != nullptr; i++) cur = cur->next;
                ListNode* successor = nullptr;
                if (cur != nullptr) {
                   successor = cur->next;
                   cur->next = nullptr;
                }

                pre->next = merge(head1, head2);
                while(pre->next != nullptr) pre = pre->next;
                cur = successor;
            }
        }
        return dummy.next;
    }

private:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode dummy = ListNode(0);
        ListNode* pre = &dummy;
        while(head1 != nullptr && head2 != nullptr) {
            if (head1->val <= head2->val) {
                pre->next = head1;
                head1 = head1->next;
            } else {
                pre->next = head2;
                head2 = head2->next;
            }
            pre = pre->next;
        }
        if (head1 != nullptr) {
            pre->next = head1;
        } else {
            pre->next = head2;
        }
        return dummy.next;
    }
};
// @lc code=end

// int main(int argc, char const *argv[])
// {
//     ListNode* node = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
//     Solution solution;
//     solution.sortList(node);
//     return 0;
// }


