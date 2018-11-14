module Question5 (SearchTree, buildSearchTree, checkWordInSearchTree) where

import qualified Data.Map as M
import           Data.Maybe

-- Question 5 (5pts)
--
-- À partir d'une liste de mot, écrivez:
--
--      * une structure de données définissant un arbre de recherche
--      * une fonction construisant un arbre de recherche
--      * une fonction permettant d'identifier un mot dans cet arbre
--
-- Par exemple, l'arbre de recherche contenant les mots "perdre", "perte",
-- "jai", "perdu", "perd" et "pere" est
--
--    │
--    ├─j
--    │ └─a
--    │   └─i (mot)
--    └─p
--      └───e
--          └───r
--              ├───d (mot)
--              │   ├───r
--              │   │   └───e (mot)
--              │   └───u (mot)
--              ├───e (mot)
--              └───t
--                  └───e (mot)
--
data SearchTree = Node (M.Map Char SearchTree, Bool)
    deriving (Eq, Show)

emptySearchTree :: SearchTree
emptySearchTree = Node (M.empty, False)

insertWordInTree :: SearchTree -> String -> SearchTree
insertWordInTree (Node (m, b)) []      = Node (m, True)
insertWordInTree (Node (m, b)) (x:xs)  =
    if isJust nextnode
    then Node (M.insert x updatenode m, b)
    else Node (M.insert x newnode    m, b)
    where
        nextnode = M.lookup x m
        updatenode = insertWordInTree (fromJust nextnode)     xs
        newnode    = insertWordInTree (Node (M.empty, False)) xs

buildSearchTree :: [String] -> SearchTree
buildSearchTree xs = foldl (\acc w -> insertWordInTree acc w) emptySearchTree xs

checkWordInSearchTree :: SearchTree -> String -> Bool
checkWordInSearchTree t w = isFinalState iterate
    where
        advance t c = case t of (Just (Node (n, _))) -> M.lookup c n
                                otherwise            -> Nothing
        iterate = foldl advance (Just t) w
        isFinalState t = case t of (Just (Node (_,True))) -> True
                                   otherwise              -> False

showTree :: SearchTree -> Int -> String
showTree (Node (m, b)) l = if M.size m == 0 then leaf else concat $ M.mapWithKey branch m
    where
        tabs = (take l $ repeat ' ')
        branch k n = tabs ++ (' ':(k:" --> \n")) ++ (showTree n (l+1))
        leaf = tabs ++ (show b) ++ "\n"
