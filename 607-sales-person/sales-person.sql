# Write your MySQL query statement below

Select name from salesperson WHERE sales_id NOT in(
Select o.sales_id 
From orders as o
Inner Join Company as c
ON o.com_id = c.com_id
Where c.name = 'RED'
);