# Write your MySQL query statement below
Select query_name , ROUND(AVG(rating/position),2) 
as quality ,ROUND(Sum(rating < 3)/Count(*) * 100,2)
as poor_query_percentage 
from queries
group by query_name