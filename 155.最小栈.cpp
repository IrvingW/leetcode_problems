/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (56.76%)
 * Likes:    908
 * Dislikes: 0
 * Total Accepted:    239.6K
 * Total Submissions: 422.1K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
 *
 *
 * push(x) —— 将元素 x 推入栈中。
 * pop() —— 删除栈顶的元素。
 * top() —— 获取栈顶元素。
 * getMin() —— 检索栈中的最小元素。
 *
 *
 *
 *
 * 示例:
 *
 * 输入：
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 *
 * 输出：
 * [null,null,null,null,-3,null,0,-2]
 *
 * 解释：
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 *
 *
 *
 *
 * 提示：
 *
 *
 * pop、top 和 getMin 操作总是在 非空栈 上调用。
 *
 *
 */

#include <stack>
#include <math.h>
#include <limits.h>

using namespace std;

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minNumber = INT_MAX;
    }

    void push(int val) {
        dataStack.push(val);
        minNumber = min(minNumber, val);
        minStack.push(minNumber);
    }

    void pop() {
        dataStack.pop();
        minStack.pop();
        minNumber = minStack.empty() ? INT_MAX: minStack.top();
    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return minNumber;
    }

private:
    stack<int> dataStack;
    stack<int> minStack;
    int minNumber;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

