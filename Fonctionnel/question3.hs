module Question3 (countpos) where

-- Question 3 (2pts)
--
-- Soit un nombre entier positif N. Donner le nombre de possibilité d'écrire N
-- sous la forme
--
--      N = A*i + B*j + C*k,
--
-- où i, j et k sont des entiers positifs (zéro inclut) et A=5, B=15 et C=20.
constA =  5
constB = 15
constC = 20
countpos :: Int -> Int
countpos n = countpos_ n 0 0

countpos_ :: Int -> Int -> Int -> Int
countpos_ n c l =
    if c < n
    then countposA + countposB + countposC
    else if c == n then 1 else 0
    where
        countposN = \x -> if l <= x then countpos_ n (c + x) x else 0
        countposA = countposN constA
        countposB = countposN constB
        countposC = countposN constC
