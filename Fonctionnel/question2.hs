module Question2 (sortlen) where

import qualified Data.List as L
import           Data.Char

-- Question 2 (1pts)
--
-- Trier une liste de chaîne de caractères en fonction de la somme ascii des
-- caractères.
sortlen :: [String] -> [String]
sortlen xs = L.sortBy predicate xs
    where
        predicate = \a b -> compare (suml a) (suml b)
        suml = \xs -> sum $ map ord xs
