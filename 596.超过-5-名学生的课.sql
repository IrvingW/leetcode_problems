--
-- @lc app=leetcode.cn id=596 lang=mysql
--
-- [596] 超过5名学生的课
--
-- https://leetcode-cn.com/problems/classes-more-than-5-students/description/
--
-- database
-- Easy (41.88%)
-- Likes:    202
-- Dislikes: 0
-- Total Accepted:    68.1K
-- Total Submissions: 162.5K
-- Testcase Example:  '{"headers": {"courses": ["student", "class"]}, "rows": {"courses": [["A", "Math"], ["B", "English"], ["C", "Math"], ["D", "Biology"], ["E", "Math"], ["F", "Computer"], ["G", "Math"], ["H", "Math"], ["I", "Math"]]}}'
--
-- 有一个courses 表 ，有: student (学生) 和 class (课程)。
--
-- 请列出所有超过或等于5名学生的课。
--
-- 例如，表：
--
-- +---------+------------+
-- | student | class      |
-- +---------+------------+
-- | A       | Math       |
-- | B       | English    |
-- | C       | Math       |
-- | D       | Biology    |
-- | E       | Math       |
-- | F       | Computer   |
-- | G       | Math       |
-- | H       | Math       |
-- | I       | Math       |
-- +---------+------------+
--
--
-- 应该输出:
--
-- +---------+
-- | class   |
-- +---------+
-- | Math    |
-- +---------+
--
--
--
--
-- 提示：
--
--
-- 学生在每个课中不应被重复计算。
--
--
--

-- @lc code=start
# Write your MySQL query statement below

SELECT
    class
FROM
    courses
GROUP BY
    class
HAVING
    count(DISTINCT student) >= 5;
-- @lc code=end

