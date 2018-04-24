allLengths : List String -> List Nat
allLengths [] = []
allLengths (x :: xs) = length x :: allLengths xs



xor : Bool -> Bool -> Bool
xor False yy = yy
xor True yy = not yy
