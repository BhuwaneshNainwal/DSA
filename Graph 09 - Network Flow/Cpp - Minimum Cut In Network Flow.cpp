
Minimum Cut problem:
1> In a flow network , an ST cut is a cut that requires the source and the sink to be in different subsets and it consists of
all the edges going from source side to sink side.

Sum of the capacity of each edge in the cut:

1> Run the ford algorithm and calculate the final residual graph.1
2> Find the set of vertices that are reachable from the source.
3> All the edges which are non reachable vertex from a reachable vertex are minimum cut edges.