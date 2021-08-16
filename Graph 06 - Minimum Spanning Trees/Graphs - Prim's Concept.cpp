Prims algorithm:

V = []								//Set of all vertices
MST set = [] 						//Set of all vertices that at the moment already included in MST 
Active edge = edge from a vertex  	//Edges from a node in MST to a node in V
MST edge = edge that has been included in the MST we have build so far.


Algorithm:

1> Start from any source vertex and include in MST set.

2> Out of all active edges , pick the one with smallest weight

	a> Select Y in MST
	b> Add edges starting from Y in the active edge list

3> It's greedy algorithm.