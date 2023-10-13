SELECT title
FROM movies, stars, people
WHERE stars.person_id = people.id
AND stars.movie_id = movies.id
AND people.name = "Johnny Depp"
AND title IN (
    SELECT title
    FROM movies, stars, people
    WHERE stars.person_id = people.id
    AND stars.movie_id = movies.id
    AND people.name = "Helena Bonham Carter"
);