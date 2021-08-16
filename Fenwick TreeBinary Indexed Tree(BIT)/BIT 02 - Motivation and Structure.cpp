
Fenwick tree or Binary indexed tree:

1> It is used for range queries.

2> Almost all problems which are solvable with Fenwick tree can be solved by segment tree but reverse is not true.

3> Let n be a number so n & (-n) will turn off all the set bits of n except the rightmost set bit of n
where -n is the 2's complement of n.

4> n -= (n & -n) will turn off the rightmost set bit of n;

5> For ith index of bit array in BIT => le k = position of rightmost set bit of n then r = i and l = i - 2 ^ k + 1.

6> BIT takes O(n) space , O(n log n) time for building Fenwick tree and O(log n) for query.
