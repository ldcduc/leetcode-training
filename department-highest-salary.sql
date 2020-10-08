/* Problem url: https://leetcode.com/problems/department-highest-salary
 * Code by: ldcduc
 * */
/* Begin of Solution */
# Write your MySQL query statement below

select D.Name as Department, E.Name as Employee, E.Salary
from Employee E join Department D
on E.DepartmentId = D.Id
where not exists (
    select *
    from Employee E2
    where E.salary < E2.salary and E.DepartmentID = E2.DepartmentID
)
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: 
 * 
 * */
