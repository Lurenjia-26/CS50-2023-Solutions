-- Keep a log of any SQL queries you execute as you solve the mystery.

-- What tables does it have.
.schema
.tables

-- Get more information about this table.
.schema crime_scene_reports

-- Find descriptions of the crime on a particular day and particular street.
SELECT description
FROM crime_scene_reports
WHERE month = 7
AND day = 28
AND street = 'Humphrey Street';

-- Get more information about this table.
.schema interviews

-- View the interview records of three witnesses
SELECT name, transcript
FROM interviews
WHERE year = 2021
AND month = 7
AND day = 28
AND transcript LIKE '%bakery%';

-- Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
-- If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
-- Find all the people who got out of the parking lot.
SELECT name
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE month = 7
    AND day = 28
    AND hour = 10
    AND minute > 15
    AND minute <= 25
    AND activity = 'exit'
)
ORDER BY name;
-- +---------+
-- |  name   |
-- +---------+
-- | Bruce   |
-- | Barry   |
-- | Diana   |
-- | Iman    |
-- | Kelsey  |
-- | Luca    |
-- | Sofia   |
-- | Vanessa |
-- +---------+

-- I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery,
-- I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- Find the person who withdraws money on Leggett Street that day.
SELECT name
FROM people, bank_accounts
WHERE people.id = bank_accounts.person_id
AND