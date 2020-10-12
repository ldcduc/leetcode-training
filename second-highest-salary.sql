/* Problem url: https://leetcode.com/problems/second-highest-salary
 * Code by: ldcduc
 * */
/* Begin of Solution */
# Write your MySQL query statement below
select Max(Salary) as SecondHighestSalary
from Employee E1
where E1.Salary < (
    select Max(salary)
    from Employee E2
)
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
