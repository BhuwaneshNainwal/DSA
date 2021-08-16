/*

1> Each player can pick a number from either end.
2> Both are smart / equally wise or plays optimally.
3> Maximum margin by which he can win.

Recurrence relation:
				Let the player be A,
								f(i , j) = max(a[i] + min( f(i + 2 , j) , f(i + 1 , j - 1)) , 
								a[j] + min( f(i, j - 2) , f(i + 1 , j - 1))
				
				Base case : if i > j => return 0
*/