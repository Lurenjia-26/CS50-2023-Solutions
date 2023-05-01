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
-- | Barry   |1
-- | Bruce   |1
-- | Diana   |1
-- | Iman    |1
-- | Kelsey  |1
-- | Luca    |1
-- | Sofia   |1
-- | Vanessa |1
-- +---------+

-- I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery,
-- I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
-- Find the person who withdrew money on Leggett Street.
SELECT name
FROM people, bank_accounts
WHERE people.id = bank_accounts.person_id
AND account_number IN (
    SELECT account_number
    FROM atm_transactions
    WHERE month = 7
    AND day = 28
    AND atm_location = 'Leggett Street'
    AND transaction_type = 'withdraw'
)
ORDER BY name;
-- +---------+
-- |  name   |
-- +---------+
-- | Benista | 2
-- | Brooke  | 2
-- | Bruce   |12
-- | Diana   |12
-- | Iman    |12
-- | Kenny   | 2
-- | Luca    |12
-- | Taylor  | 2
-- +---------+

-- As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
-- In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
-- The thief then asked the person on the other end of the phone to purchase the flight ticket.
-- The thief bought the earliest ticket for tomorrow
SELECT name
  FROM people
 WHERE passport_number IN (
    SELECT passport_number
    FROM passengers
    WHERE flight_id IN (
        SELECT id
        FROM flights
        WHERE year = 2021
        AND month = 7
        AND day = 29
        AND origin_airport_id IN (
            SELECT id
            FROM airports
            WHERE city = 'Fiftyville'
        )
        ORDER BY hour ASC
        LIMIT 1
    )
)
 ORDER BY name;
-- +--------+
-- |  name  |
-- +--------+
-- | Bruce  |123
-- | Doris  |  3
-- | Edward |  3
-- | Kelsey |1 3
-- | Kenny  | 23
-- | Luca   |123
-- | Sofia  |1 3
-- | Taylor | 23
-- +--------+

-- Find people who called less than a minute that day.
SELECT name
FROM people
WHERE phone_number IN (
    SELECT caller
    FROM phone_calls
    WHERE month = 7
    AND day = 28
    AND duration < 60
)
ORDER BY name;
-- Bruce!
-- Bruce called
SELECT *
FROM people
WHERE name = 'Bruce';