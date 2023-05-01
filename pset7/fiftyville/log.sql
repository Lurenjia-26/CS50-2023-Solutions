-- Keep a log of any SQL queries you execute as you solve the mystery.

-- What tables does it have
.schema
.tables

--Get more information about this table
.schema crime_scene_reports

--Search for descriptions of crime on a particular day and particular street
SELECT description
FROM crime_scene_reports
WHERE month = 7
AND day = 28
AND street = 'Humphrey Street';