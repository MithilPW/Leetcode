# Write your MySQL query statement below
SELECT eu.unique_id , e.name
FROM 
Employees as e
LEFT JOIN
EMPLOYEEUNI As eu
ON e.id = eu.id
