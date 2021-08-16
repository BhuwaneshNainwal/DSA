For Fulkerson Algorithm:

1> So flow <= Maximum capacity of an edge
2> The amount of flow going inside at every vertex should be equal to flow going outside (excluding source and sink).
3> Our objective is to maximize the flow of the given network graph.
4> We have to make sure no edge goes into the source and no edge comes out of the source.
5> Non zero backward edge and a non full forward edge.

Algorithm:

1> Setup our directed residual graph with edge capacity = original graph weight.
2> Max flow = 0
3> While(there exist any augmented path from source to sink)
{

	a> Find 'f' , the minimum edge weight along the current path.
	b> Decrease the capacity of all the forward edges by f.
	c> Increase the capacity of all backward edges by f.
	d> max_flow = f.
}

print(max_flow)

4> The use of bfs in For Fulkerson Algorithm is also known as Edmond Karp Algorithm.
