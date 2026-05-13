# Write your MySQL query statement below
Select project_id , Round(AVG(experience_years),2) as 
average_years 
from Project 
Inner Join
Employee on Project.employee_id = Employee.employee_id
group by project_id;