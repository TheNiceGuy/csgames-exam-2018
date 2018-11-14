module Question4 (countcase) where

import qualified Data.Set  as S

-- Question 4 (3pts)
--
-- Soit les caractères '^', '>', 'v' et '<' définissant respectivement un
-- mouvement de une unité vers le haut, la droite, le bas et la gauche. Soit
-- une suite de mouvement, donné le nombre de case unique visitée.
--
-- La suite "<><><><><><><>" visite 2 cases différentes.
-- La suite "<^>v" visite 4 cases différentes.
-- La suite "<v<v<v<v<" visite 10 cases différentes,
countcase :: String -> Int
countcase xs = getlen travel
    where
        start = (0,0)
        init = (S.singleton start, start)
        func = \(s,p) c -> (S.insert (move c p) s, (move c p))
        travel = foldl func init xs
        getlen = \(s,p) -> S.size s

move :: Char -> (Int, Int) -> (Int, Int)
move '^' (x,y) = (x  ,y+1)
move '>' (x,y) = (x+1,y  )
move 'v' (x,y) = (x  ,y-1)
move '<' (x,y) = (x-1,y  )
