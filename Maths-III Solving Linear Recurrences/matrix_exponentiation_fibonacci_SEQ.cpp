
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

const int mod = 1e9;
const int INF = 1e9;
const int LINF = 1e18;
const int N = 1e4;
const int chkprc = 1e-9;  // Check for precision error in double



int k;
vci b , c;

vcvci multiply(vcvci A , vcvci B)
{
	//Let's store the result in a 2d vector C
	vcvci C(k + 1 , vci (k + 1));
	for(int i = 1 ; i <= k ; i++)
	{
		for(int j = 1 ; j <= k ; j++)
		{
			for(int l = 1 ; l <= k ; l++)
				C[i][j] = (C[i][j] + (A[i][l] * B[l][j]) % mod) % mod;
		}
	}
	return C;
}

vcvci pow(vcvci A , int n)
{
	if(n == 1)
		return A;
	vcvci res(k + 1 , vci (k + 1));
	for(int i = 0 ; i <= k ; i++)
	{
		for(int j = 0 ; j <= k ; j++)
		{
			if(i == j)
				res[i][j] = 1;
			else
				res[i][j] = 0;
		}
	}

	while(n)
	{
		if(n & 1)
			res = multiply(A , res);
		A = multiply(A , A);
		n /= 2;
	}

	return res;
}

int compute(int n)
{
	if(n == 0)
		return 0;
	if(n <= k)
		return b[n - 1];

	//Otherwise we will use matrix exponentiation

	vci F1(k + 1);

	for(int i = 1 ; i <= k ; i++)
		F1[i] = b[i - 1];

	vcvci T(k + 1, vci (k + 1));

	for(int i = 1 ; i <= k ; i++)
	{
		for(int j = 1 ; j <= k ; j++)
		{
			if(i < k)
			{
				if(j == (i + 1))
					T[i][j] = 1;
				else
					T[i][j] = 0;
			}
			else
				T[i][j] = c[k - j];

		}
	}

	T = pow(T , n - 1);

	int res = 0;

	for(int i = 1 ; i <= k ; i++)
		res = (res + (T[1][i] * F1[i]) % mod) % mod;
	return res;
}

void solve()
{

	int  n , num;
	cin >> k;
	for(int i = 0 ; i < k ; i++)
	{
		cin >> num;
		b.pb(num);
	}
	
	for(int i = 0 ; i < k ; i++)
	{
		cin >> num;
		c.pb(num);
	}

	cin >> n;
	cout << compute(n)<<"\n";
	b.clear();
	c.clear();
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
    int T;
    cin>>T;

    while(T--)
    {
        solve();
    }

    return 0;
}