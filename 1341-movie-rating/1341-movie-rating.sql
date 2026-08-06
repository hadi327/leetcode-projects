SELECT name AS results
FROM Users
WHERE user_id = (
    SELECT mr.user_id
    FROM MovieRating mr
    JOIN Users u
    ON mr.user_id = u.user_id
    GROUP BY mr.user_id, u.name
    ORDER BY COUNT(*) DESC, u.name ASC
    LIMIT 1
)

UNION ALL

SELECT title AS results
FROM Movies
WHERE movie_id = (
    SELECT mr.movie_id
    FROM MovieRating mr
    JOIN Movies m
    ON mr.movie_id = m.movie_id
    WHERE created_at >= '2020-02-01'
      AND created_at < '2020-03-01'
    GROUP BY mr.movie_id, m.title
    ORDER BY AVG(rating) DESC, m.title ASC
    LIMIT 1
);