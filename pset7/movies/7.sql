SELECT ratings.rating, movies.title
FROM ratings
INNER JOIN movies ON movies.id = ratings.movie_id
WHERE movies.year = 2010
ORDER BY ratings.rating, movies.title DESC;