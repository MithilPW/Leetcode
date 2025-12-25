# Write your MySQL query statement below
SELECT C.name as Customers
FROM Customers as C left JOIN Orders as O 
ON C.id = O.customerid
WHERE O.customerId is NULL
