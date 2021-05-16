--
-- @lc app=leetcode.cn id=180 lang=mysql
--
-- [180] 连续出现的数字
--
-- https://leetcode-cn.com/problems/consecutive-numbers/description/
--
-- database
-- Medium (48.94%)
-- Likes:    417
-- Dislikes: 0
-- Total Accepted:    70.5K
-- Total Submissions: 144K
-- Testcase Example:  '{"headers": {"Logs": ["Id", "Num"]}, "rows": {"Logs": [[1, 1], [2, 1], [3, 1], [4, 2], [5, 1], [6, 2], [7, 2]]}}'
--
-- 表：Logs
--
--
-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | num         | varchar |
-- +-------------+---------+
-- id 是这个表的主键。
--
--
--
-- 编写一个 SQL 查询，查找所有至少连续出现三次的数字。
--
-- 返回的结果表中的数据可以按 任意顺序 排列。
--
--
--
-- 查询结果格式如下面的例子所示：
--
--
--
--
-- Logs 表：
-- +----+-----+
-- | Id | Num |
-- +----+-----+
-- | 1  | 1   |
-- | 2  | 1   |
-- | 3  | 1   |
-- | 4  | 2   |
-- | 5  | 1   |
-- | 6  | 2   |
-- | 7  | 2   |
-- +----+-----+
--
-- Result 表：
-- +-----------------+
-- | ConsecutiveNums |
-- +-----------------+
-- | 1               |
-- +-----------------+
-- 1 是唯一连续出现至少三次的数字。
--
--
--

-- @lc code=start
# Write your MySQL query statement below

SELECT
    DISTINCT L1.num ConsecutiveNums
FROM
    Logs L1, Logs L2, Logs L3
WHERE
    L1.id = L2.id - 1 AND L2.id = L3.id - 1 AND
    L1.num = L2.num AND L2.num = L3.num;
-- @lc code=end

