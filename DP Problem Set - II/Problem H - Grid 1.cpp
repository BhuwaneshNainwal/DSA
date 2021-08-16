
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
const int N = 1000 + 10;
const int chkprc = 1e-9;  // Check for precision error in double

int mat[N][N];
int n , m;
int ways()
{	
	int dp[n][m];
	memset(dp , 0 , sizeof(dp));
	dp[0][0] = 1;
	for(int i = 1 ; i < n; i++)
	{
		if(mat[i][0] == 1)
			dp[i][0] = dp[i - 1][0];
		else
			dp[i][0] = 0;
	}

	for(int j = 1 ; j < m ; j++)
	{
		if(mat[0][j] == 1)
			dp[0][j] = dp[0][j - 1];
		else
			dp[0][j] = 0;
	}

	for(int i = 1 ; i < n ; i++)
	{
		for(int j = 1 ; j < m ; j++)
		{
			if(mat[i][j] == 0)
			{
				dp[i][j] = 0;
				continue;
			}

			dp[i][j] = (dp[i - 1][j] % mod + dp[i][j - 1] % mod) % mod;
		}
	
	}


	// for(int i = 0 ; i < n ; i++)
	// {
	// 	for(int j = 0 ; j < m ; j++)
	// 		cout << dp[i][j] << " ";
	// 	cout << '\n';
	// }


	return dp[n - 1][m - 1];

}

void solve()
{
	
	cin >> n >> m;

	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < m ; j++)
		{
			char c;
			cin >> c;
				
			if(c == '.')
				mat[i][j] = 1;
			else
				mat[i][j] = 0;
		}
	}
	
	cout << ways();


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
    // cin>>T;

    while(T--)
    {
        solve();
    }

    return 0;
}