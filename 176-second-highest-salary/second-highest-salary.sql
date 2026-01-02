# Write your MySQL query statement below
SELECT MAX(SALARY) as secondhighestsalary
FROM EMPLOYEE 
WHERE SALARY < (SELECT MAX(SALARY) FROM EMPLOYEE);