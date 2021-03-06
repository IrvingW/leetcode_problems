--
-- @lc app=leetcode.cn id=181 lang=mysql
--
-- [181] 超过经理收入的员工
--
-- https://leetcode-cn.com/problems/employees-earning-more-than-their-managers/description/
--
-- database
-- Easy (70.33%)
-- Likes:    373
-- Dislikes: 0
-- Total Accepted:    134.3K
-- Total Submissions: 191K
-- Testcase Example:  '{"headers": {"Employee": ["Id", "Name", "Salary", "ManagerId"]}, "rows": {"Employee": [[1, "Joe", 70000, 3], [2, "Henry", 80000, 4], [3, "Sam", 60000, null], [4, "Max", 90000, null]]}}'
--
-- Employee 表包含所有员工，他们的经理也属于员工。每个员工都有一个 Id，此外还有一列对应员工的经理的 Id。
--
-- +----+-------+--------+-----------+
-- | Id | Name  | Salary | ManagerId |
-- +----+-------+--------+-----------+
-- | 1  | Joe   | 70000  | 3         |
-- | 2  | Henry | 80000  | 4         |
-- | 3  | Sam   | 60000  | NULL      |
-- | 4  | Max   | 90000  | NULL      |
-- +----+-------+--------+-----------+
--
--
-- 给定 Employee 表，编写一个 SQL 查询，该查询可以获取收入超过他们经理的员工的姓名。在上面的表格中，Joe
-- 是唯一一个收入超过他的经理的员工。
--
-- +----------+
-- | Employee |
-- +----------+
-- | Joe      |
-- +----------+
--
--
--

-- @lc code=start
# Write your MySQL query statement below

SELECT
    e.Name AS Employee
FROM
    Employee e INNER JOIN Employee m
ON
    e.ManagerId = m.Id
    AND e.Salary > m.Salary;
-- @lc code=end

