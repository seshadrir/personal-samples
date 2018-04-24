

data Expr = Val Int
          | Add Expr Expr
          | Sub Expr Expr
          | Mult Expr Expr

evaluate : Expr -> Int
evaluate (Val  x) = x 
evaluate (Add  x y) = evaluate x + evaluate y 
evaluate (Sub  x y) = evaluate x - evaluate y
evaluate (Mult x y) = evaluate x * evaluate y



maxMaybe : Ord a => Maybe a -> Maybe a -> Maybe a
maxMaybe Nothing y = y 
maxMaybe (Just x) Nothing = Just x 
maxMaybe (Just x) (Just y) = Just (max x y)


data Shape = Triangle Double Double
           | Rectangle Double Double
           | Circle Double


area : Shape -> Double
area (Triangle x y) = 0.5*x*y
area (Rectangle x y) = x*y
area (Circle x) = pi*x*x

areaT : Shape -> Maybe Double
areaT (Triangle x y) = Just (0.5*x*y)
areaT (Rectangle x y) = Nothing
areaT (Circle x) = Nothing 

data Picture = Primitive Shape
             | Combine Picture Picture
             | Rotate Double Picture
             | Translate Double Double Picture


biggestTriangle : Picture -> Maybe Double
biggestTriangle (Primitive x) = areaT x
biggestTriangle (Combine x y) = maxMaybe (biggestTriangle x) (biggestTriangle y)
biggestTriangle (Rotate x y) = biggestTriangle y
biggestTriangle (Translate x y z) = biggestTriangle z 

testPic1 : Picture
testPic1 = Combine (Primitive (Triangle 2 3)) (Primitive (Triangle 2 4))
testPic2 : Picture
testPic2 = Combine (Primitive (Rectangle 1 3)) (Primitive (Circle 4))


