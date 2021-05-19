/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (55.00%)
 * Likes:    1305
 * Dislikes: 0
 * Total Accepted:    258.1K
 * Total Submissions: 468.6K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 *
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 *
 *
 *
 * 示例 1：
 *
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 *
 *
 * 示例 2：
 *
 * 输入：lists = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 * 输入：lists = [[]]
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
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
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    /**
     * 归并
     */
    // ListNode* mergeKLists(vector<ListNode*>& lists) {
    //     return merge(lists, 0, lists.size() - 1);
    // }

    /**
     * 优先级队列解法
     */
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Node> q;
        for (ListNode* node : lists) {
            if (node == nullptr) continue;
            q.push({node});
        }
        ListNode* head = new ListNode();
        ListNode* tail = head;
        while(!q.empty()) {
            tail->next = q.top().node;
            if (q.top().node->next != nullptr) {
                q.push({q.top().node->next});
            }
            q.pop();
            tail = tail->next;
        }
        return head->next;
    }
private:
    struct Node {
        Node(ListNode* l) {
            this->node = l;
            this->value = l->val;
        }
        bool operator<(const Node& l2) const {
            return value > l2.value;
        }
        ListNode* node;
        int value;
    };

// private:
    // ListNode* merge(vector<ListNode*>&lists, int left, int right) {
    //     if (left == right) return lists[left];
    //     if (left > right) return nullptr;
    //     int mid = (right + left ) / 2;
    //     ListNode *l = merge(lists, left, mid);
    //     ListNode *r = merge(lists, mid+1, right);
    //     return mergeList(l, r);
    // }

    // ListNode* mergeList(ListNode* left, ListNode* right) {
    //     if (left == nullptr || right == nullptr) return left ? left : right;
    //     ListNode* head = new ListNode();
    //     ListNode* tail = head;
    //     while (left != nullptr && right != nullptr) {
    //         if (left->val < right->val) {
    //             tail->next = left;
    //             left = left->next;
    //         } else {
    //             tail->next = right;
    //             right = right->next;
    //         }
    //         tail = tail->next;
    //     }
    //     tail->next = left ? left : right;
    //     return head->next;
    // }
};
// @lc code=end