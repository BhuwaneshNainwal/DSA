/*
	Let there are n nodes numbered from 1 , 2 , 3 , ... , n.
	
	Let f(n) be the total number of BST.

	Let's pick arbitrary i as the root node . Let , number of subtrees at the left of i be x and number
	of subtrees at the right of i be y.
	So , x = f(i - 1) and y = f(n - i)

	Hence , total number of BST are : f(n) = sum over i = 0 to n ( f(i - 1) * f(n - i) )
	Base case : f(0) = 1 (null tree) , f(1) = 1
	This is equivalent to Catalan number : 2n C n / (n + 1) 
	
	Unlabelled Binary trees : 2n C n / (n + 1)
	Binary trees : 2n C n / (n + 1) * n!
 

*/