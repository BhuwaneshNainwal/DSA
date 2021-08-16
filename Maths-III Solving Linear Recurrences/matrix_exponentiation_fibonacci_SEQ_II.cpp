
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



int k , n , m , p ;

vci b , c;


vcvci multiply(vcvci A , vcvci B)
{
	//Let's store the result in a 2d vector C
	vcvci C(k + 2 , vci (k + 2));
	for(int i = 1 ; i <= (k + 1) ; i++)
	{
		for(int j = 1 ; j <= (k + 1) ; j++)
		{
			for(int l = 1 ; l <= (k + 1) ; l++)
				C[i][j] = (C[i][j] + (A[i][l] * B[l][j]) % p) % p;
		}
	}
	return C;
}


vcvci pow(vcvci A , int n)
{
	if(n == 1)
		return A;
	vcvci res(k + 2 , vci (k + 2));
	for(int i = 0 ; i <= (k + 1) ; i++)
	{
		for(int j = 0 ; j <= (k + 1) ; j++)
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

int compute(vci sum)
{

	//if it is less than 
	if(n <= k)
		return (sum[n] % p - sum[m - 1] % p + p) % p;

	//Otherwise we will use matrix exponentiation
	int last = 0;
	int first = 0;
	bool check = false;
	if(m <= (k + 1))
	{	
		check = true;
		last = sum[m - 1];
	}

	vci F1(k + 2);

	F1[1] = sum[k];
	for(int i = 2 ; i <= (k + 1) ; i++)
		F1[i] = b[i - 2];

	vcvci T(k + 2, vci (k + 2));

	for(int i = 1 ; i <= (k + 1) ; i++)
	{
		for(int j = 1 ; j <= (k + 1) ; j++)
		{
			if(i == 1)
			{
				if(j == 1)
					T[i][j] = 1;
				else
					T[i][j] = c[k - j + 1];
			}
			else if(i <= k)
			{
				if(j == (i + 1))
					T[i][j] = 1;
				else
					T[i][j] = 0;
			}
			else
			{
				if(j == 1)
					T[i][j] = 0;
				else
					T[i][j] = c[k - j + 1];
			}

		}
	}

	vcvci M(k + 2 , vci(k + 2));
	vcvci N(k + 2 , vci(k + 2));

	if(!check)
		M = pow(T , m - k - 1);

	N = pow(T , n - k);

	for(int i = 1 ; i <= (k + 1) ; i++)
		first = (first + (N[1][i] * F1[i]) % p) % p;
	
	if(!check)
	{
		for(int i = 1 ; i <= (k + 1) ; i++)
			last = (last + (M[1][i] * F1[i]) % p) % p;
	}
	
	return (first % p - last % p + p) % p;
}

void solve()
{
	int num;
	
	cin >> k;
	
	vci sum(k + 1 , 0);
	//Vector b
	sum[0] = 0;

	//Lets store the prefix sum till kth element
	for(int i = 0 ; i < k ; i++)
	{
		cin >> num;
		sum[i + 1] = sum[i] + num; 
		b.pb(num);
	}
	
	//Vector c
	for(int i = 0 ; i < k ; i++)
	{
		cin >> num;
		c.pb(num);
	}

	//p is modulo
	cin >> m >> n >> p;
	
	cout << compute(sum)<<"\n";
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