SELECT movies.title, ratings.rating
FROM movies
INNER JOIN ratings ON movies.id = ratings.Movie_id
WHERE movies.year = 2010
ORDER BY ratings.rating, movies.title DESC;