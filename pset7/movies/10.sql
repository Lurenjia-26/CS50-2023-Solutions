SELECT DISTINCT(name)
FROM directors, ratings, people
WHERE 
AND stars.movie_id = movies.id
AND movies.year = 2004
ORDER BY people.birth;