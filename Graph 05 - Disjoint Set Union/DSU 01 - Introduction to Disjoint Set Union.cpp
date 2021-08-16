DSU basics:

1> Related to pairwise distinct sets.

2> find(x) - It finds in which x lies.

3> union(x , y) - Combines the sets in which x and y lies into one.  

4> Used for undirected graphs.

5> Used for cycle detection in graphs.

6> Both union() and find() takes O(n) times but can be optimised using 	path compression and union by rank method.

7> Path compression alone optimises the whole algorithm to O(log n) whereas after applying union by rank time complexity
optimises upto O(1).