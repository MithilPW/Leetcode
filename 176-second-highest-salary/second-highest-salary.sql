select IFNULL((
select distinct salary 
from
(
select salary ,
Dense_rank() over  (order by salary DESC)  as rankkeked
from employee
) t
where rankkeked  = 2
),NULL) as SecondHighestSalary

