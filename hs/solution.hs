{-# OPTIONS_GHC -Wno-incomplete-patterns #-}

merge (x:xs) (y:ys) | x < y     = x : merge xs (y:ys)
                    | x > y     = y : merge (x:xs) ys
                    | x == y    = x : merge xs ys


prime = filter (not . null) $ map (flip take [2..]) $ iterate (merge [2,3,5,7]) [2,3,5,7]


main = do mapM_ print $ take 10000000 prime
