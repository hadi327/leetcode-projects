# Write your MySQL query statement below
SELECT
    request_at AS Day,
    ROUND(
        SUM(status != 'completed') / COUNT(*),
        2
    ) AS `Cancellation Rate`
FROM Trips
WHERE request_at BETWEEN '2013-10-01' AND '2013-10-03'
  AND client_id IN (
      SELECT users_id
      FROM Users
      WHERE banned = 'No'
        AND role = 'client'
  )
  AND driver_id IN (
      SELECT users_id
      FROM Users
      WHERE banned = 'No'
        AND role = 'driver'
  )
GROUP BY request_at;