SELECT title
FROM movies, stars, ratings, people
WHERE stars.person_id = people.id
AND stars.movie_id = movies.id
AND ratings.movie_id = movies.id
AND people.name = "Chadwick Boseman"
ORDER BY rating DESC
LIMIT 5;