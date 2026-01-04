# Write your MySQL query statement below
SELECT e.name,b.bonus
FROM 
employee as e
LEFT JOIN
bonus as b
ON
e.empID = b.empid

WHERE 
b.bonus < 1000
OR b.bonus is null