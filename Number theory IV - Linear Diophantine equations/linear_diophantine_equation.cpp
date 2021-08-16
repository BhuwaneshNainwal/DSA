It gives the solution of linear equation in two variables of the form ,
a * x + b * y = c , where x and y are two unknowns and a , b and c are constants

let gcd(a , b) = g and a = g * k1 and b = g * k2 
so , g * k1 * x + g * k2 * y = c
k1 * x + k2 * y = c / g 
as RHS is integer so c % g must be zero for this equation having solution
if one solution exists it would have infinitely many solutions
solutions :
		x0 = x * c / g 				y0 = y * c / g
		xi = x0 + i * b / g 		yi = y0 - i * a / g