
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
	Multidimensional dp is easy.
	We just have to figure out unique dp state
	For example , In this particular question (i , j , remaining substrings) is not a unique state
	Continuity assurance is required (That is our fourth dimension , 0 or 1)
*/



int n , m , k;
string s , t;
int dp[1005][1005][12][2];
int solve(int is , int it , int rem , int cont)
{
	//p1 , p2 , p3 , p4 , p5
	//if p3 has a length of 5
	//p3 = abcde
	//Then if we are on 
	if(is == n || it == m)
		return ((rem == 0) ? 0 : INT_MAX);
	
	if(dp[is][it][rem][cont] != -1)
		return dp[is][it][rem][cont];
	
	if(rem == 0)
		return 0;
	int res = INT_MIN;

	if(cont == 1)
	{
		res = max(res , solve(is + 1 , it , rem - 1 , 0));
		res = max(res , solve(is , it + 1 , rem - 1 , 0));
	
	}
	else
	{
		res = max(res , solve(is + 1 , it , rem , 0));
		res = max(res , solve(is , it + 1 , rem , 0));
	}

	if(s[is] == t[it])
	{
		res = max(res , 1 + solve(is + 1 , it + 1 , rem , 1));
		res = max(res , 1 + solve(is + 1 , it + 1 , rem - 1, 0));
	}
	return dp[is][it][rem][cont] = res;
}

void solve()
{
	
	cin >> n >> m >> k;
	cin >> s >> t;
	memset(dp , -1 , sizeof(dp));
	cout << solve(0 , 0 , k , 0);

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