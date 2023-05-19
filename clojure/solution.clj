(defn fib [n] (if (<= n 1) n (+ (fib (- n 1)) (fib (- n 2)))))

(ns solution
  (:require [clojure.test :refer :all]))

(print (fib 10))
