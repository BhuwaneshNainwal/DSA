
1> SCC is related to directed graph.

2> Kosaraju's algorithm is used to find number of strongly connected components in directed graph.

3> Steps :
a> Do dfs and get the ordering based on finish time.
b> Reverse the graph (reverse the directed edge)
c> Do dfs from right to left.

4> Refer to CLRS for more mathematical proof.