1> It is based on Square root decomposition.

2> For the problem of D-Query type , Firstly , divide the queries in root n and solve them on the basis of
block number.

3> Inside the same block , solve them on the basis of right pointer if j1 < j2 then solve j1 first.

4> Time complexity reduced to O(N * root(N) + Q * root(N))
 
5> Valid for offline queries that it the queries are present before hand.