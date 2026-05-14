# Write your MySQL query statement below
select IFNULL(
    (
select distinct salary 
from employee
order by salary desc
LIMIT 1 OFFSET 1
),NULL
) as SecondHighestSalary
