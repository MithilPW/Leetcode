# Write your MySQL query statement below
Select max(num) as num from(
select num , count(num) from mynumbers 
group by num 
having count(num) = 1
) t;