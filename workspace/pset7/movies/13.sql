SELECT DISTINCT(name)
FROM movies, stars, people
WHERE stars.person_id = people.id
AND stars.movie_id = movies.id
AND people.name != "Kevin Bacon"
AND title IN (
    SELECT title
    FROM movies, stars, people
    WHERE stars.person_id = people.id
    AND stars.movie_id = movies.id
    AND people.name = "Kevin Bacon"
    AND birth = 1958
);