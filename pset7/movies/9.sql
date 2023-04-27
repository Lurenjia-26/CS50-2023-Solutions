SELECT DISTINCT(name)
FROM movies, stars, people
WHERE stars.person_id = people.id
AND stars.movie_id = movies.id
AND movies.year = 2004
ORDER BY people.birth;