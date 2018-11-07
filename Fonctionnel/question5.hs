module Question5 (SearchTree, buildSearchTree, checkWordInSearchTree) where

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
data SearchTree = Node deriving (Eq, Show) -- À MODIFIER

buildSearchTree :: [String] -> SearchTree
buildSearchTree xs = Node -- À MODIFIER

checkWordInSearchTree :: SearchTree -> String -> Bool
checkWordInSearchTree t w = False -- À MODIFIER
