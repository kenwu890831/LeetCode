# Write your MySQL query statement below
SELECT name AS Customers
FROM Customers
LEFT JOIN Orders AS orders ON customers.id = orders.customerId
WHERE orders.customerId IS NULL ;