# Write your MySQL query statement below
select id , movie , description , rating from cinema 
Where
description  != 'boring' AND 
id % 2 = 1
order by rating desc