CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N = N - 1;
  RETURN (
      # Write your MySQL query statement below.
        Select DISTINCT salary
        From Employee
        Order By salary DESC
        Limit 1 OFFSET N
    );
END