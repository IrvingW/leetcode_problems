--
-- @lc app=leetcode.cn id=184 lang=mysql
--
-- [184] 部门工资最高的员工
--
-- https://leetcode-cn.com/problems/department-highest-salary/description/
--
-- database
-- Medium (47.17%)
-- Likes:    374
-- Dislikes: 0
-- Total Accepted:    82.8K
-- Total Submissions: 175.6K
-- Testcase Example:  '{"headers": {"Employee": ["Id", "Name", "Salary", "DepartmentId"], "Department": ["Id", "Name"]}, "rows": {"Employee": [[1, "Joe", 70000, 1], [2, "Jim", 90000, 1], [3, "Henry", 80000, 2], [4, "Sam", 60000, 2], [5, "Max", 90000, 1]], "Department": [[1, "IT"], [2, "Sales"]]}}'
--
-- Employee 表包含所有员工信息，每个员工有其对应的 Id, salary 和 department Id。
--
-- +----+-------+--------+--------------+
-- | Id | Name  | Salary | DepartmentId |
-- +----+-------+--------+--------------+
-- | 1  | Joe   | 70000  | 1            |
-- | 2  | Jim   | 90000  | 1            |
-- | 3  | Henry | 80000  | 2            |
-- | 4  | Sam   | 60000  | 2            |
-- | 5  | Max   | 90000  | 1            |
-- +----+-------+--------+--------------+
--
-- Department 表包含公司所有部门的信息。
--
-- +----+----------+
-- | Id | Name     |
-- +----+----------+
-- | 1  | IT       |
-- | 2  | Sales    |
-- +----+----------+
--
-- 编写一个 SQL 查询，找出每个部门工资最高的员工。对于上述表，您的 SQL 查询应返回以下行（行的顺序无关紧要）。
--
-- +------------+----------+--------+
-- | Department | Employee | Salary |
-- +------------+----------+--------+
-- | IT         | Max      | 90000  |
-- | IT         | Jim      | 90000  |
-- | Sales      | Henry    | 80000  |
-- +------------+----------+--------+
--
-- 解释：
--
-- Max 和 Jim 在 IT 部门的工资都是最高的，Henry 在销售部的工资最高。
--
--

-- @lc code=start
# Write your MySQL query statement below


SELECT
    D.Name Department,
    E.Name Employee,
    M.Salary Salary
FROM
    Department D,
    Employee E,
    (
        SELECT
            MAX(Salary) Salary,
            DepartmentId
        FROM
            Employee
        GROUP BY
            DepartmentId
    ) M
WHERE
    D.Id = M.DepartmentId AND
    D.Id = E.DepartmentId AND
    M.Salary = E.Salary;
-- @lc code=end

