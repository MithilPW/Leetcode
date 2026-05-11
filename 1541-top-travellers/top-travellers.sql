# Write your MySQL query statement below
 
select name , IFNULL(SUM(distance),0) as travelled_distance 
from users
LEFT JOIN 
rides
on users.id = rides.user_id
group by users.id
order by travelled_distance Desc , name ASC