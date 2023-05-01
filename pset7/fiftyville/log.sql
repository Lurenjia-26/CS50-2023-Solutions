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
AND transcript LIKE "%thief%";