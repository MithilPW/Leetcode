# Write your MySQL query statement below

Select product_name ,  SUM(unit) 
as unit 
from
products p1
Inner Join
Orders o1
ON p1.product_id = o1.product_id
Where Order_date Between '2020-02-01'
AND 
'2020-02-29'
group by product_name
having unit >= 100
