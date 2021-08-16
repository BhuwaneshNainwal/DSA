Concept:

1> Sparse table is the matrix in which range - query can be performed in O(log n) time and Idempotent functions like min
, max , gcd etc can be perfomed in O(1) time.

2> mat[i][j] will contain the range [i , i + (2 ^ j) - 1].

3> [i till i + len] = [i till len / 2] + [i + 4 till len / 2]

4> Advantage of using Sparse table is that it performs query in O(1) for Idempotent functions and other type of queries in log(n).

5> Disadvantage of using Sparse table is that it doesn't support update operation. 

6> Building Sparse table takes O(n log n) time where n is the size of the input array.