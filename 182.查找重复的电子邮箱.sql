--
-- @lc app=leetcode.cn id=182 lang=mysql
--
-- [182] 查找重复的电子邮箱
--
-- https://leetcode-cn.com/problems/duplicate-emails/description/
--
-- database
-- Easy (79.68%)
-- Likes:    275
-- Dislikes: 0
-- Total Accepted:    151.7K
-- Total Submissions: 190.4K
-- Testcase Example:  '{"headers": {"Person": ["Id", "Email"]}, "rows": {"Person": [[1, "a@b.com"], [2, "c@d.com"], [3, "a@b.com"]]}}'
--
-- 编写一个 SQL 查询，查找 Person 表中所有重复的电子邮箱。
--
-- 示例：
--
-- +----+---------+
-- | Id | Email   |
-- +----+---------+
-- | 1  | a@b.com |
-- | 2  | c@d.com |
-- | 3  | a@b.com |
-- +----+---------+
--
--
-- 根据以上输入，你的查询应返回以下结果：
--
-- +---------+
-- | Email   |
-- +---------+
-- | a@b.com |
-- +---------+
--
--
-- 说明：所有电子邮箱都是小写字母。
--
--

-- @lc code=start
# Write your MySQL query statement below

SELECT
    Email
FROM
    Person
GROUP BY
    Email
HAVING
    count(*) > 1;
-- @lc code=end

