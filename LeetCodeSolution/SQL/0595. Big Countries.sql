
select name , area , population 
from world
where area >= 3000000 or population >= 25000000;





select product_id 
from Products
where low_fats = 'Y' and recyclable = 'Y'



select name
from Customer
where referee_id != 2 or referee_id is null





https://leetcode.com/problems/combine-two-tables/
SELECT firstName,lastName,city,state
FROM Person LEFT JOIN Address ON Person.personId = Address.personId




https://leetcode.com/problems/second-highest-salary/
SELECT MAX(salary) as SecondHighestSalary
FROM Employee
WHERE salary NOT IN (SELECT MAX(salary) from Employee)
/* doesn't return null value 
SELECT salary as SecondHighestSalary
FROM Employee
ORDER BY salary DESC
LIMIT 1 OFFSET 1;
*/



https://leetcode.com/problems/nth-highest-salary/
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N-1;
  RETURN (
      # Write your MySQL query statement below.
        SELECT DISTINCT(salary)
        FROM Employee ORDER BY salary DESC LIMIT 1 OFFSET N
  );
END
