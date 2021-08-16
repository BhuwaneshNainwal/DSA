1> Hash the pattern first.
2> Hash the text with pattern length using rolling hash techniques.
3> Rolling hash technique: Iterate the text from left to right taking lenght of pattern as window now divide 
that window by p (prime) modulo mod and add the last hash value of new window. 