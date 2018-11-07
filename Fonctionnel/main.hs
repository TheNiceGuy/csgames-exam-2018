import Test.HUnit
import Question1 (rev)
import Question2 (sortlen)
import Question3 (countpos)
import Question4 (countcase)
import Question5 (SearchTree, buildSearchTree, checkWordInSearchTree)

-- Exécution des tests, ne pas modifier. Sinon, vous êtes disqualifié.
-- En fait, touchez pas à ce fichier.

question1test01 = TestCase (assertEqual "simple" "yako" $ rev "okay")
question1test02 = TestCase (assertEqual "list" [4,3,2,1] $ rev [1,2,3,4])

question2test01 = TestCase (assertEqual "simple" ["aa","bb"] $ sortlen ["bb","aa"])
question2test02 = TestCase (assertEqual "capital" ["ABC","AAAA","zzz"] $ sortlen ["zzz","ABC","AAAA"])

question3test01 = TestCase (assertEqual "for 20"      3 $ countpos 20)
question3test02 = TestCase (assertEqual "for 25"      3 $ countpos 25)
question3test03 = TestCase (assertEqual "for 30"      4 $ countpos 30)
question3test04 = TestCase (assertEqual "for 2000" 6801 $ countpos 2000)

question4test01 = TestCase (assertEqual "case 1"  2 $ countcase ">")
question4test02 = TestCase (assertEqual "case 2"  4 $ countcase "^>v<")
question4test03 = TestCase (assertEqual "case 3"  2 $ countcase "^v^v^v^v^v")
question4test04 = TestCase (assertEqual "case 4" 19 $ countcase "^^^^<v<v<^v<<v<<v^>>>>")

searchTree = buildSearchTree ["pere", "perte", "perdu", "parent", "roger", "poire", "pomme"]
question5test01 = TestCase (assertEqual "good 1"  True  $ checkWordInSearchTree searchTree "pere")
question5test02 = TestCase (assertEqual "good 2"  True  $ checkWordInSearchTree searchTree "perte")
question5test03 = TestCase (assertEqual "good 3"  True  $ checkWordInSearchTree searchTree "perdu")
question5test04 = TestCase (assertEqual "good 4"  True  $ checkWordInSearchTree searchTree "parent")
question5test05 = TestCase (assertEqual "good 5"  True  $ checkWordInSearchTree searchTree "roger")
question5test06 = TestCase (assertEqual "good 6"  True  $ checkWordInSearchTree searchTree "poire")
question5test07 = TestCase (assertEqual "good 7"  True  $ checkWordInSearchTree searchTree "pomme")
question5test08 = TestCase (assertEqual "bad 1"   False $ checkWordInSearchTree searchTree "pa")
question5test09 = TestCase (assertEqual "bad 2"   False $ checkWordInSearchTree searchTree "")
question5test10 = TestCase (assertEqual "bad 3"   False $ checkWordInSearchTree searchTree "pommee")
question5test11 = TestCase (assertEqual "bad 4"   False $ checkWordInSearchTree searchTree "parenter")

main = runTestTT $ TestList
    [ TestLabel "question 1 -- test 1"  question1test01
    , TestLabel "question 1 -- test 2"  question1test02
    , TestLabel "question 2 -- test 1"  question2test01
    , TestLabel "question 2 -- test 2"  question2test02
    , TestLabel "question 3 -- test 1"  question3test01
    , TestLabel "question 3 -- test 2"  question3test02
    , TestLabel "question 3 -- test 3"  question3test03
    , TestLabel "question 3 -- test 4"  question3test04
    , TestLabel "question 4 -- test 1"  question4test01
    , TestLabel "question 4 -- test 2"  question4test02
    , TestLabel "question 4 -- test 3"  question4test03
    , TestLabel "question 4 -- test 4"  question4test04
    , TestLabel "question 5 -- test 1"  question5test01
    , TestLabel "question 5 -- test 2"  question5test02
    , TestLabel "question 5 -- test 3"  question5test03
    , TestLabel "question 5 -- test 4"  question5test04
    , TestLabel "question 5 -- test 5"  question5test05
    , TestLabel "question 5 -- test 6"  question5test06
    , TestLabel "question 5 -- test 7"  question5test07
    , TestLabel "question 5 -- test 8"  question5test08
    , TestLabel "question 5 -- test 9"  question5test09
    , TestLabel "question 5 -- test 10" question5test10
    , TestLabel "question 5 -- test 11" question5test11
    ]

