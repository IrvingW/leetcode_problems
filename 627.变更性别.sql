--
-- @lc app=leetcode.cn id=627 lang=mysql
--
-- [627] 变更性别
--
-- https://leetcode-cn.com/problems/swap-salary/description/
--
-- database
-- Easy (80.40%)
-- Likes:    253
-- Dislikes: 0
-- Total Accepted:    73K
-- Total Submissions: 90.8K
-- Testcase Example:  '{"headers":{"salary":["id","name","sex","salary"]},"rows":{"salary":[[1,"A","m",2500],[2,"B","f",1500],[3,"C","m",5500],[4,"D","f",500]]}}'
--
-- 给定一个 salary 表，如下所示，有 m = 男性 和 f = 女性 的值。交换所有的 f 和 m 值（例如，将所有 f 值更改为
-- m，反之亦然）。要求只使用一个更新（Update）语句，并且没有中间的临时表。
--
-- 注意，您必只能写一个 Update 语句，请不要编写任何 Select 语句。
--
-- 例如：
--
-- | id | name | sex | salary |
-- |----|------|-----|--------|
-- | 1  | A    | m   | 2500   |
-- | 2  | B    | f   | 1500   |
-- | 3  | C    | m   | 5500   |
-- | 4  | D    | f   | 500    |
--
--
-- 运行你所编写的更新语句之后，将会得到以下表:
--
-- | id | name | sex | salary |
-- |----|------|-----|--------|
-- | 1  | A    | f   | 2500   |
-- | 2  | B    | m   | 1500   |
-- | 3  | C    | f   | 5500   |
-- | 4  | D    | m   | 500    |
--
--
--

-- @lc code=start
# Write your MySQL query statement below

UPDATE salary
SET
    sex = CHAR(ASCII(sex) ^ ASCII('f') ^ ASCII('m'));
-- @lc code=end

