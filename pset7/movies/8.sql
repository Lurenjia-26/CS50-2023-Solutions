SELECT name FROM movie, stars, people
WHERE id IN (
    SELECT stars.person_id FROM stars
    WHERE stars.person_id = people.id
    AND stars.movie_id IN (
        SELECT id FROM movies
        WHERE title = "Toy Story"
    )
);