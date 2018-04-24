import Data.Vect

sumEntries : Num a => (pos : Integer) -> Vect n a -> Vect n a -> Maybe a
sumEntries {n} pos xs ys = (case integerToFin pos n  of
                                 Nothing => Nothing 
                                 (Just idx) => Just (index idx xs + index idx ys)) 



sumInputs : Integer -> String -> Maybe (String, Integer)
sumInputs tot inp = let val = cast inp in
                       if val < 0
                         then Nothing
                         else let newVal = tot + val in
                                  Just ("Subtotal : " ++ show newVal ++ "\n", newVal)



main : IO ()
main = replWith 0 "Value:" sumInputs
