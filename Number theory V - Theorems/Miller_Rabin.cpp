
/*
	ॐ
		JAI SHREE RAM

		Hare Krishna Hare Krishna Krishna Krishna Hare Hare
		Hare Rama Hare Rama Rama Rama Hare Hare
	
												ॐ
*/

//Written by Bhuwanesh Nainwal
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
pbds;



#define fast            	ios_base::sync_with_stdio(false) , cin.tie(NULL) , cout.tie(NULL)
#define int					long long int
#define vci              	vector<int>
#define vcvci             	vector<vector<int>>
#define vcpi             	vector<pair<int,int>>
#define vcs					vector<string>
#define pb              	push_back
#define mpii             	map<int , int>
#define mpsi             	map<string , int>
#define mpci             	map<char , int>
#define umpii             	unordered_map<int , int>
#define umpsi             	unordered_map<string , int>
#define umpci             	unordered_map<char , int>
#define all(x)				auto it = x.begin() ; it != x.end() ; it++
#define vcc              	vector<char>
#define vcs              	vector<string>
#define sti            		set<int>
#define stc            		set<char>
#define sts            		set<string>
#define pqmx				priority_queue<int>
#define pqmn				priority_queue<int , vi , greater<int>>
#define null            	NULL
#define ff            		first
#define ss              	second
#define stb(x)				__builtin_popcount(x)
#define lzr(x)				__builtin_clz(x)
#define tzr(x)					__builtin_ctz(x)
#define prc(x , y)          fixed << setprecision(y) << x
#define max3(a, b, c)   	max(a, max(b, c))
#define min3(a, b, c)   	min(a, min(b, c))

using namespace std;

const int mod = 1e9 + 7;
const int INF = 1e9;
const int LINF = 1e18;
const int N = 1e4;
const int chkprc = 1e-9;  // Check for precision error in double

/* Choosing r items out of n but don't forget to declare dp and memset it */

// ll dp[N][N];	//Memset it inside main function

// ll combination(int n , int r )
// {
//     if(r == 0 || n == r)
//         return 1;
//     if(dp[n][r] != -1)
//         return dp[n][r];
//     dp[n][r] = combination(n - 1 , r) + combination(n - 1 , r - 1) ;
//     return dp[n][r];
// }

/* End */

/* Depth first search */


// vi adjacency[N];		//Declare them dynamically inside the main function for more than one test cases like new vi [n] and new ll [n]()
// vi visited(N);

// void dfs(ll i)
// {
// 	visited[i] = 1;

// 	for(ll j = 0 ; j < adjacency[i].size() ; j++)
// 	{
// 		if(visited[adjacency[i][j]] == 0)
// 			dfs(adjacency[i][j]);
// 	}
// }

/* End */

/* Breadth first search */

// vi adjacency[N];
// vi visited(N);
// queue<ll> q;

// void bfs(ll k)
// {
// 	//process vertex

// 	visited[k] = 1;
// 	q.push(k);

// 	while(!q.empty())
// 	{
// 		ll i = q.front();
// 		q.pop();
// for(ll j = 0 ; j < adjacency[i].size() ; j++)
// 		{
// 			if(visited[adjacency[i][j]] == 0)
// 			{
// 				//process vertex

// 				visited[adjacency[i][j]] = 1;
// 				q.push(adjacency[i][j]);
// 			}
// 		}
// 	}
// }




/* End */

/* Divisors of a number */

// void divisors(ll n)
// {
// 	   for(ll i = 1 ; i <= sqrt(n) ; i++)
//     {
//         if(n % i == 0)
//         {
//             if(i != n / i)
//             {
//                 cout<<i<<n / i;
//             }
//             else
//                 cout<<i;
//         }
//     }
// }

/* End */

/* Binary exponentiation */

// ll binpow(ll a , ll n)
// {
//
//  ll res = 1;

// 	while(n)
// 	{
// 		if(n % 2 != 0)
// 			res = res * a;

// 		a = a * a;
// 		n = n / 2;
// 	}

// 	return res;
// }

/* End */

/* Greatest comman divisor (Euclid) */

// ll gcd(ll a , ll b)
// {
//     if(b == 0)
//         return a;

//     return gcd(b , a % b);
// }

/* End */

/* Greatest comman divisior (Extended Euclid) */

// ll gcd(ll a , ll b , ll &x , ll &y)
// {
// 		if(b == 0)
// 		{
// 			x = 1;
// 			y = 0;
// 			return a;
// 		}

// 		ll x1 , y1;

// 		ll g = gcd(b , a % b , x1 , y1);
// 		x = y1;
// 		y = x1 - (a / b) * y1;

// 		return g;
// }

/* End */

/* Prime factorisation */

// void pfact(ll n)
// {


//     while(n % 2 == 0)
//     {
// 		cout<<"2"<<" ";
//         n /= 2;
//     }

//     for (ll i = 3; i <= sqrt(n); i = i + 2)
//     {
//         while (n % i == 0)
//         {
// 			cout<<i<<" ";
//             n = n / i;
//         }
//     }

//     if(n > 2)
//         cout<<n<<" ";
// }

/* End */


/* Disjoint Set Union */



// vi parent(N);
// vi depth(N);


// void make_set(ll child)
// {
//     parent[child] = child;
//     depth[child] = 0;
// }

// ll find_set(ll child)
// {
//     if(child == parent[child])
//         return child;

//     ll result = find_set(parent[child]);

//     parent[child] = result;
//     return result;
// }

// void union_set(ll child1 , ll child2)
// {
//     ll parent1 = find_set(child1);
//     ll parent2 = find_set(child2);
//     if(parent1 != parent2)
//     {
//         if(depth[child1] < depth[child2])
//             swap(child1 , child2);
//         parent[child2] = child1;

//         if(depth[child1] == depth[child2])
//             depth[child1]++;
//     }
// }

/* End */

/* Factorial of a number */

// ll fac(ll n)
// {
//     ll ans = 1;
//     for(ll i = 1 ; i <= n ; i++)
//         ans *= i;
//     return ans;
// }

/* End */

/* Euler totient function */

/* O(sqrt(n)) */

// ll phi(ll n)
// {
// 	ll res = n;

// 	for(ll i = 2 ; i * i <= n ; i++)
// 	{
// 		if(n % i == 0)
// 		{
// 			while(n % i == 0)
// 			{
// 				n /= 2;
// 			}
// 			res -= res / i;
// 		}
// 	}
// 	if(n > 1)
// 		res -= res / n;

// 	return res;
// }


/* O(n log log n) for all phi 1 => n , based on sieve */

// vi phi(ll n)
// {
// 	vi p(n + 1);

// 	for(ll i = 0 ; i <= n ; i++)
// 		p[i] = i;

// 	for(ll i = 2 ; i <= n ; i++)
// 	{
// 		if(p[i] == i)
// 		{
// 			for(ll j = i ; j < n ; j += i)
// 				p[j] -= p[j] / i;
// 		}
// 	}
// 	return p;
// }

/* O(n log n) based on division  sum property */

// vi phi(ll n)
// {
// 	vi p(n + 1);
// 	p[0] = 0;
// 	p[1] = 1;
// 	for(ll i = 2 ; i <= n ; i++)
// 		p[i] = i - 1;

// 	for(ll i = 2 ; i <= n ; i++)
// 	{
// 		for(ll j = i * 2 ; j <= n ; j += i)
// 			p[j] -= p[i];
// 	}
// 	return p;
// }

/* End */


/* End */

//Lazy propagation

//Updating a node

// void upd(ll ind , ll l , ll r , ll val)
// {
// 	lazy[ind] += val;

// 	seg[ind] += (r - l + 1) * val;
// }

// void shift(ll ind , ll l , ll r)
// {
// 	ll mid = (l + r) / 2;

// 	upd(2 * ind + 1 , l , mid , lazy[ind]);
// 	upd(2 * ind + 2 , mid + 1 , r , lazy[ind]);

// 	lazy[ind] = 0;
// }

// void range_update(ll ind , ll x , ll y , ll l , ll r , ll val)
// {
// 	if(x > r || y < l)
// 		return;

// 	if(x <= l && r <= y)
// 	{
// 		upd(ind , l , r , val);
// 		return;
// 	}

// 	ll mid = (l + r) / 2;

// 	shift(ind , l , r);

// 	range_update(2 * ind + 1 , x , y , l , mid , val);
// 	range_update(2 * ind + 2 , x , y , mid + 1 , r , val);

// 	seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
// }

// ll sum_query(ll ind , ll x , ll y , ll l , ll r)
// {
// 	if(x > r || l > y)
// 		return 0;

// 	if(l >= x && r <= y)
// 		return seg[ind];

// 	shift(ind , l , r);

// 	ll mid = (l + r) / 2;

// 	return sum_query(2 * ind + 1 , x , y , l , mid) + sum_query(2 * ind + 2 , x , y , mid + 1 , r);

// }


/* End */

/*
-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------
								Do not dare to touch before this
-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------

*/


/*
1> Miller Rabin test is used to check a number is prime or not for
numbers upto <= 10 ^ 18.

2> It uses the concept of Fermat's little theorem.

3> a ^ m - 1 mod m = 1 , where m is prime but it may be true for some
composite numbers which are known Miller Rabin pseudo primes.

4> Euclid's lemma , (x * y) % m = 0 , then if m is prime it will definitely
divide at least one of them ( x or y or both).

5> Base cases => n = 1 is not prime , n = 2 is prime , if n % 2 == 0 then n 
is not prime.

6> Base numbers should be 0 <= a <= n - 1

7> a ^ (2 ^ ((s - 1) * d )) * a ^ (2 ^ ((s - 2) * d )) *... * (a ^ d + 1)  * (a ^ d - 1) = 0 (mod n)

8> Using Euclid's lemma , a ^ d = 1 (mod n) or a ^ 2 ^ (r * d) = -1 (mod n) for n to be prime.

*/

int modular_multiplication(int a , int b , int n)
{
	int res = 0;
	while(b)
	{
		if(b & (int)1)
			res += a;
		a = 2 * a;
		res %= n;
		a %= n;
		b /= 2;
	}
	return res;
}
int modular_exponentiation(int a , int b , int n)
{
	int res = 1;
	while(b)
	{
		if(b & (int)1)
		{
			res = modular_multiplication(res , a , n);
			res %= n;
		}
		a = modular_multiplication(a , a, n);
		a %= n;
		b /= 2;
	}
	return res;
}
bool miller_rabin(int n)
{
	if(n == 1)
		return false;
	if(n == 2)
		return true;
	if(n % 2 == 0)
		return false;
	int d = n - 1 , s = 0;
	while(d % 2 == 0)
	{
		d = d / 2;
		s++;
	}
	//Now d is odd number 

	vector<int> a{2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23};
	//a represents random numbers

	for(int i = 0 ; i < a.size() ; i++)
	{
		if(a[i] > n - 2)
			continue;
		int ad = modular_exponentiation(a[i] , d , n);
		if(ad % n == 1)
			continue;
		bool prime = false;
		for(int r = 0 ; r <= s - 1 ; r++)
		{
			//(2 ^ r) % n
			int rr = modular_exponentiation(2 , r , n);
			int ard = modular_exponentiation(ad , rr , n);
			
			if(ard % n == n - 1)
			{
				prime = true;
				break;
			}
		}
		if(prime == false)
			return false;
	}
	return true;

}
void solve()
{

	int n;
	cin >> n;
	if(miller_rabin(n))
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";
}

void local()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int32_t main()
{

    fast;
    local();
    int T = 1;
    cin>>T;

    while(T--)
    {
        solve();
    }

    return 0;
}