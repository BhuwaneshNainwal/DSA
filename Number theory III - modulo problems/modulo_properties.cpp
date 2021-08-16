Modulo properties:

When we need value in range 0 to mod - 1 only:

1> (a + b) % mod = (a % mod + b % mod) % mod
2> (a - b) % mod = (a % mod - b % mod + mod) % mod
3> (a * b) % mod = (a % mod * b % mod) % mod
4> (a / b) % mod = (a % mod * (b ^ -1) % mod) % mod , where (b ^ -1) is modulo 
multiplicative inverse

for example ,

(6 * y) % 7 = 1 
so modulo inverse of 6 with respect to 7 is y which is 6
