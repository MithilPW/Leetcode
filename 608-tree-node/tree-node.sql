# Write your MySQL query statement below
select id , 
    CASE
    WHEN p_id IS NULL THEN 'Root'
    When id IN (SELECT p_id from tree)then 'Inner'
    Else 'Leaf'
    END
as type from tree;
