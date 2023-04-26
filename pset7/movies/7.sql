SELECT ratings.rating, movies.title
FROM movies
INNER JOIN ratings ON movies.id = ratings.Movie_id
WHERE movies.year = 2010
ORDER BY ratings.rating, movies.title DESC;