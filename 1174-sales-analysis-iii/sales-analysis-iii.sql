# Write your MySQL query statement below
Select distinct product_id , product_name 
from product
natural Inner JOIN
sales 
where product_id not in (select product_id from sales where
sale_date not between '2019-01-01' AND '2019-03-31');

