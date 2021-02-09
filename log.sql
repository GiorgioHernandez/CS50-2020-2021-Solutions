-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports WHERE month = 7 and day = 28; -- Theft happened at 10:15am at the courthouse.

SELECT transcript FROM interviews WHERE month = 7 and day = 28; -- The thief escaped in the next 10 minutes in a car.
                                                                -- He was in the ATM on Fifer Street earlier that morning.
                                                                -- The thief is gonna flight tomorrow, and the accomplice purchased the tickets during the runnaway.

SELECT account_number, amount FROM atm_transactions WHERE month = 7 and day = 28 and transaction_type = "withdraw" and atm_location = "Fifer Street"; -- The accounts that withdrawed money at that ATM that morning                                                               

SELECT                                                   -- Personal data of all people that withdrawed money that thay at that ATM
name, phone_number, passport_number, license_plate       -- The Suspects are: 
FROM                                                     -- Ernest           
people                                                   -- Russell
JOIN                                                     -- Roy
bank_accounts                                            -- Bobby
ON                                                       -- Elizabeth
people.id = bank_accounts.person_id                      -- Danielle
JOIN                                                     -- Madison    
atm_transactions                                         -- Victoria
ON 
bank_accounts.account_number = atm_transactions.account_number 
WHERE 
month = 7 and day = 28 and transaction_type = "withdraw" and atm_location = "Fifer Street"; 


SELECT activity, license_plate, hour, minute FROM courthouse_security_logs WHERE month = 7 and day = 28 and hour = 10 and minute >= 15 and minute <= 25 and license_plate in (SELECT 
license_plate                                                             -- Matching the previous suspects with the security logs the suspects are: 
FROM                                                                      -- Elizabeth
people                                                                    -- Ernest
JOIN                                                                      -- Russel
bank_accounts                                                             -- Danielle
ON                                                                        
people.id = bank_accounts.person_id 
JOIN 
atm_transactions 
ON 
bank_accounts.account_number = atm_transactions.account_number 
WHERE 
month = 7 and day = 28 and transaction_type = "withdraw" and atm_location = "Fifer Street");


SELECT airports.id, full_name FROM airports WHERE city = "Fiftyville";  -- Figuring out the name of the airport and it's code
                                                                        -- Fiftyville Reginoal Airport Code: 8

SELECT origin_airport_id, destination_airport_id, people.name
FROM                                     -- Checking the flights the day after matching the passport number with the flight and names. Suspects are:
flights                                  -- Ernest 
JOIN                                     -- Danielle
passengers
ON 
flights.id = passengers.flight_id and
flights.month = 7 and flights.day = 29 and flights.origin_airport_id = 8
JOIN
people
ON
passengers.passport_number = people.passport_number
WHERE
people.name = "Ernest" or people.name = "Russel" or people.name = "Danielle" or people.name = "Elizabeth"; 

SELECT full_name, city FROM airports WHERE id = 4;  -- The city chosen for the thief to escape
                                                    -- London, Heathrow Airport

SELECT caller, people.name, receiver FROM phone_calls          -- Checking who was the accomplice by the phone record
JOIN                                                           -- The (367) 555-5533 had a call that day for a minute, and it was Ernets, so he's the thief.
people
ON
phone_calls.caller = people.phone_number
and phone_calls.duration <= 60
and phone_calls.month = 7 and phone_calls.day = 28
WHERE
people.name = "Ernest" or people.name = "Danielle";  

SELECT name FROM people WHERE phone_number = "(375) 555-8161"; -- The Accomplice is Berthold, the call receiver.