
import Data.Vect

palindromeCS : String -> Bool
palindromeCS word = word == reverse word 

palindromeCIS : String -> Bool
palindromeCIS w = let word = toLower w 
                in
                word == reverse word


palindromeL : String -> Bool
palindromeL word = if length word > 10 
                      then 
                        palindromeCS word 
                      else 
                        False


palindromeLL : Nat -> String -> Bool
palindromeLL len word = if length word > len 
                           then 
                            palindromeCS word 
                           else 
                            False

counts : String -> (Nat, Nat)
counts word = (length (words (word)), length word)



invert : Bool -> Bool
invert False = True 
invert True = False

allLengths : List String -> List Nat
allLengths [] = ?allLengths_rhs_1
allLengths (x :: xs) = ?allLengths_rhs_2


