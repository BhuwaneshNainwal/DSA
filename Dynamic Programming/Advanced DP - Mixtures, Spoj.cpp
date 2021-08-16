
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


/*

	Variation of matrix chain multiplication

*/

int dp[102][102];
int a[1000] = {0};

int sum(int i , int j)
{
	int ans = 0;
	for(int k = i ; k <= j ; k++)
	{
		ans += a[k];
		ans %= 100;
	}
	
	return ans ;
}

int solve_mixtures(int i , int j)
{
	if(i >= j)
		return 0;

	//If the answer is already there
	if(dp[i][j] != -1)
		return dp[i][j];

	dp[i][j] = LLONG_MAX;
	for(int k = i ; k < j ; k++)
	{
		dp[i][j] = min(dp[i][j] , (solve_mixtures(i , k) + solve_mixtures(k + 1 , j) + (sum(i , k) * sum(k + 1 , j))));
	}	
	return dp[i][j];
}


void solve(int n)
{

	for(int i = 0 ; i < n ; i++)
		cin >> a[i];


	memset(dp , -1 , sizeof(dp));

	cout << solve_mixtures(0 , n - 1) << "\n";

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

    while(cin >> T)
    {
        solve(T);
    }

    return 0;
}