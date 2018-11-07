module Question4 (countcase) where

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
countcase xs = 0 -- À MODIFIER
